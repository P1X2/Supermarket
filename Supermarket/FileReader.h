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




class FileReader
{
public:
	vector <string> names;
	vector <string> surnames;
	




	void load_names_surnames(string);
	vector<Product> load_products(string);
};

