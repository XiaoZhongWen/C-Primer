//
//  main.cpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/13.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "StrBlob.hpp"
#include "TextQuery.hpp"
#include "QueryResult.hpp"

using namespace std;

void process(shared_ptr<int> p) {
    cout << p.use_count() << endl;
}

void exercise_12_23_1() {
    char *str1 = "C++";
    char *str2 = " Primer";
    size_t len = strlen(str1) + strlen(str2) + 1;
    char *str = (char *)calloc(len, sizeof(char));
    int index = 0;
    int p = 0;
    int q = 0;
    while (str1[p] != '\0') {
        str[index] = str1[p];
        index++;
        p++;
    }
    while (str2[q] != '\0') {
        str[index] = str2[q];
        index++;
        q++;
    }
    str[index] = '\0';
    printf("%s\n", str);
    delete [] str;
}

void exercise_12_23_2() {
    string str1("C++");
    string str2(" Primer");
    char *str = new char[str1.length() + str2.length() + 1];
    istringstream ist1(str1);
    istringstream ist2(str2);
    
    char ch;
    size_t index = 0;
    while (ist1 >> ch) {
        str[index] = ch;
        index++;
    }
    while (ist2 >> ch) {
        str[index] = ch;
        index++;
    }
    str[index] = '\0';
    printf("%s\n", str);
    delete [] str;
}

void exercise_12_24() {
    string str;
    cin >> str;
    char *s = new char[str.length() + 1]();
    istringstream ist(str);
    char ch;
    size_t index = 0;
    while (ist >> ch) {
        s[index] = ch;
        index++;
    }
    s[index] = '\0';
    printf("%s\n", s);
    delete [] s;
}

void exercise_12_25() {
    size_t n = 10;
    allocator<string> alloc;
    auto p = alloc.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q != p + n) {
        alloc.construct(q, s);
        q++;
    }
    q = p;
    while (q != p + n) {
        cout << *q << endl;
        q++;
    }
    
    q = p;
    while (q != p + n) {
        alloc.destroy(q);
        q++;
    }
    
    alloc.deallocate(p, n);
}

void runQueries(ifstream &ifs) {
    TextQuery tq(ifs);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, const char * argv[]) {
    
//    StrBlob b1;
//    {
//        StrBlob b2 = {"a", "an", "the"};
//        b1 = b2;
//        b2.push_back("about");
//        cout << b1.size() << " " << b2.size() << endl;
//    }
    
//    shared_ptr<int> p(new int(42));
//    cout << p.use_count() << endl;
//    process(shared_ptr<int>(p));
//    cout << p.use_count() << endl;
    
//    unique_ptr<int> p(new int(5));
//    unique_ptr<int> q(new int(10));
//    p = q;
//    unique_ptr<int> k(p);
    
//    exercise_12_23_1();
//    exercise_12_23_2();
//    exercise_12_24();
    exercise_12_25();
    
    return 0;
}
