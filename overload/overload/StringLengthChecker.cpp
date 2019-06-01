//
//  StringLengthChecker.cpp
//  overload
//
//  Created by 肖仲文 on 2019/5/26.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "StringLengthChecker.hpp"

bool StringLengthChecker::operator()(const std::string &s) const {
    return s.size() == n;
}
