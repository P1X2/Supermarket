#include "ProductShelve.h"

void ProductShelve::set_inventory(vector<Product> prd, vector<int> prd_number)
{
	if (prd.size() != prd_number.size())
	{
		throw exception("");
	}
	for (int i = 0; i != prd.size(); i++)
	{
		inventory.insert(pair<Product, int>(prd[i], prd_number[i]));
	}
}


map<Product, int> ProductShelve::get_inventory()
{
	return inventory;
}

void ProductShelve::who_is_looking_for_prd(RegisterWarehouseman &registerWHM)
{
	for (vector<Warehouseman>::iterator emp_ptr = registerWHM.employees.begin(); emp_ptr != registerWHM.employees.end(); emp_ptr++)
	{
		if (emp_ptr->get_is_serching_prd() == true && emp_ptr->get_busy() == 0)
		{
			Product serched_prd = search_prd(emp_ptr->get_searched_prd());
			emp_ptr->add_prd_to_pocket(serched_prd);
			emp_ptr->stop_searching();
			return;
		}
		if (emp_ptr->get_is_serching_prd() == true && emp_ptr->get_busy() != 0)
		{
			emp_ptr->set_busy(emp_ptr->get_busy() - 1);
			continue;
		}
		else
		{
			continue;
		}
	}
	return;
}

Product ProductShelve::search_prd(string prd_name)
{
	map<Product, int>::iterator it;

	for (it = inventory.begin(); it != inventory.end(); it++)
	{
		Product prd_map = it->first;

		if (prd_map.getName() == prd_name)
		{
			if (it->second == 0)
			{
				it = inventory.begin();
				return it->first;
			}
			else
			{
				this->update_inventory(it->first);
				return it->first;

			}
		}
	}
}


void ProductShelve::update_inventory(Product prd)
{
	inventory[prd] -= 1;
}

