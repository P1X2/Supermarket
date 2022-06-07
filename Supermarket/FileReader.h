#pragma once
#include "Employees/Cashier.h"
#include "Employees/Employee.h"
#include "Employees/Person.h"
#include "FileReadError.h"
#include <vector>
#include "ProductShelve.h"
#include "products/Friut.h"
#include "products/Juice.h"
#include "products/Meat.h"
#include "products/Whiskey.h"
#include "products/Product.h"
#include "Client.h"
#include "Employees/RegisterCashiers.h"
#include "Employees/RegisterWarehouseman.h"
#include "Address.h"
#include "RegisterBills.h"
#include "RegisterClient.h"
#include "Checkout.h"


class FileReader
{
public:

	vector <string> names;
	vector <string> surnames;
	vector <Address> addresses;

	
	void load_names_surnames(string);
	vector<Product> load_products(string);
	void load_addresses(string);

	void write_client_to_simulation_file(Client& client);
	void write_checkout_to_simulation_file(Checkout checkout);
	void write_warehouseman_to_simulation_file(Warehouseman& warehouseman);

	void write_bills_to_file(RegisterBills& bills);
	void write_invoice_to_file(Invoice& invoice);
	void write_recipe_to_file(Recipe& recipe);
};

