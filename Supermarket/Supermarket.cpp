#include "Supermarket.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Supermarket::Supermarket()
{
	Register employees;
}

void Supermarket::load_eployees(string path)
{
	ifstream handle;
	handle.open(path);
	string job;
	string name;
	string surname;
	int hours;
	int id;
	float money_per_hour;
	while (handle.good())
	{
		string line;
		getline(handle, line);
		stringstream ss(line);
		string item;
		int i = 0;
		while (getline(ss, item, ' '))
		{
			i++;
			switch (i)
			{
			case 1:
				job = item;
			case 2:
				name = item;
				break;
			case 3:
				surname = item;
				break;
			case 4:
				hours = stoi(item);
				break;
			case 5:
				id = stoi(item);
				break;
			case 6:
				money_per_hour = stof(item);
				break;
			}
			if (i != 6)
			{
				throw FileReadError("Employees");
			}
			if (job == "cashier")
			{
				employees.add_cashier(name, surname, hours, id, money_per_hour);
			}
			if (job == "manager")
			{
				employees.add_manager(name, surname, hours, id, money_per_hour);
			}
			if (job == "securityguard")
			{
				employees.add_security_guard(name, surname, hours, id, money_per_hour);
			}
			if (job == "warehouseman")
			{
				employees.add_warehouseman(name, surname, hours, id, money_per_hour);
			}
		}
	}