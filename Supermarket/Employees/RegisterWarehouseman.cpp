#include "RegisterWarehouseman.h"

#include "EmployeeDoesNotExistException.h"
#include "EmployeeAlreadyExistsException.h"

void RegisterWarehouseman::add_warehouseman(string name, string surname, int hours, int id, float money)
{
	Warehouseman warehouseman(name, surname, hours, id, money);
	if (in_register(warehouseman.get_id() == true))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back((warehouseman));
}


float RegisterWarehouseman::count_salaries()
{
	float sum = 0;
	for (vector<Warehouseman>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end();emp_ptr++)
	{
		sum += emp_ptr->calculate_salary();
	}
	return sum;
}

int RegisterWarehouseman::how_many_workers()
{
	return employees.size();
}

bool RegisterWarehouseman::in_register(int id)
{
	bool x = false;

	for (vector<Warehouseman>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end();emp_ptr++)
	{
		if (id == emp_ptr->get_id()) x = true;
	}
	return x;

}

void RegisterWarehouseman::remove_employee(int id)
{
	if (in_register(id))
	{
		for (vector<Warehouseman>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end();emp_ptr++)
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

void RegisterWarehouseman::print_employees()
{
	cout << "Warehousemen:" << endl;
	for (vector<Warehouseman>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end();emp_ptr++)
	{
		emp_ptr->print_employer();
	}
}

void RegisterWarehouseman::pass_time_unit()
{

	for (vector<Warehouseman>::iterator emp_ptr = employees.begin(); emp_ptr != employees.end();emp_ptr++)
	{
		emp_ptr->set_busy(emp_ptr->get_busy() - 1);
	}
}


ostream& operator<<(ostream& os, RegisterWarehouseman& rc)
{
	{
		for (Warehouseman cl : rc.employees)
		{
			os << cl << endl;
		}
		return os;
	}
}