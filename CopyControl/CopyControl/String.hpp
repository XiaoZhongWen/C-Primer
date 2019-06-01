//
//  String.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/25.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <memory>

class String {
public:
    String(): str(nullptr) {};
    String(const char *);
    String(const String &);
    String(String &&) noexcept;
    String& operator=(const String &);
    String& operator=(String &&) noexcept;
    ~String();
    void free();
    
    void print() const;
    
private:
    char *str;
    size_t begin;
    size_t end;
    static std::allocator<char> alloc;
};

#endif /* String_hpp */
