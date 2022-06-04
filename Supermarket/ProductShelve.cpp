#include "ProductShelve.h"+

ProductShelve::ProductShelve(vector<Product> prd, vector<int> prd_number)
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

void ProductShelve::who_is_looking_for_prd(RegisterWarehouseman registerWHM)
{
	for (const auto& emp_ptr : registerWHM.employees)
	{
		if (emp_ptr->get_is_serching_prd() == true)
		{
			Product serched_prd = search_prd(emp_ptr->get_searched_prd());
		}
		else
		{
			continue;
		}
	}
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

