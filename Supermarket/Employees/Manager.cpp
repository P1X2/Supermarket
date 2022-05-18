#include "Manager.h"
#include "SalaryError.h"

Manager::Manager(string n, string sur, int h,int iden, float mon) :
	Employee(n, sur, h, iden) {
	set_money_per_hour(mon);
}

void Manager::set_money_per_hour(float money)
{
	if (money > 1000 or money < 50)
		throw SalaryError(50, 1000, "Manager", money);
	else money_per_hour = money;
}

void Manager::print_schedule()
{
	vector<int> bufor = get_schedule();
	cout << "Schedule: ";
	for (int i = 1; i < 7; i++)
	{
		switch (i)
		{
		case 1:
			cout << "Monday: 10-" << bufor[i-1]+10 << ", ";
			break;
		case 2:
			cout << "Tuesady: 10-" << bufor[i-1]+10 << ", ";
			break;
		case 3:
			cout << "Wednesday: 10-" << bufor[i-1]+10<< ", ";
			break;
		case 4:
			cout << "Thursday : 10-" << bufor[i-1]+10 << ", ";
			break;
		case 5:
			cout << "Friday: 10-" << bufor[i-1]+10 << ", ";
			break;
		case 6:
			cout << "Saturday: 10-" << bufor[i-1]+10 << ", ";
			break;
		default:
			break;
		}
	}
}



float Manager::calculate_salary()
{
	return (160 * get_money_per_hour() + (get_hours() - 160) * (get_money_per_hour() + 20));
}

float Manager::get_money_per_hour()
{
	return money_per_hour;
}

ostream& operator<<(ostream& os, Manager emp)
{
	emp.print_employer();
	return os;
}