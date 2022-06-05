#include "Bill.h"


Bill::Bill(int money,vector<Product> products): 
	money(money),products(products) {}

int Bill::count_total() { return 0; }

void Bill::print_bill() {}

int Bill::get_money()
{
	return money;
}

vector<Product> Bill::get_products()
{
	return products;
}