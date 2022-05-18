
#include <iostream>
#include "Employee.h"
#include "Cashier.h"
#include <list>
#include "Manager.h"
#include "Register.h"
#include "WorkingHoursError.h"
#include "EmployeeAlreadyExistsException.h"
#include "SalaryError.h"
#include "EmployeeDoesNotExistException.h"

using namespace std;

void print_menu()
{
	cout << "Menu: " << endl << endl;
	cout << "1.Add Cashier" << endl;
	cout << "2.Add Manager" << endl;
	cout << "3.Add Warehouseman" << endl;
	cout << "4.Add Security Guard" << endl;
	cout << "5.Remove employee" << endl;
	cout << "6.Print employees" << endl;
	cout << "7.Count total salary" << endl;
	cout << "8.Leave" << endl;
}

string load_name(string emp)
{
	string name;
	cout << emp << "'s name: ";
	cin >> name;
	cout << endl;
	return name;
}

string load_surname(string emp)
{
	string surname;
	cout << emp << "'s surname: ";
	cin >> surname;
	cout << endl;
	return surname;
}

int load_hours(string emp)
{
	int hours;
	cout << emp << "'s working hours in month: ";
	cin >> hours;
	cout << endl;
	return hours;
}

int load_id(string emp)
{
	int id;
	cout << emp << "'s id: ";
	cin >> id;
	cout << endl;
	return id;
}

float load_money(string emp)
{
	float money;
	cout << emp << "'s money per hour: ";
	cin >> money;
	cout << endl;
	return money;
}

int main()
{
	Register register1;
	bool run = true;
	while (run)
	{
		print_menu();
		char choice;
		cin >> choice;
		try
		{
			switch (choice)
			{
			case '1':
				register1.add_cashier(load_name("Cashier"), load_surname("Cashier"), load_hours("Cashier"), load_id("Cashier"), load_money("Cashier"));
				break;
			case '2':
				register1.add_manager(load_name("Manager"), load_surname("Manager"), load_hours("Manager"), load_id("Manager"), load_money("Manager"));
				break;
			case '3':
				register1.add_warehouseman(load_name("Warehouseman"), load_surname("Warehouseman"), load_hours("Warehouseman"), load_id("Warehouseman"), load_money("Warehouseman"));
				break;
			case '4':
				register1.add_security_guard(load_name("Security Guard"), load_surname("Security Guard"), load_hours("Security Guard"), load_id("Security Guard"), load_money("Security Guard"));
				break;
			case '5':
				int iden;
				cout << "Input id of employee to remove: ";
				cin >> iden;
				register1.remove_employee(iden);
				break;
			case '6':
				register1.print_employees();
				break;
			case '7':
				cout << "Sum of all salaries: " <<  register1.count_salaries() << endl;
				break;
			case '8':
				run = false;
				break;
			default:
				cout << choice << " is a wrong input." << endl;
				cout << "Please input a number from 1 to 8" << endl;
				break;
			}
		}
		catch (const SalaryError e1)
		{
			cout << "Caught an exception SalaryError" << endl << e1.what() << endl;
		}
		catch (const WorkingHoursError e2)
		{
			cout << "Caught an exception WorkingHoursError" << endl << e2.what() << endl;
		}
		catch (const EmployeeAlreadyExistsException e3)
		{
			cout << "Caught an exception EmployeeAlreadExistsException" << endl << e3.what() << endl;
		}
		catch (const EmployeeDoesNotExistException e4)
		{
			cout << "Caught an exception EmployeeDoesNotExistException" << endl << e4.what() << endl;
		}
	}
	return 0;
}
