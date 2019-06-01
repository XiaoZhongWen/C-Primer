//
//  HasPtrV_2.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/21.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "HasPtrV_2.hpp"

HasPtrV_2& HasPtrV_2::operator=(const HasPtrV_2 &hp) {
    ++(*hp.use);
    --*(use);
    if (*use == 0) {
        delete ps;
        delete use;
    }
    i = hp.i;
    ps = hp.ps;
    use = hp.use;
    return *this;
}

HasPtrV_2::~HasPtrV_2() {
    (*use)--;
    if (*use == 0) {
        delete ps;
        delete use;
    }
}
