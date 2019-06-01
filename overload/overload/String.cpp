//
//  String.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/25.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "String.hpp"
#include <iostream>

std::allocator<char> String::alloc;

String::String(const char *s) {
    std::size_t size = strlen(s) + 1;
    str = alloc.allocate(size);
    for (std::size_t i = 0; i < size; i++) {
        alloc.construct(str + i, s[i]);
    }
    alloc.construct(str + size, '\0');
    begin = 0;
    end = size - 1;
}

String::String(const String &s) {
    if (s.str) {
        std::size_t size = s.end + 1;
        str = alloc.allocate(size);
        for (std::size_t i = 0; i < size; i++) {
            alloc.construct(str + i, s.str[i]);
        }
        alloc.construct(str + size, '\0');
        begin = 0;
        end = s.end;
    }
//    std::cout << "copy constructor" << std::endl;
}

String::String(String &&s) noexcept : str(s.str), begin(s.begin), end(s.end) {
    s.str = nullptr;
//    std::cout << "move constructor" << std::endl;
}

String& String::operator=(const String &s) {
    if (s.str) {
        std::size_t size = s.end + 1;
        auto p = alloc.allocate(size);
        free();
        str = p;
        for (std::size_t i = 0; i < s.end; i++) {
            alloc.construct(str + i, p[i]);
        }
        alloc.construct(str + size, '\0');
        begin = 0;
        end = s.end;
    }
    return *this;
}

String& String::operator=(String &&s) noexcept {
    if (this != &s) {
        free();
        str = s.str;
        begin = s.begin;
        end = s.end;
        s.str = nullptr;
    }
    std::cout << "move constructor operator" << std::endl;
    return *this;
}

void String::print() const {
    for (size_t i = begin; i != end; i++) {
        printf("%c", str[i]);
    }
}

std::ostream& operator<<(std::ostream &os, const String &s) {
    os << s.str;
    return os;
}

char& String::operator[](std::size_t n) {
    return str[n];
}

const char& String::operator[](std::size_t n) const {
    return str[n];
}

void String::free() {
    if (str) {
        for (std::size_t i = 0; i <= end; i++) {
            alloc.destroy(str + i);
        }
        alloc.deallocate(str, end + 1);
    }
}

String::~String() {
    free();
}
