//
//  main.cpp
//  IO
//
//  Created by 肖仲文 on 2019/5/1.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

istream& readData(istream &is) {
    auto old_state = is.rdstate();
    
    char ch;
    while (!cin.eof()) {
        cin >> ch;
        cout << ch << endl;
    }
    
    is.setstate(old_state);
    return is;
}

void readFile() {
    vector<string> vec;
    string path = "/Users/julien/Desktop/test.txt";
    ifstream ifs;
    ifs.open(path);
    if (ifs) {
        string str;
        while (!ifs.eof()) {
            getline(ifs, str);
            vec.push_back(str);
        }
        ifs.close();
    }
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
}

void fetchWords() {
    vector<string> vec;
    string path = "/Users/julien/Desktop/test.txt";
    ifstream ifs;
    ifs.open(path);
    if (ifs) {
        string str;
        while (!ifs.eof()) {
            char ch;
            ifs.get(ch);
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z')) {
                str.append(string(1, ch));
            } else {
                if (str.length()) {
                    vec.push_back(str);
                    str.clear();
                }
            }
        }
        ifs.close();
    }
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
}

int main(int argc, const char * argv[]) {
    
//    readData(cin);
//    readFile();
//    fetchWords();
    
//    string str = "C++ Jave Objective-C Swift Shell Python Javascript CSS HTML5";
//    istringstream ist(str);
//    string word;
//    while (ist >> word) {
//        cout << word << endl;
//    }
    
    vector<string> vec;
    vec.push_back("C++ Jave");
    vec.push_back("Objective-C Swift");
    vec.push_back("Shell Python");
    vec.push_back("Javascript CSS");
    vec.push_back("HTML5");
    vec.push_back("Ruby");
    
    istringstream ist;
//    auto old_state = ist.rdstate();
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
//        ist.str(*it);
        
        istringstream ist(*it);
        string str;
        while (ist >> str) {
            cout << str << endl;
        }
        
//        ist.setstate(old_state);
    }
    
    return 0;
}
