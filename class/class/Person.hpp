//
//  Person.hpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>

struct Person {
    std::string name = "";
    std::string address = "";
    
    Person() = default;
    Person(const std::string &name, const std::string &address) : name(name), address(address) {};
    
    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
};

std::istream &read(std::istream&, Person &);
std::ostream &print(std::ostream&, const Person &);

#endif /* Person_hpp */
