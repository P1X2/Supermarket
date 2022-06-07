#include "Warehouseman.h"
#include "SalaryError.h"
#include "..\Supermarket.h"
#include <stdexcept>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <cstdlib>
#include "../FileReadError.h"

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

string Warehouseman::get_client_name()
{
	return served_cl_name;
}

string Warehouseman::get_client_surname()
{
	return served_cl_surname;
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





void Warehouseman::serch_product(int id,string name, string surname, string product)
{
	is_serching_prd = true;
	searched_prd = product;
	served_client = id;
	served_cl_name = name;
	served_cl_surname = surname;

	set_activity("is going to the magazine");
	cout << *this;
	FileReader writer;
	writer.write_warehouseman_to_simulation_file(*this);
	Sleep(1500);
	set_busy(RNG.generate_random_number(0, 3));
}

void Warehouseman::stop_searching()
{
	is_serching_prd = false;
}

void Warehouseman::add_prd_to_pocket(Product prd)
{
	if (prd.getName() == "")
	{
		set_activity("didnt found");
		cout << *this;
		FileReader writer;
		writer.write_warehouseman_to_simulation_file(*this);
		Sleep(1500);

	}
	else
	{
		set_activity("found");
		cout << *this;
		FileReader writer;
		writer.write_warehouseman_to_simulation_file(*this);
		Sleep(1500);
	}
	pocket.push_back(prd);
}


void Warehouseman::empty_pocket()
{
	if (get_activity() == "found")
	{
		set_activity("gave product to the client");
		cout << *this;
		FileReader writer;
		writer.write_warehouseman_to_simulation_file(*this);
		Sleep(2000);
	}
	if (get_activity() == "didnt found")
	{
		set_activity("inform there is no more");
		cout << *this;
		FileReader writer;
		writer.write_warehouseman_to_simulation_file(*this);
		Sleep(2000);
	};
    vector<Product>::iterator it;
    it = pocket.begin();
    pocket.erase(it);
}

ostream& operator<<(ostream& os, Warehouseman& emp)
{
	if (emp.get_activity() == "is going to the magazine")
	{
		os <<endl<< emp.get_name() << " " << emp.get_surname() << " " << emp.get_activity();
		os << " to look for " << emp.get_searched_prd() << " for client "<< emp.get_client_name() << " " << emp.get_client_surname() << endl<<endl;
	}
	else if (emp.get_activity() == "gave product to the client")
	{
		os <<endl<< emp.get_name() << " " << emp.get_surname() << " gave " << emp.get_searched_prd() << " to the client " << emp.get_client_name() << " " << emp.get_client_surname() << endl<<endl;
	}
	else if (emp.get_activity() == "inform there is no more")
	{
		os <<endl<< emp.get_name() << " " << emp.get_surname() << " informed client " << emp.get_client_name() << " " << emp.get_client_surname() << ", that there is no " << emp.get_searched_prd() << " in magazine" << endl<<endl;
	}
	else if (emp.get_activity() == "found")
	{
		os <<endl<< emp.get_name() << " " << emp.get_surname() << " found " << emp.get_searched_prd() << " for the client " << emp.get_client_name() << " " << emp.get_client_surname() << " in magazine" << endl<<endl;
	}
	else if (emp.get_activity() == "didnt found")
	{
		os <<endl<< emp.get_name() << " " << emp.get_surname() << " did not found " << emp.get_searched_prd() << " for the client " << emp.get_client_name() << " " << emp.get_client_surname() << " in magazine" <<endl <<endl;
	}
	return os;
}