#include "Warehouseman.h"
#include "SalaryError.h"
#include "..\Supermarket.h"

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
	set_busy(RNG.generate_random_number(0, 3));
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

void Warehouseman::go_to_magazine()
{
	action = "is going to the magazine";
	set_busy(3);
}

void Warehouseman::gave_to_client()
{
	action = "gave product to the client";
	set_busy(1);
}

ostream& operator<<(ostream& os, Warehouseman emp)
{
	if (emp.action == "is going to the magazine")
	{
		os << emp.get_name() << " " << emp.get_surname() << " " << emp.action;
		os << " to look for " << emp.pocket[0] << endl;
	}
	else if (emp.action == "gave product to the client")
	{
		os << emp.get_name() << " " << emp.get_surname() << " " << emp.action;
	}
	return os;
}