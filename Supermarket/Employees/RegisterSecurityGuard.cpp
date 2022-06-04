#include "RegisterSecurityGuard.h"
#include "EmployeeDoesNotExistException.h"
#include "EmployeeAlreadyExistsException.h"

void RegisterSecurityGuard::add_security_guard(string name, string surname, int hours, int id, float money)
{
	unique_ptr<SecurityGuard> guard = make_unique<SecurityGuard>(name, surname, hours, id, money);
	if (in_register(guard->get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(guard));
}

float RegisterSecurityGuard::count_salaries()
{
	float sum = 0;
	for (const auto& emp_ptr : employees)
	{
		sum += emp_ptr->calculate_salary();
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

	for (const auto& emp_ptr : employees)
	{
		if (id == emp_ptr->get_id()) x = true;
	}
	return x;

}

void RegisterSecurityGuard::remove_employee(int id)
{
	if (in_register(id))
	{
		for (const auto& emp_ptr : employees)
		{
			if (id == emp_ptr->get_id())
			{
				employees.remove(emp_ptr); break;
			}
		}
	}

	else
		throw EmployeeDoesNotExistException();
}

void RegisterSecurityGuard::print_employees()
{
	cout << "Security Guards:" << endl;
	for (const auto& emp_ptr : employees)
	{
		emp_ptr->print_employer();
	}
}

void RegisterSecurityGuard::pass_time_unit()
{
	for (const auto& emp_ptr : employees)
	{
		emp_ptr->set_busy(emp_ptr->get_busy() - 1);
	}
}
