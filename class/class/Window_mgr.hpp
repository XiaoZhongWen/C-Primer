//
//  Window_mgr.hpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Window_mgr_hpp
#define Window_mgr_hpp

#include <stdio.h>
#include <vector>
#include "Screen.hpp"

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif /* Window_mgr_hpp */
