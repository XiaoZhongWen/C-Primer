//
//  Foo.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/26.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Foo.hpp"

Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    return *this;
}

//Foo Foo::sorted() const & {
//    Foo ret(*this);
//    std::sort(ret.data.begin(), ret.data.end());
//    return ret;
//}

Foo Foo::sorted() const & {
    return Foo(*this).sorted();
}
