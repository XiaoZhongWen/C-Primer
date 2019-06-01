//
//  HasPtrV_2.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/21.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef HasPtrV_2_hpp
#define HasPtrV_2_hpp

#include <stdio.h>
#include <string>

class HasPtrV_2 {
public:
    HasPtrV_2(const std::string &s): i(0), ps(new std::string(s)), use(new std::size_t(1)) {};
    HasPtrV_2(const HasPtrV_2 &hp): i(hp.i), ps(hp.ps), use(hp.use) {
        (*use)++;
    }
    HasPtrV_2& operator=(const HasPtrV_2 &hp);
    ~HasPtrV_2();
    
private:
    int i;
    std::string *ps;
    std::size_t *use;
};

#endif /* HasPtrV_2_hpp */
