#pragma once
#include "Employees/Cashier.h"
#include "Employees/Employee.h"
#include "Employees/Manager.h"
#include "Employees/Person.h"
#include "Employees/Register.h"
#include "Employees/SecurityGuard.h"
#include "Employees/Warehouseman.h"
#include "FileReadError.h"
#include <vector>
#include "ProductShelve.h"
#include "products/DataBase.h"




class Supermarket
{
	Register employees;
	DataBase products;
	vector<ProductShelve> product_shelve;

public:
	Supermarket();
	void load_eployees(string);
};

