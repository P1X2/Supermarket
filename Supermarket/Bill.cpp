#include "Bill.h"


Bill::Bill(vector<Product> products): 
	products(products) {}

int Bill::count_total() { return 0; }

//void Bill::print_bill() {}

vector<Product> Bill::get_products()
{
	return products;
}

ostream& Bill::operator<<(ostream& os)
{
	return os;
}