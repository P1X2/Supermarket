#pragma once
#include "SecurityGuard.h"
#include <vector>
class RegisterSecurityGuard
{
	vector<SecurityGuard> employees;
public:
	void add_security_guard(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);

	friend ostream& operator<<(ostream& os, RegisterSecurityGuard& rc);
};

