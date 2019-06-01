//
//  main.cpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include <iostream>
#include "Sales_data.hpp"
#include "Screen.hpp"
#include "NoDefault.hpp"
#include "Person.hpp"

using namespace std;

class Example {
public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
//    static vector<double> vec(vecSize);
};

int main(int argc, const char * argv[]) {
    
    
//    Sales_data total;
//    if (read(cin, total)) {
//        Sales_data trans;
//        while (read(cin, trans)) {
//            if (total.isbn() == trans.isbn()) {
//                total.combine(trans);
//            } else {
//                print(cout, trans) << endl;
//                total = trans;
//            }
//        }
//        print(cout, total) << endl;
//    } else {
//        cerr << "No data?!" << endl;
//    }
    
//    vector<C> vec(10);
    
    Sales_data item("123", 1, 1.0);
    item.combine(string("456"));
    
    
//    Screen myScreen(5, 5, 'X');
//    myScreen.move(4, 0).set('#').display(cout);
//    cout << endl;
//    myScreen.display(cout);
//    cout << endl;
    
    return 0;
}
