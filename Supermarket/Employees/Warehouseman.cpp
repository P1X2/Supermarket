#include "Warehouseman.h"
#include "SalaryError.h"

Warehouseman::Warehouseman(string n, string sur, int h, int iden, float mon) :
	Employee(n, sur, h, iden) {
	set_money_per_hour(mon);
}

void Warehouseman::set_money_per_hour(float money)
{
	if (money > 30 or money < 5)
		throw SalaryError(5, 30, "Warehouseman", money);
	else money_per_hour = money;
}

void Warehouseman::print_schedule()
{
	vector<int> bufor = get_schedule();
	cout << "Schedule: ";
	for (int i = 1; i < 7; i++)
	{
		switch (i)
		{
		case 1:
			cout << "Monday: 4-" << bufor[i - 1] + 4 << ", ";
			break;
		case 2:
			cout << "Tuesady: 4-" << bufor[i - 1] + 4 << ", ";
			break;
		case 3:
			cout << "Wednesday: 4-" << bufor[i - 1] + 4 << ", ";
			break;
		case 4:
			cout << "Thursday : 4-" << bufor[i - 1] + 4 << ", ";
			break;
		case 5:
			cout << "Friday: 4-" << bufor[i - 1] + 4 << ", ";
			break;
		case 6:
			cout << "Saturday: 4-" << bufor[i - 1] + 4 << ", ";
			break;
		default:
			break;
		}
	}
}



float Warehouseman::calculate_salary()
{
	return (160 * get_money_per_hour() + (get_hours() - 160) * (get_money_per_hour() + 4));
}

float Warehouseman::get_money_per_hour()
{
	return money_per_hour;
}

ostream& operator<<(ostream& os, Warehouseman emp)
{
	emp.print_employer();
	return os;
}