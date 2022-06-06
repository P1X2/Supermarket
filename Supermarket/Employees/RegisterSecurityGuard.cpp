#include "RegisterSecurityGuard.h"
#include "EmployeeDoesNotExistException.h"
#include "EmployeeAlreadyExistsException.h"

void RegisterSecurityGuard::add_security_guard(string name, string surname, int hours, int id, float money)
{
	SecurityGuard guard(name, surname, hours, id, money);
	if (in_register(guard.get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(guard);
}

float RegisterSecurityGuard::count_salaries()
{
	float sum = 0;
	for (SecurityGuard emp_ptr : employees)
	{
		sum += emp_ptr.calculate_salary();
	}
	return sum;
}

int RegisterSecurityGuard::how_many_workers()
{
	return employees.size();
}

bool RegisterSecurityGuard::in_register(int id)
{
	bool x = false;

	for (SecurityGuard emp_ptr : employees)
	{
		if (id == emp_ptr.get_id()) x = true;
	}
	return x;

}

ostream& operator<<(ostream& os, RegisterSecurityGuard& rc)
{
	{
		for (SecurityGuard cl : rc.employees)
		{
			os << cl << endl;
		}
		return os;
	}
}