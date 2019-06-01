//
//  TextQuery.hpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/19.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef TextQuery_hpp
#define TextQuery_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>

class QueryResult;
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &ifs);
    QueryResult query(const std::string &s) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif /* TextQuery_hpp */
