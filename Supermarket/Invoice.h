#pragma once
#include "Bill.h"
class Invoice :
    public Bill
{
    string name, surname;
    Address address;
public:
    Invoice(string name, string surname, Address address,vector<Product> products);
    int count_total();
    virtual ostream& operator<<(ostream& os);
};
