//
//  Person.cpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Person.hpp"

std::istream &read(std::istream &is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << person.name << " " << person.address;
    return os;
}
