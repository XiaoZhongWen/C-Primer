//
//  Foo.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/26.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Foo_hpp
#define Foo_hpp

#include <stdio.h>
#include <vector>

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

#endif /* Foo_hpp */
