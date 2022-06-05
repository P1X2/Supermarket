#pragma once
#include "Bill.h"
class Invoice :
    public Bill
{
public:
    Invoice(string name, string surname, int money, Address address,vector<Product> products);
    int count_total();
    void print_bill();
};

