#pragma once
#include "SecurityGuard.h"
#include <list>
class RegisterSecurityGuard
{
	list<unique_ptr<SecurityGuard>> employees;
public:
	void add_security_guard(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);
	void remove_employee(int);
	void print_employees();
	void pass_time_unit();
};

