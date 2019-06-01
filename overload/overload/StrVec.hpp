//
//  StrVec.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/25.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef StrVec_hpp
#define StrVec_hpp

#include <stdio.h>
#include <memory>
#include <string>

class StrVec {
    
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(const StrVec &);
    StrVec& operator=(StrVec &&) noexcept;
    std::string& operator[](std::size_t n);
    const std::string& operator[](std::size_t n) const;
    ~StrVec();
    std::size_t size() const;
    size_t capacity() const;
    std::string* begin() const;
    std::string* end() const;
    void push_back(const std::string &);
    // 分配至少能容纳n个元素的内存空间, 如果n大于当前容器已分配的内存空间, 容器的容量会改变; 当n小于或等于当前容量, 不做任何操作
    void reserve(std::size_t);
    // 调整n的大小为n个元素, 若n小于当前容量, 则多出的元素被丢弃; 若必须添加新元素, 对新元素进行值初始化
    void resize(std::size_t);
private:
    static std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
    
    void chk_n_alloc();
    void free();
    void reallocate();
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
};

#endif /* StrVec_hpp */
