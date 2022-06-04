#pragma once
#include "Cashier.h"
#include <list>
#include "Warehouseman.h"
class RegisterWarehouseman
{
	list<unique_ptr<Warehouseman>> employees;
public:
	void add_warehouseman(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);
	void remove_employee(int);
	void print_employees();
	void pass_time_unit();
};

