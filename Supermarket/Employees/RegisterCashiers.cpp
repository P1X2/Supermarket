#include "RegisterCashiers.h"
#include "EmployeeDoesNotExistException.h"
#include "EmployeeAlreadyExistsException.h"

void RegisterCashiers::add_cashier(string name, string surname, int hours, int id, float money)
{
	Cashier cashier(name, surname, hours, id, money);
	if (in_register(cashier.get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(cashier));
}

float RegisterCashiers::count_salaries()
{
	float sum = 0;
	for (vector<Cashier>::iterator emp_ptr = employees.begin(); emp_ptr!=employees.end();emp_ptr++)
	{
		sum += emp_ptr->calculate_salary();
	}
	return sum;
}

int RegisterCashiers::how_many_workers()
{
	return employees.size();
}

bool RegisterCashiers::in_register(int id)
{
	bool x = false;

	for (vector<Cashier>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end(); emp_ptr++)
	{
		if (id == emp_ptr->get_id()) x = true;
	}
	return x;

}

void RegisterCashiers::remove_employee(int id)
{
	if (in_register(id))
	{
		for (vector<Cashier>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end(); emp_ptr++)
		{
			if (id == emp_ptr->get_id())
			{
				employees.erase(emp_ptr); break;
			}
		}
	}

	else
		throw EmployeeDoesNotExistException();
}

void RegisterCashiers::print_employees()
{
	cout << "Cashiers:" << endl;
	for (vector<Cashier>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end(); emp_ptr++)
	{
		emp_ptr->print_employer();
	}
}

void RegisterCashiers::pass_time_unit()
{
	for (vector<Cashier>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end(); emp_ptr++)
	{
		emp_ptr->set_busy(emp_ptr->get_busy() - 1);
	}
}

ostream& operator<<(ostream& os, RegisterCashiers rc)
{
	{
		for (Cashier cl : rc.employees)
		{
			os << cl << endl;
		}
		return os;
	}
}