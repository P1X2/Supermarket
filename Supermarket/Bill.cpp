#include "Bill.h"


Bill::Bill(vector<Product> products): 
	money(money),products(products) {}

int Bill::count_total() { return 0; }

void Bill::print_bill() {}

vector<Product> Bill::get_products()
{
	return products;
}