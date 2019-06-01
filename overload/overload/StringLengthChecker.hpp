//
//  StringLengthChecker.hpp
//  overload
//
//  Created by 肖仲文 on 2019/5/26.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef StringLengthChecker_hpp
#define StringLengthChecker_hpp

#include <stdio.h>
#include <string>

class StringLengthChecker {
public:
    StringLengthChecker(size_t n): n(n) {}
    bool operator()(const std::string &) const;
private:
    std::size_t n;
};

#endif /* StringLengthChecker_hpp */
