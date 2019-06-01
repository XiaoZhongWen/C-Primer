//
//  QueryResult.hpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/19.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef QueryResult_hpp
#define QueryResult_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include <string>

class QueryResult {
    friend std::ostream& print(std::ostream &os, const QueryResult qr);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> file, std::shared_ptr<std::set<line_no>> lines);
private:
    std::string s;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<line_no>> lineNums;
};

#endif /* QueryResult_hpp */
