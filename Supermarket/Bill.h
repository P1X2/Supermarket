#pragma once
#include "products/Product.h"
#include "Address.h"
class Bill
{
	string name, surname;
	int money;
	Address address;
	vector<Product> products;
public:
	Bill(string name, string surname, int total, Address address,vector<Product> products);
	virtual int count_total();
	virtual void print_bill();
	vector<Product> get_products();
	Address get_address();
	int get_money();
	string get_name();
	string get_surname();
};

