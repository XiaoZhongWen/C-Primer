//
//  main.cpp
//  Association_Container
//
//  Created by 肖仲文 on 2019/5/11.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> m;
    if (map_file) {
        string line;
        while (getline(map_file, line)) {
            string key;
            string value;
            istringstream stream(line);
            stream >> key;
            string str;
            while (stream >> str) {
                value.append(str);
            }
            m.insert({key, value});
        }
    }
    
    return m;
}

const string& transform(const string &s, const map<string, string> &m) {
    auto iter = m.find(s);
    if (iter != m.cend()) {
        return iter->second;
    } else {
        return s;
    }
}

void word_transform(ifstream &map_file, ifstream &input) {
    map<string, string> m = buildMap(map_file);
    if (input) {
        string line;
        while (getline(input, line)) {
            istringstream stream(line);
            string word;
            bool firstword = true;
            while (stream >> word) {
                if (firstword) {
                    firstword = false;
                } else {
                    cout << " ";
                }
                cout << transform(word, m);
            }
            cout << endl;
        }
    }
}

void exercise11_3() {
    ifstream ifs("/Users/julien/Desktop/words.txt");
    string str;
    map<string, size_t> word_count;
    if (ifs) {
        while (!ifs.eof()) {
            char ch = ifs.get();
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z')) {
                ch = tolower(ch);
                str.append(string(1, ch));
            } else {
                if (str.length()) {
                    word_count[str]++;
                    str.clear();
                }
            }
        }
    }
    for (auto pair : word_count) {
        cout << pair.first << ": " << pair.second << endl;
    }
    ifs.close();
}

int main(int argc, const char * argv[]) {
    
//    multiset<string> c;
//    vector<string> v;
//    copy(v.begin(), v.end(), inserter(c, c.end()));
////    copy(v.begin(), v.end(), back_inserter(c));
//    copy(c.begin(), c.end(), inserter(v, v.end()));
//    copy(c.begin(), c.end(), back_inserter(v));
//
//    map<string, vector<int>> m;
//    map<string, vector<int>>::iterator it = m.find("1");
//
//    exercise11_3();
//
    
    ifstream map("/Users/julien/Desktop/map");
    ifstream input("/Users/julien/Desktop/input");
    word_transform(map, input);
    map.close();
    input.close();
    
    return 0;
}
