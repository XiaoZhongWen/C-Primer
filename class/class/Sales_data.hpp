//
//  Sales_data.hpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Sales_data_hpp
#define Sales_data_hpp

#include <stdio.h>
#include <iostream>

struct Sales_data {
    
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    
private:
    // 数据成员
    /* ISBN编号 */
    std::string bookNo;
    /* 本书销量 */
    unsigned units_sold = 0;
    /* 本书总销售收入 */
    double revenue = 0.0;
    
public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {};
    Sales_data(std::istream &);
    
    // 关于Sales_data对象的操作
    // const 表示this是一个指向常量的指针, 该成员函数被称作常量成员函数
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
//    Sales_data& combine(Sales_data);
//    Sales_data& combine(Sales_data&);
    double avg_price() const;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif /* Sales_data_hpp */
