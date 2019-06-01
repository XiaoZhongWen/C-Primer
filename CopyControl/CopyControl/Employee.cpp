//
//  Employee.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/21.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Employee.hpp"

Employee::Employee(std::string name): name(name) {
    number++;
    std::string card_no = std::to_string(number);
    cardNo = card_no;
}
