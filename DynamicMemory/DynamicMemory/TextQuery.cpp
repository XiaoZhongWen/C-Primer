//
//  TextQuery.cpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/19.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "TextQuery.hpp"
#include <sstream>
#include "QueryResult.hpp"

using namespace std;

TextQuery::TextQuery(ifstream &ifs): file(new vector<string>) {
    string line;
    while (ifs >> line) {
        file->push_back(line);
        line_no n = file->size() - 1;
        istringstream ist(line);
        string word;
        while (ist >> word) {
            auto &lineNums = wm[word];
            if (!lineNums) {
                lineNums.reset(new set<line_no>);
            }
            lineNums->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &s) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end()) {
        return QueryResult(s, file, nodata);
    } else {
        return QueryResult(s, file, loc->second);
    }
}
