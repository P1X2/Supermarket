#include "RegisterBills.h"

void RegisterBills::add_invoice(string name, string surname, Address address, vector<Product>products)
{
	unique_ptr<Invoice> invoice = make_unique<Invoice>(name, surname, address, products);
	bills.push_back(move(invoice));
}

void RegisterBills::add_recipe(vector<Product>products)
{
	unique_ptr<Recipe> recipe = make_unique<Recipe>(products);
	bills.push_back(move(recipe));
}

ostream& operator<<(ostream& os, RegisterBills& reg)
{
	int i = 0;
	for (const auto& bill_ptr : reg.bills)
	{
		i++;
		os << "Bill " << i << ": " << endl;
		bill_ptr->operator<<(os);
		os << endl;
	}
	
	return os;
}

