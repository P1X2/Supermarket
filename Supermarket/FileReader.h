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
#include "Employees/RegisterCashiers.h"
#include "Employees/RegisterWarehouseman.h"
#include "Address.h"



class FileReader
{
public:

	vector <string> names;
	vector <string> surnames;
	vector <Address> addresses;
	
	void load_names_surnames(string);
	vector<Product> load_products(string);
	void load_addresses(string);

	void write_to_file();
};

