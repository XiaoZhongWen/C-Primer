//
//  main.cpp
//  overload
//
//  Created by 肖仲文 on 2019/5/26.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include "Sales_data.hpp"
#include "String.hpp"
#include "StringLengthChecker.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
//    Sales_data item;
//    cout << item << endl;
    
//    String s("xiaozhongwen");
//    cout << s << endl;
    
    vector<string> v;
    const char *path = "/Users/julien/Desktop/input";
    ifstream is(path);
    if (is) {
        string line;
        while (getline(is, line)) {
            istringstream iss(line);
            if (iss) {
                string word;
                while (iss >> word) {
                    v.push_back(word);
                }
            }
        }
        is.close();
    }
    
    for (std::size_t i = 1; i != 11; i++) {
        StringLengthChecker checker(i);
        size_t count = 0;
        for (string s : v) {
            if (checker(s)) {
                count++;
            }
        }
        cout << "the number of word which length is equal " << i << " is " << count << endl;
    }
    
    return 0;
}
