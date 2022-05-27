#pragma once
#include "Employees/Cashier.h"
#include "Employees/Employee.h"
#include "Employees/Manager.h"
#include "Employees/Person.h"
#include "Employees/Register.h"
#include "Employees/SecurityGuard.h"
#include "Employees/Warehouseman.h"

class Supermarket
{
	Register Employees;

public:
	Supermarket();
	void load_eployees(string);
};

