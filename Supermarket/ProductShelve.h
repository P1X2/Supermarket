#pragma once
#include <vector>
#include <map>
#include "products/Product.h"
#include "Employees/Warehouseman.h"
#include "Employees/RegisterWarehouseman.h"
#include <string>
#include <stdexcept>

using namespace std;

class ProductShelve
{
	map <Product, int> inventory;

public:
	void set_inventory(vector<Product> prods, vector<int> ints);

	void update_inventory(Product prd);
	map <Product, int> get_inventory();

	void who_is_looking_for_prd(RegisterWarehouseman &registerWHM);
	Product search_prd(string prd_name);

	friend class Supermarket;
};

