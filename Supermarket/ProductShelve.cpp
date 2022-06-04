#include "ProductShelve.h"

ProductShelve::ProductShelve(vector<Product> prd, vector<int> prd_number)
{
	if (prd.size() != prd_number.size())
	{
		throw exception("");
	}
	for (int i = 0; i != prd.size(); i++)
	{
		inventory.insert(pair<Product, int>(prd[i], prd_number[i]));
	}
}


map<Product, int> ProductShelve::get_inventory()
{
	return inventory;
}

void ProductShelve::update_inventory(Product prd)
{
	inventory[prd] -= 1;
}

