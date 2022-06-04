#pragma once
#include "Employees/Cashier.h"
#include "Employees/Employee.h"
#include "Employees/Manager.h"
#include "Employees/Person.h"
#include "Employees/Register.h"
#include "Employees/Warehouseman.h"
#include "FileReadError.h"
#include <vector>
#include "ProductShelve.h"
#include "products/DataBase.h"
#include "products/DataBase.h"




class FileReader
{
	Register employees;
	vector <string> names;
	vector <string> surnames;
	


public:

	void load_names_surnames(string);
	void load_products(string);
};

