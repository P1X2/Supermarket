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

ostream& operator<<(ostream& os, const RegisterBills& reg)
{
	for (const auto& bill_ptr : reg.bills)
	{
		bill_ptr->print_bill();
	}
	return os;
}