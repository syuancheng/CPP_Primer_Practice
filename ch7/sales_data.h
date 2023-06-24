#ifndef SYUAN_SALES_DATA_H
#define SYUAN_SALES_DATA_H

#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    bool isbn();

    void merge(Sales_data& sd);

};

void read(std::istream& is);




#endif // SYUAN_SALES_DATA_H