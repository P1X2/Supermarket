#include "Register.h"
#include "EmployeeDoesNotExistException.h"

void Register::add_warehouseman(string name, string surname, int hours,int id, float money)
{
	unique_ptr<Warehouseman> warehouseman = make_unique<Warehouseman>(name, surname, hours, id, money);
	if (in_register(warehouseman->get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(warehouseman));
}

void Register::add_manager(string name, string surname, int hours, int id, float money)
{
	unique_ptr<Manager> manager = make_unique<Manager>(name, surname, hours, id, money);
	if (in_register(manager->get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(manager));
}

void Register::add_security_guard(string name, string surname, int hours, int id, float money)
{
	unique_ptr<SecurityGuard> securityguard = make_unique<SecurityGuard>(name, surname, hours, id, money);
	if (in_register(securityguard->get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(securityguard));
}

void Register::add_cashier(string name, string surname, int hours, int id, float money)
{
	unique_ptr<Cashier> cashier = make_unique<Cashier>(name, surname, hours, id, money);
	if (in_register(cashier->get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(cashier));
}

float Register::count_salaries()
{
	float sum=0;
	for (const auto& emp_ptr : employees)
	{
		sum += emp_ptr->calculate_salary();
	}
	return sum;
}

int Register::how_many_workers()
{
	return employees.size();
}

bool Register::in_register(int id)
{
	bool x = false;
	
	for (const auto& emp_ptr : employees)
	{
		if (id == emp_ptr->get_id()) x=true;
	}
	return x;
	
}

void Register::remove_employee(int id)
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

void Register::print_employees()
{
	for (const auto& emp_ptr : employees)
	{
		emp_ptr->print_employer();
	}
}

void Register::pass_time_unit()
{
	for (const auto& emp_ptr : employees)
	{
		emp_ptr->set_busy(emp_ptr->get_busy() - 1);
	}
}
