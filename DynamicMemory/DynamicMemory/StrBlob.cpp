//
//  StrBlob.cpp
//  DynamicMemory
//
//  Created by 肖仲文 on 2019/5/14.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "StrBlob.hpp"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::push_back(const std::string &t) const {
    data->push_back(t);
}

void StrBlob::pop_back() const {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i > data->size()) {
//        throw out_of_range(msg);
    }
}
