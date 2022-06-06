#pragma once
#include "Bill.h"
#include <cmath>
class Recipe :
    public Bill
{
    float get_price_with_vat(Product product);
public:
    Recipe(vector<Product> products);
    int count_total();
    void print_bill();
};

