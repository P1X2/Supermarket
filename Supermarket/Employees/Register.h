#pragma once
#include <list>
#include <iostream>
#include "Employee.h"
#include "Warehouseman.h"
#include "Cashier.h"
#include "Manager.h"
#include "SecurityGuard.h"
#include "EmployeeAlreadyExistsException.h"
#include <memory>

using namespace std;
class Register
{
	list<unique_ptr<Employee>> employees;
public:
	
	Register();
	
	void add_cashier(string, string, int, int, float);
	void add_warehouseman(string, string, int, int, float);
	void add_manager(string, string, int, int, float);
	void add_security_guard(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);
	void remove_employee(int);
	void print_employees();
};
