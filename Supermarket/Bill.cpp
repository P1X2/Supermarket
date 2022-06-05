#include "Bill.h"


Bill::Bill(string name, string surname, int money, Address address, vector<Product> products): 
	name(name),surname(surname), money(money),address(address),products(products) {}

int Bill::count_total() { return 0; }

void Bill::print_bill() {}

string Bill::get_name()
{
	return name;
}

string Bill::get_surname()
{
	return surname;
}

int Bill::get_money()
{
	return money;
}

Address Bill::get_address()
{
	return address;
}

vector<Product> Bill::get_products()
{
	return products;
}