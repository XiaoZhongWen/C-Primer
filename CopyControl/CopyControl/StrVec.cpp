//
//  StrVec.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/25.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "StrVec.hpp"

std::allocator<std::string> StrVec::alloc;

#pragma mark - interface
StrVec::StrVec(const StrVec &sv) {
    std::pair<std::string *, std::string *> pair = alloc_n_copy(sv.begin(), sv.end());
    elements = pair.first;
    first_free = cap = pair.second;
}

StrVec::StrVec(StrVec &&sv) noexcept : elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
    sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&sv) noexcept {
    if (this != &sv) {
        free();
        elements = sv.elements;
        first_free = sv.first_free;
        cap = sv.cap;
        sv.elements = sv.first_free = sv.cap = nullptr;
    }
    return *this;
}

StrVec& StrVec::operator=(const StrVec &sv) {
    std::pair<std::string *, std::string *> pair = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = pair.first;
    first_free = cap = pair.second;
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

size_t StrVec::size() const {
    return first_free - elements;
}

size_t StrVec::capacity() const {
    return cap - elements;
}

std::string* StrVec::begin() const {
    return elements;
}

std::string* StrVec::end() const {
    return first_free;
}

void StrVec::reserve(std::size_t n) {
    if (n > capacity()) {
        auto newPtr = alloc.allocate(n);
        auto dest = newPtr;
        for (auto p = elements; p != first_free; p++) {
            alloc.construct(dest++, *p);
        }
        elements = newPtr;
        first_free = dest;
        cap = elements + n;
    }
}

void StrVec::resize(std::size_t n) {
    if (n < size()) {
        for (std::size_t i = n; i < size(); i++) {
            alloc.destroy(elements + i);
        }
        alloc.deallocate(elements + n, capacity() - n);
        first_free = cap = elements + n;
    } else if (n < capacity()) {
        alloc.deallocate(elements + n, capacity() - n);
        cap = elements + n;
    } else if (n > capacity()) {
        reserve(n);
    }
}

#pragma mark - private method
void StrVec::chk_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, capacity());
    }
}

void StrVec::reallocate() {
    size_t newCapacity = size()? 2 * size(): 1;
    auto newdata = alloc.allocate(newCapacity);
    auto dest = newdata;
    for (auto p = elements; p != first_free; p++) {
        alloc.construct(dest++, std::move(*p));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newCapacity;
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    std::pair<std::string *, std::string *> pair;
    auto begin = alloc.allocate(e - b);
    auto end = std::uninitialized_copy(b, e, begin);
    pair = std::make_pair(begin, end);
    return pair;
}

