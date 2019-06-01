//
//  Screen.hpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <iostream>

class Screen {
    friend class Window_mgr;
    
public:
    typedef std::string::size_type pos;
    
    void dummy_fcn(pos height) {
        cursor = width * height;
    }
    
    Screen() = default;
    Screen(pos ht, pos wt) : height(ht), width(wt) {}
    Screen(pos ht, pos wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
    
    char get() const {
        return contents[cursor];
    }
    
    char get(pos ht, pos wt) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    
private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const {
        os << contents;
    }
};

#endif /* Screen_hpp */
