#pragma once
#include <vector>
#include "products/Product.h"
#include <string>

using namespace std;

class ProductShelve
{
	vector<Product> shelve_products;
	int shelve_number, product_count;


public:
	ProductShelve(vector<Product> prd, int shelve_number);

	vector<Product> get_shelve_products();
	void remove_product(Product prd);
};

