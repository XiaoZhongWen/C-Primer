//
//  numbered.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/20.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef numbered_hpp
#define numbered_hpp

#include <stdio.h>
#include <string>
#include <uuid/uuid.h>

class numbered {
public:
    numbered() {
        uuid_t uid;
        uuid_generate(uid);
        mysn = (char *)uid;
    }
    
    numbered(const numbered &n) {
        uuid_t uid;
        uuid_generate(uid);
        mysn = (char *)uid;
    }
    
    std::string mysn;
};

#endif /* numbered_hpp */
