//
//  QueryResult.cpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/19.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "QueryResult.hpp"
#include <iostream>

using namespace std;

QueryResult::QueryResult(string s, shared_ptr<vector<string>> file, shared_ptr<set<line_no>> lineNums): s(s), file(file), lineNums(lineNums) {}

ostream& print(ostream &os, const QueryResult qr) {
    os << qr.s << " occurs " << qr.lineNums->size() << " times" << endl;
    for (auto num : *qr.lineNums) {
        os << "\t(line) " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}
