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

void Invoice::print_bill()
{
	cout <<endl<< "            Invoice" << endl;
	cout << "         Client data:" << endl;
	cout << "Name: "<<name << " " << surname << endl;;
	cout << "Address: "<<address;
	cout <<"_________________________________" << endl;
	cout << "           Products:" << endl;
	for (Product prod : get_products())
	{
		cout << prod.getName() << ": " << round(prod.getPrice()/100) << " zl" << endl;
	}
	cout << "Summary: " << count_total() << " zl" << endl;
	cout << "_________________________________" << endl;

}