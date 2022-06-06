#pragma once
#include <list>
#include "Warehouseman.h"
class RegisterWarehouseman
{
	vector<Warehouseman> employees;
		
public:


	
	void add_warehouseman(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);
	void remove_employee(int);
	void print_employees();
	void pass_time_unit();
	friend class Client;
	friend class ProductShelve;
	friend class Supermarket;
	friend class Supermarket_sandbox;

	friend ostream& operator<<(ostream& os, RegisterWarehouseman& rw);
};

