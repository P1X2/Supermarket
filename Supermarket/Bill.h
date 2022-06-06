#pragma once
#include "products/Product.h"
#include "Address.h"
class Bill
{
	vector<Product> products;
public:
	Bill(vector<Product> products);
	virtual int count_total();
	vector<Product> get_products();
	virtual ostream& operator<<(ostream& os);
};

