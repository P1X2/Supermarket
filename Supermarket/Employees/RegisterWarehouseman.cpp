#include "RegisterWarehouseman.h"

#include "EmployeeDoesNotExistException.h"
#include "EmployeeAlreadyExistsException.h"

void RegisterWarehouseman::add_warehouseman(string name, string surname, int hours, int id, float money)
{
	unique_ptr<Warehouseman> warehouseman = make_unique<Warehouseman>(name, surname, hours, id, money);
	if (in_register(warehouseman->get_id()))
	{
		throw EmployeeAlreadyExistsException();
	}
	employees.push_back(move(warehouseman));
}


float RegisterWarehouseman::count_salaries()
{
	float sum = 0;
	for (const auto& emp_ptr : employees)
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

	for (const auto& emp_ptr : employees)
	{
		if (id == emp_ptr->get_id()) x = true;
	}
	return x;

}

void RegisterWarehouseman::remove_employee(int id)
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

void RegisterWarehouseman::print_employees()
{
	for (const auto& emp_ptr : employees)
	{
		emp_ptr->print_employer();
	}
}

void RegisterWarehouseman::pass_time_unit()
{
	for (const auto& emp_ptr : employees)
	{
		emp_ptr->set_busy(emp_ptr->get_busy() - 1);
	}
}
