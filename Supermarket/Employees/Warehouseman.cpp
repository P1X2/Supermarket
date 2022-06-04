#include "Warehouseman.h"
#include "SalaryError.h"
//#include "..\Supermarket.h"

Warehouseman::Warehouseman(string n, string sur, int h, int iden, float mon) :
	Employee(n, sur, h, iden)
{
	set_money_per_hour(mon);
}

bool Warehouseman::get_is_serching_prd()
{
	return is_serching_prd;
}

string Warehouseman::get_searched_prd()
{
	return searched_prd;
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



void Warehouseman::serch_product(string surename, string product)
{
	is_serching_prd = true;
	searched_prd = product;
	served_client = surename;
}

void Warehouseman::stop_searching()
{
	is_serching_prd = false;
}

void Warehouseman::add_prd_to_pocket(Product prd)
{
	pocket.push_back(prd);
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