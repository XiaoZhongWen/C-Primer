//
//  main.cpp
//  Function
//
//  Created by 肖仲文 on 2019/4/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>

#define NDEBUG

void testAssert() {
    int i = -1;
    assert(i > 0);
}

int main(int argc, const char * argv[]) {
    
    testAssert();
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
