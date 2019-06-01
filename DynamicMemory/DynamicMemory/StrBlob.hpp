//
//  StrBlob.hpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/14.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef StrBlob_hpp
#define StrBlob_hpp

#include <stdio.h>
#include <memory>
#include <vector>
#include <string>
#include <list>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) const ;
    void pop_back() const ;
    std::string& front() const;
    std::string& back() const;
    
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

#endif /* StrBlob_hpp */
