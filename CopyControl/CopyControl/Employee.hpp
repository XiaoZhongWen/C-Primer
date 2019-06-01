//
//  Employee.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/21.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>

static int number;

class Employee {
public:
    Employee() = default;
    Employee(std::string name);
    
private:
    std::string name;
    std::string cardNo;
};

#endif /* Employee_hpp */
