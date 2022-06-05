#include "Invoice.h"

Invoice::Invoice(string name, string surname, int money, Address address, vector<Product> products) :
	Bill(name, surname, money, address, products) {}

int Invoice::count_total()
{
	int total=0;
	for (Product prod : get_products())
	{
		total = total + prod.getPrice();
	}
	return total;
}

void Invoice::print_bill()
{

}