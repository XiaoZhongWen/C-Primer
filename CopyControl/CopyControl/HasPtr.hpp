//
//  HasPtr.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/21.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef HasPtr_hpp
#define HasPtr_hpp

#include <stdio.h>
#include <string>

class Hasptr {
public:
    Hasptr(const Hasptr &);
    Hasptr(const std::string &s = std::string());
    Hasptr& operator=(const Hasptr &);
    ~Hasptr();
    
private:
    int i;
    std::string *ps;
};

#endif /* HasPtr_hpp */
