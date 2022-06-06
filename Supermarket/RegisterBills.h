#pragma once
#include "Invoice.h"
#include "Recipe.h"
class RegisterBills
{
	vector<unique_ptr<Bill>> bills;
public:
	void add_invoice(string name, string surname, Address address, vector<Product>products);
	void add_recipe(vector<Product>products);

	friend ostream& operator<<(ostream& os, RegisterBills& reg);
};

ostream& operator<<(ostream& os, RegisterBills& reg);