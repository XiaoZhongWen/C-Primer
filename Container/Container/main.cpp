//
//  main.cpp
//  Container
//
//  Created by 肖仲文 on 2019/5/2.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <queue>
#include <stack>

using namespace std;

bool exercise_9_4(vector<int>::iterator &begin, vector<int>::iterator &end, int target) {
    bool result = false;
    while (begin != end) {
        if (*begin == target) {
            result = true;
            break;
        }
        begin++;
    }
    return result;
}

vector<int>::iterator exercise_9_5(vector<int>::iterator &begin, vector<int>::iterator &end, int target) {
    vector<int>::iterator it;
    while (begin != end) {
        if (*begin == target) {
            it = begin;
            break;
        }
        begin++;
    }
    return it;
}

void exercise_9_11() {
    // 1
    vector<int> v1(10, 1);
    // 2
    vector<int> v2 = {0, 1, 2};
    // 3
    vector<int> v3 = v1;
    // 4
    vector<int> v4(v1);
    // 5
    vector<int> v5(10);
    // 6
    vector<int> v6{0, 1, 2};
    // 7
    vector<int> v7(v1.begin(), v1.end());
    cout << "v1: ";
    vector<int>::iterator v1_begin = v1.begin();
    vector<int>::iterator v1_end = v1.end();
    while (v1_begin != v1_end) {
        cout <<  *v1_begin << "\t";
        v1_begin++;
    }
    cout << endl;
    
    cout << "v2: ";
    vector<int>::iterator v2_begin = v2.begin();
    vector<int>::iterator v2_end = v2.end();
    while (v2_begin != v2_end) {
        cout <<  *v2_begin << "\t";
        v2_begin++;
    }
    cout << endl;

    cout << "v3: ";
    vector<int>::iterator v3_begin = v3.begin();
    vector<int>::iterator v3_end = v3.end();
    while (v3_begin != v3_end) {
        cout <<  *v3_begin << "\t";
        v3_begin++;
    }
    cout << endl;

    cout << "v4: ";
    vector<int>::iterator v4_begin = v4.begin();
    vector<int>::iterator v4_end = v4.end();
    while (v4_begin != v4_end) {
        cout <<  *v4_begin << "\t";
        v4_begin++;
    }
    cout << endl;

    cout << "v5: ";
    vector<int>::iterator v5_begin = v4.begin();
    vector<int>::iterator v5_end = v4.end();
    while (v5_begin != v5_end) {
        cout <<  *v5_begin << "\t";
        v5_begin++;
    }
    cout << endl;

    cout << "v6: ";
    vector<int>::iterator v6_begin = v6.begin();
    vector<int>::iterator v6_end = v6.end();
    while (v6_begin != v6_end) {
        cout <<  *v6_begin << "\t";
        v6_begin++;
    }
    cout << endl;

    cout << "v7: ";
    vector<int>::iterator v7_begin = v7.begin();
    vector<int>::iterator v7_end = v7.end();
    while (v7_begin != v7_end) {
        cout <<  *v7_begin << "\t";
        v7_begin++;
    }
    cout << endl;
}

void exercise_9_13() {
    list<int> l = {1,2,3,4,5,6,7,8,9};
//    vector<double> v = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    vector<double> v(l.begin(), l.end());
}

void exercise_9_14() {
    list<const char *> l = {"Java", "Objective-C", "C++"};
    vector<string> v;
    v.assign(l.begin(), l.end());
    
    vector<string>::iterator begin = v.begin();
    vector<string>::iterator end = v.end();
    while (begin != end) {
        cout << *begin << endl;
        begin++;
    }
}

bool exercise_9_15(const vector<int> &v1, const vector<int> &v2) {
    return v1 == v2;
}

bool exercise_9_16(const list<int> &l, const vector<int> &v) {
    list<int>::size_type l_size = l.size();
    vector<int>::size_type v_size = v.size();
    bool result = true;
    if (l_size != v_size) {
        result = false;
    } else {
        list<int>::const_iterator l_it = l.begin();
        vector<int>::const_iterator v_it = v.begin();
        for (; l_it != l.end() && v_it != v.end(); l_it++, v_it++) {
            if (*l_it != *v_it) {
                result = false;
                break;
            }
        }
    }
    return result;
}

void exercise_9_18() {
    deque<string> dq;
    string word;
    while (cin >> word && word != "eof") {
        dq.push_back(word);
    }
    
    for (deque<string>::iterator it = dq.begin(); it != dq.end(); it++) {
        cout << *it << endl;
    }
}

void exercise_9_19() {
    list<string> l;
    string word;
    while (cin >> word && word != "eof") {
        l.push_back(word);
    }
    
    for (list<string>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << endl;
    }
}

void exercise_9_20() {
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd;
    deque<int> even;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        if (*it % 2) {
            odd.push_back(*it);
        } else {
            even.push_back(*it);
        }
    }
    
    for (deque<int>::iterator it = odd.begin(); it != odd.end(); it++) {
        cout << *it << endl;
    }
    
    for (deque<int>::iterator it = even.begin(); it != even.end(); it++) {
        cout << *it << endl;
    }
}

void exercise_9_24() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    cout << v.at(0) << endl;
    cout << v[0] << endl;
    cout << v.front() << endl;
    cout << *v.begin() << endl;
}

void exercise_9_25() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    vector<int>::iterator it1 = v.end();
    vector<int>::iterator it2 = v.end();
    v.erase(it1, it2);
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}

void exercise_9_26() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v;
    list<int> l;
    int count = sizeof(ia) / sizeof(int);
    for (int i= 0; i < count; i++) {
        v.push_back(ia[i]);
        l.push_back(ia[i]);
    }
    
    vector<int>::iterator it_v = v.begin();
    while (it_v != v.end()) {
        if (*it_v % 2 == 0) {
            it_v = v.erase(it_v);
        } else {
            it_v++;
        }
    }
    
    it_v = v.begin();
    while (it_v != v.end()) {
        cout << *it_v << "\t";
        it_v++;
    }

    cout << endl;
    
    list<int>::iterator it_l = l.begin();
    while (it_l != l.end()) {
        if (*it_l % 2) {
            it_l = l.erase(it_l);
        } else {
            it_l++;
        }
    }
    
    it_l = l.begin();
    while (it_l != l.end()) {
        cout << *it_l << "\t";
        it_l++;
    }
}

void exercise_9_27() {
    forward_list<int> list = {1,2,3,4,5,6,7,8,9};
    forward_list<int>::iterator prev = list.before_begin();
    forward_list<int>::iterator curr = list.begin();
    while (curr != list.end()) {
        if (*curr % 2) {
            curr = list.erase_after(prev);
        } else {
            prev = curr;
            curr++;
        }
    }
    
    forward_list<int>::iterator it = list.begin();
    while (it != list.end()) {
        cout << *it << "\t";
        it++;
    }
    cout << endl;
}

void exercise_9_28(forward_list<string> &list, const string str1, const string str2) {
    forward_list<string>::iterator prev = list.before_begin();
    forward_list<string>::iterator curr = list.begin();
    while (curr != list.end()) {
        if (*curr == str1) {
            list.insert_after(curr, str2);
            break;
        } else {
            prev = curr;
            curr++;
        }
    }
    if (curr == list.end()) {
        list.insert_after(prev, str2);
    }
}

void exercise_9_31() {
    list<int> l = {1,2,3,4,5,6,7,8,9};
    auto iter = l.begin();
    while (iter != l.end()) {
        if (*iter % 2) {
            iter = l.insert(iter, *iter);
            iter++;
            iter++;
        } else {
            iter = l.erase(iter);
        }
    }
    
    iter = l.begin();
    while (iter != l.end()) {
        cout << *iter << "\t";
        iter++;
    }
    cout << endl;
}

void exercise_9_41() {
    vector<char> v = {'x', 'i', 'a', 'o'};
    string str(v.begin(), v.end());
    cout << str << endl;
}

void exercise_9_43(string &s, const string &oldVal, const string &newVal) {
    auto iter = s.begin();
    while (iter != s.end()) {
        auto it1 = iter;
        auto it2 = oldVal.begin();
        while (*it1 == *it2) {
            it1++;
            it2++;
        }
        if (it2 == oldVal.end()) {
            iter = s.erase(iter, it1);
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size();
        } else {
            iter++;
        }
    }
}

void exercise_9_44(string &s, const string &oldVal, const string &newVal) {
    auto iter = s.begin();
    while (iter != s.end()) {
        auto it1 = iter;
        auto it2 = oldVal.begin();
        while (*it1 == *it2) {
            it1++;
            it2++;
        }
        if (it2 == oldVal.end()) {
            s.replace(iter, it1, newVal);
            iter += newVal.size();
        } else {
            iter++;
        }
    }
}

string exercise_9_45(string name, const string &prefix, const string &suffix) {
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(suffix);
    return name;
}

string exercise_9_46(string name, const string &prefix, const string &suffix) {
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.insert(name.end(), suffix.begin(), suffix.end());
    return name;
}

void exercise_9_47() {
    string str = "ab2c3d7R4E6";
    string numbers = "0123456789";
    string::size_type pos = 0;
    while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos << " element is " << str[pos] << endl;
        pos++;
    }
    
    pos = 0;
    while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos << " element is " << str[pos] << endl;
        pos++;
    }
}

void exercise_9_50() {
    vector<string> v = {"123", "456", "789"};
    int sum = 0;
    auto iter = v.begin();
    while (iter != v.end()) {
        sum += stoi(*iter);
        iter++;
    }
    cout << sum << endl;
}

int main(int argc, const char * argv[]) {
    
//    vector<int> v = {1,2,3,4,5,6,7,8,9};
    
//    vector<int>::iterator begin = v.begin();
//    vector<int>::iterator end = v.end();
//    bool result = exercise_9_4(begin, end, 8);
//    cout << result << endl;
    
//    vector<int>::iterator it = exercise_9_5(begin, end, 30);
//    cout << *it << endl;
    
//    exercise_9_11();
    
//    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    vector<int> v2 = {-1, -2, -3};
////    vector<int>::iterator begin = v2.begin();
////    vector<int>::iterator end = v2.end();
////    v2 = v1;
//    swap(v1, v2);
//    vector<int>::iterator begin = v2.begin();
//    vector<int>::iterator end = v2.end();
//    while (begin != end) {
//        cout << *begin << endl;
//        begin++;
//    }
    
//    exercise_9_14();
    
//    vector<int> v1 = {1, 1, 2, 3, 4, 5, 6, 7, 8};
//    vector<int> v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    cout << exercise_9_15(v1, v2) << endl;
    
//    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    cout << exercise_9_16(l, v) << endl;
    
//    exercise_9_19();
    
//    exercise_9_20();
    
//    exercise_9_24();
    
//    exercise_9_25();
    
//    exercise_9_26();
    
//    exercise_9_27();
    
//    forward_list<string> list = {"C++", "Objective-C", "Java"};
//    string str1 = "Java";
//    string str2 = "Swift";
//    exercise_9_28(list, str1, str2);
//
//    forward_list<string>::iterator it = list.begin();
//    while (it != list.end()) {
//        cout << *it << endl;
//        it++;
//    }
    
//    exercise_9_31();
    
//    exercise_9_41();
    
//    string s = "hakDHJthoahdkashkthouhthojhdaskh";
//    exercise_9_44(s, "tho", "though");
//    cout << s << endl;
    
//    string str = exercise_9_46("xiao", "Mr.", "Jr.");
//    cout << str << endl;
    
//    exercise_9_47();
    
    exercise_9_50();
    
    return 0;
}
