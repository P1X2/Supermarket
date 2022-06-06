#include "Warehouseman.h"
#include "SalaryError.h"
#include "..\Supermarket.h"
#include <stdexcept>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <cstdlib>

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

int Warehouseman::get_client_id()
{
	return served_client;
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





void Warehouseman::serch_product(int id, string product)
{
	is_serching_prd = true;
	searched_prd = product;
	this->served_client = id;
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

ostream& operator<<(ostream& os, Warehouseman& emp)
{
	if (emp.get_activity() == " is going to the magazine")
	{
		os << emp.get_name() << " " << emp.get_surname() << " " << emp.get_activity();
		os << " to look for " << emp.get_searched_prd() << " for client with id "<< emp.get_client_id() << endl;
	}
	else if (emp.get_activity() == "gave product to the client ")
	{
		os << emp.get_name() << " " << emp.get_surname() << " gave " << emp.get_searched_prd() << " to the client with id " << emp.get_client_id();
	}
	return os;
}