#include "Invoice.h"

Invoice::Invoice(string name, string surname,Address address, vector<Product> products) :
	Bill(products), name(name),surname(surname),address(address) {}

int Invoice::count_total()
{
	int total=0;
	for (Product prod : get_products())
	{
		total = total + round(prod.getPrice()/100);
	}
	return total;
}

ostream& Invoice::operator<<(ostream& os)
{
	os << endl << "            Invoice" << endl;
	os << "         Client data:" << endl;
	os << "Name: " << name << " " << surname << endl;
	os << "Address: " << address;
	os << "_________________________________" << endl;
	os << "           Products:" << endl;
	for (Product prod : get_products())
	{
		os << prod.getName() << ": " << round(prod.getPrice() / 100) << " zl" << endl;
	}
	os << "Summary: " << count_total() << " zl" << endl;
	os << "_________________________________" << endl;
	return os;
}