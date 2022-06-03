#include "ProductShelve.h"

ProductShelve::ProductShelve(vector<Product> prd, int shelve_number): shelve_products(prd), shelve_number(shelve_number)
{
	this->product_count = shelve_products.size();
}

vector<Product> ProductShelve::get_shelve_products()
{
	return shelve_products;
}

void ProductShelve::remove_product(Product prd)
{
	vector<Product>::iterator it;
	for (it = shelve_products.begin(); it != shelve_products.end(); it++)
	{
		if (*it == prd)
		{
			shelve_products.erase(it);
			product_count -= 1;
			return;
		
		
		}




	}
}
