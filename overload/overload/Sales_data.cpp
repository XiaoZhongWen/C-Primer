//
//  Sales_data.cpp
//  class
//
//  Created by 肖仲文 on 2019/4/27.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Sales_data.hpp"

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &s) {
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data();
    }
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " "
    << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " "
    << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}
