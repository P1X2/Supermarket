#pragma once
#include "Bill.h"
class Invoice :
    public Bill
{
    string name, surname;
    Address address;
public:
    Invoice(string name, string surname, int money, Address address,vector<Product> products);
    int count_total();
    void print_bill();
};

