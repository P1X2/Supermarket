#pragma once
#include <vector>
#include <map>
#include "products/Product.h"
#include <string>
#include <stdexcept>

using namespace std;

class ProductShelve
{
	map <Product, int> inventory;

public:
	ProductShelve(vector<Product> prd, vector<int> prd_number);

	void update_inventory(Product prd);
	map <Product, int> get_inventory();

};

