#pragma once
#include "products/Product.h"
#include "Address.h"
class Bill
{
	int money;
	vector<Product> products;
public:
	Bill(vector<Product> products);
	virtual int count_total();
	virtual void print_bill();
	vector<Product> get_products();
};
