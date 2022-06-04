#include "Warehouseman.h"
#include "SalaryError.h"

Warehouseman::Warehouseman(string n, string sur, int h, int iden, float mon) :
	Employee(n, sur, h, iden) {
	set_money_per_hour(mon);
}

void Warehouseman::set_money_per_hour(float money)
{
	if (money > 20 or money < 5)
		throw SalaryError(5, 20, "Warehouseman", money);
	else money_per_hour = money;
}

float Warehouseman::calculate_salary()
{
	return (160 * get_money_per_hour() + (get_hours() - 160) * (get_money_per_hour() + 4));
}

float Warehouseman::get_money_per_hour()
{
	return money_per_hour;
}

void Warehouseman::serch_product(Client whichCL, string product)
{
    map<Product, int>::iterator it;
    map<Product, int> inventory = magazine.get_inventory();

    for (it = inventory.begin(); it != inventory.end(); it++)
    {
        Product prd_map = it->first;

        if (prd_map.getName() == product)
        {
            if (it->second == 0)
            {
                // odpwieada ze mike ma
            }
            else
            {
                grab_product(inventory, it);
                magazine.update_inventory(it->first);
            }
        };
    }
}

void Warehouseman::grab_product(map<Product, int> shop_shelve, map<Product, int>::iterator it)
{
    pocket.push_back(it->first);
}

void Warehouseman::empty_pocket()
{
    vector<Product>::iterator it;
    it = pocket.begin();
    pocket.erase(it);
}



ostream& operator<<(ostream& os, Warehouseman emp)
{
	emp.print_employer();
	return os;
}