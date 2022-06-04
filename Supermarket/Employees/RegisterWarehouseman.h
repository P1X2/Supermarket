#pragma once
#include <list>
#include "Warehouseman.h"
class RegisterWarehouseman
{

		
public:
	list<unique_ptr<Warehouseman>> employees;


	void add_warehouseman(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);
	void remove_employee(int);
	void print_employees();
	void pass_time_unit();
};

