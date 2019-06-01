//
//  HasPtr.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/21.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "HasPtr.hpp"

Hasptr::Hasptr(const Hasptr &hp): i(hp.i), ps(new std::string(*hp.ps)) {}

Hasptr::Hasptr(const std::string &s): ps(new std::string(s)), i(0) {}

Hasptr& Hasptr::operator=(const Hasptr &hp) {
    std::string *p = new std::string(*hp.ps);
    delete ps;
    i = hp.i;
    ps = p;
    return *this;
}

Hasptr::~Hasptr() {
    delete ps;
}
