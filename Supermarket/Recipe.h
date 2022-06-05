#pragma once
#include "Bill.h"
class Recipe :
    public Bill
{
    int get_price_with_vat(Product product);
public:
    Recipe(vector<Product> products);
    int count_total();
    void print_bill();
};

