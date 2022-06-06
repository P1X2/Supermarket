#pragma once
#include "Employees/Cashier.h"
#include "Employees/Employee.h"
#include "Employees/Manager.h"
#include "Employees/Person.h"
#include "FileReadError.h"
#include <vector>
#include "ProductShelve.h"
#include "products/DataBase.h"
#include "products/DataBase.h"
#include "Client.h"
#include "Employees/RegisterCashiers.h"
#include "Employees/RegisterWarehouseman.h"
#include "Address.h"
#include "RegisterBills.h"
#include "RegisterClient.h"
#include "Checkout.h"
#include "Employees/RegisterWarehouseman.h"
#include "Employees/RegisterSecurityGuard.h"



class FileReader
{
	string bills_file, simulation_file;
public:

	vector <string> names;
	vector <string> surnames;
	vector <Address> addresses;

	
	void load_names_surnames(string);
	vector<Product> load_products(string);
	void load_addresses(string);
	void set_saving_files(string bills, string simulation);

	void write_clients_to_simulation_file(RegisterClient register_clients);
	void write_checkout_to_simulation_file(Checkout checkout);
	void write_warehousemen_to_simulation_file(RegisterWarehouseman warehousemen);
	void write_securityguard_to_simulation_file(RegisterSecurityGuard scurity_guard);

	void write_bills_to_file(RegisterBills& bills);
};

