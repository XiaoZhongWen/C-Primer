//
//  Window_mgr.cpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Window_mgr.hpp"

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}
