//
//  NoDefault.hpp
//  class
//
//  Created by 肖仲文 on 2019/4/28.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef NoDefault_hpp
#define NoDefault_hpp

#include <stdio.h>

class NoDefault {
public:
    NoDefault() = default;
    NoDefault(int){};
};

class C {
public:
    NoDefault defaultItem;
    C(NoDefault d): defaultItem(d){};
};

#endif /* NoDefault_hpp */
