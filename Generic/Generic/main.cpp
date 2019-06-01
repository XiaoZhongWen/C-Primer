//
//  main.cpp
//  Generic
//
//  Created by 肖仲文 on 2019/5/5.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

class Sales_date {
public:
    Sales_date(const string &_isbn, const double _price) : isbn(_isbn), price(_price) {}
    const string& getIsbn() const {
        return isbn;
    }
private:
    string isbn;
    double price;
};

void exercise_10_3() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    int sum = accumulate(v.cbegin(), v.cend(), 0);
    cout << sum << endl;
}

void exercise_10_6() {
    vector<int> v;
    auto iter = back_inserter(v);
    fill_n(iter, 10, 0);
    
    auto it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }
}

void exercise_10_7() {
    list<int> lst = {1,2,3,4,5,6};
    vector<int> v;
//    v.reserve(lst.size());
    auto iter = back_inserter(v);
    copy(lst.cbegin(), lst.cend(), iter);
    
    auto it = v.begin();
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void exercise_10_11() {
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(vec.begin(), vec.end());
    auto iter = unique(vec.begin(), vec.end());
    vec.erase(iter, vec.end());
    
    stable_sort(vec.begin(), vec.end(), isShorter);
    for (const auto &s : vec) {
        cout << s << "\t";
    }
    cout << endl;
}

bool compareIsbn(const Sales_date &s1, const Sales_date &s2) {
    return s1.getIsbn() < s2.getIsbn();
}

void exercise_10_12() {
    vector<Sales_date> vec;
    Sales_date s1("abcd", 10.0);
    Sales_date s2("efgh", 11.0);
    Sales_date s3("ijkl", 12.0);
    Sales_date s4("mnop", 13.0);
    Sales_date s5("qrst", 14.0);
    Sales_date s6("uvwx", 15.0);
    Sales_date s7("yzab", 16.0);
    Sales_date s8("cdef", 17.0);
    Sales_date s9("ghij", 18.0);
    Sales_date s10("klmn", 19.0);
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    vec.push_back(s4);
    vec.push_back(s5);
    vec.push_back(s6);
    vec.push_back(s7);
    vec.push_back(s8);
    vec.push_back(s9);
    vec.push_back(s10);
    sort(vec.begin(), vec.end(), compareIsbn);
    
    for (auto &s : vec) {
        cout << s.getIsbn() << "\t";
    }
    cout << endl;
}

bool compare(const string s) {
    return s.size() >= 5;
}

void exercise_10_13() {
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto iter = partition(vec.begin(), vec.end(), compare);
    auto it = vec.begin();
    while (it != iter) {
        cout << *it << "\t";
        it++;
    }
    cout << endl;
}

void exercise_10_14() {
    auto f = [](int a, int b) -> int {
        return a + b;
    };
    cout << f(1, 2) << endl;
}

void exercise_10_15() {
    int a = 6;
    auto f = [a](int x) -> int {
        return a + x;
    };
    cout << f(4) << endl;
}

void exercise_10_17() {
    vector<Sales_date> vec;
    Sales_date s1("abcd", 10.0);
    Sales_date s2("efgh", 11.0);
    Sales_date s3("ijkl", 12.0);
    Sales_date s4("mnop", 13.0);
    Sales_date s5("qrst", 14.0);
    Sales_date s6("uvwx", 15.0);
    Sales_date s7("yzab", 16.0);
    Sales_date s8("cdef", 17.0);
    Sales_date s9("ghij", 18.0);
    Sales_date s10("klmn", 19.0);
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    vec.push_back(s4);
    vec.push_back(s5);
    vec.push_back(s6);
    vec.push_back(s7);
    vec.push_back(s8);
    vec.push_back(s9);
    vec.push_back(s10);
//    sort(vec.begin(), vec.end(), compareIsbn);
    sort(vec.begin(), vec.end(), [](const Sales_date &s1, const Sales_date &s2) -> bool {
        return s1.getIsbn() < s2.getIsbn();
    });
    
    for (auto &s : vec) {
        cout << s.getIsbn() << "\t";
    }
    cout << endl;
}

void exercise_10_20() {
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto result = count_if(vec.begin(), vec.end(), [](const string &s){
        return s.length() > 6;
    });
    cout << result << endl;
}

void exercise_10_21() {
    int a = 10;
    auto f = [&a]() -> bool {
        if (a > 0) {
            a--;
            return false;
        } else {
            return true;
        }
    };
    
    while (!f()) {
        cout << a << "\t";
    }
    cout << "\n" << a << endl;
}

bool checkSum(const string &s, int sz) {
    return s.length() <= sz;
}

void exercise_10_22() {
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto check = bind(checkSum, std::placeholders::_1, 6);
    count_if(vec.begin(), vec.end(), check);
}

void exercise_10_27() {
    vector<int> v = {1,2,3,6,6,6,8,8,9};
    list<int> lst;
    unique_copy(v.begin(), v.end(), inserter(lst, lst.begin()));
    for (int x : lst) {
        cout << x << "\t";
    }
}

void exercise_10_28() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    vector<int> v1, v2;
    list<int> list;
    
    // inserter
    copy(v.begin(), v.end(), inserter(v1, v1.begin()));

    // back_inserter
    copy(v.begin(), v.end(), back_inserter(v2));

    // front_inserter
    copy(v.begin(), v.end(), front_inserter(list));

    for (int x : v1) {
        cout << x << "\t";
    }
    cout << endl;

    for (int x : v2) {
        cout << x << "\t";
    }
    cout << endl;

    for (int x : list) {
        cout << x << "\t";
    }
    cout << endl;
}

void exercise_10_29() {
    ifstream in("/Users/julien/Desktop/test.txt");
    istream_iterator<string> str_it(in);
    istream_iterator<string> eof;
    vector<string> v;
    while (str_it != eof) {
        v.push_back(*str_it);
        str_it++;
    }
    
    for (string str : v) {
        cout << str << endl;
    }
}

void exercise_10_30() {
    istream_iterator<int> ist(cin), eof;
    vector<int> vec;
    unique_copy(ist, eof, back_inserter(vec));
    sort(vec.begin(), vec.end(), [](int a, int b){
        return a < b;
    });
    for (int x : vec) {
        cout << x << "\t";
    }
    cout << endl;
}

void exercise_10_33(const string &inputFileName, const string &outputFileName1, const string &outputFileName2) {
    ifstream ifs(inputFileName);
    istream_iterator<int> ist(ifs), eof;
    
    ofstream ofs1(outputFileName1);
    ostream_iterator<int> osi1(ofs1, " ");
    copy_if(ist, eof, osi1, [](int x){
        return x % 2;
    });
    ofs1.close();
    ifs.close();
    
    istream_iterator<int> ist1(ifs);
    ofstream ofs2(outputFileName2);
    ostream_iterator<int> osi2(ofs2, "\n");
    copy_if(ist1, eof, osi2, [](int x) -> bool {
        cout << x << endl;
        return !(x % 2);
    });
    ofs2.close();
    ifs.close();
}

void exercise_10_34() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    auto it = v.crbegin();
    while (it != v.crend()) {
        cout << *it << "\t";
        it++;
    }
}

void exercise_10_35() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    auto it = v.end();
    auto it1 = v.begin();
    it--;
    it1--;
    while (it != it1) {
        cout << *it << "\t";
        it--;
    }
}

void exercise_10_36() {
    vector<int> v = {1,0,2,3,4,0,5,6,0,7,8,9};
    auto it = find(v.crbegin(), v.crend(), 0);
    auto b = it.base();
    while (b != v.end()) {
        cout << *b << "\t";
        b++;
    }
}

void exercise_10_37() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    auto begin = v.crbegin() + 3;
    auto end = v.crend() - 2;
    list<int> lst;
    copy(begin, end, back_inserter(lst));
    auto it = lst.begin();
    while (it != lst.end()) {
        cout << *it << "\t";
        it++;
    }
}

int main(int argc, const char * argv[]) {
    
//    exercise_10_3();
    
//    exercise_10_6();
    
//    exercise_10_7();
    
//    vector<int> vec;
//    auto iter = back_inserter(vec);
//    fill_n(iter, 10, 0);
//
//    auto it = vec.begin();
//    while (it != vec.end()) {
//        cout << *it << endl;
//        it++;
//    }
//
//    vector<const char *> roster1 = {"c++", "Jave"};
//    list<const char *> roster2 = {"c++", "jave"};
//    bool result = equal(roster1.cbegin(), roster1.cend(), roster2.begin());
//    cout << result << endl;
    
//    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
//    sort(vec.begin(), vec.end());
//
//    auto it = vec.begin();
//    while (it != vec.end()) {
//        cout << *it << "\t";
//        it++;
//    }
//    cout << endl;
//
//    auto iter = unique(vec.begin(), vec.end());
//    vec.erase(iter, vec.end());
//    it = vec.begin();
//    while (it != vec.end()) {
//        cout << *it << "\t";
//        it++;
//    }
    
//    exercise_10_11();
    
//    exercise_10_12();
    
//    exercise_10_13();
    
//    exercise_10_14();
    
//    exercise_10_15();
    
//    exercise_10_17();
    
//    exercise_10_21();
    
//    exercise_10_22();
    
//    exercise_10_27();
    
//    exercise_10_28();
    
//    exercise_10_29();
    
//    exercise_10_30();
    
//    exercise_10_33("/Users/julien/Desktop/test1.txt", "/Users/julien/Desktop/test2.txt", "/Users/julien/Desktop/test3.txt");
    
//    exercise_10_34();
    
//    exercise_10_35();
    
//    exercise_10_36();
    
    exercise_10_37();
    
    return 0;
}
