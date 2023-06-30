#ifndef SYUAN_EX7_6_H
#define SYUAN_EX7_6_H

#include <string>
#include <istream>
#include <ostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isdn() const { return bookNo; }
    Sales_data& combine(const Sales_data& rhs);
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);

    return sum;
}

std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;

    return os;
}


#endif // SYUAN_EX7_6_H