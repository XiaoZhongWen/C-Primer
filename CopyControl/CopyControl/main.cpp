//
//  main.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/20.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include "numbered.hpp"
#include "String.hpp"
#include "Foo.hpp"

using namespace std;

void f(numbered s) {
    cout << s.mysn << endl;
}

void test(const string *) {
    
}

void test1(const string &) {
    
}

int main(int argc, const char * argv[]) {
    
//    set<string *> s;
//    string * const str = new string("");
//    s.insert(str);
//    test(str);
    
//    const string str1;
//    test1(str1);
//    string str2;
//    test1(str2);
    
//    numbered a;
//    numbered b = a;
//    numbered c = b;
//    f(a);
//    f(b);
//    f(c);
    
//    vector<String> v;
//    v.reserve(10);
    
//    String s1("xiao");
//    String s2("zhong");
//    String s3("wen");
//    String s4("C++");
//    String s5("Objective-C");
//    String s6("JavaScript");
//    String s7("Swift");
//    String s8("Java");
//    String s9("Python");
//    String s10("Shell");
    
//    v.push_back("xiao");
//    v.push_back("zhong");
//    v.push_back("wen");
//    v.push_back("C++");
//    v.push_back("Objective-C");
//    v.push_back("JavaScript");
//    v.push_back("Swift");
//    v.push_back("Java");
//    v.push_back("Python");
//    v.push_back("Shell");
    
//    v.push_back(s1);
//    v.push_back(s2);
//    v.push_back(s3);
//    v.push_back(s4);
//    v.push_back(s5);
//    v.push_back(s6);
//    v.push_back(s7);
//    v.push_back(s8);
//    v.push_back(s9);
//    v.push_back(s10);
    
//    v.push_back("xiao");
//    v.push_back("zhongc++");
//    v.push_back("wen");
    
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << "traverse";
//    std::cout << std::endl;
//    std::cout << std::endl;
    
//    for (String s : v) {
//        s.print();
//        printf("\n");
//    }
    
    Foo f;
    f.sorted();
    
    return 0;
}
