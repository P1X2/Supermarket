#include "Cashier.h"
#include "SalaryError.h"

Cashier::Cashier(string n, string sur, int h,int iden, float mon) :
	Employee(n, sur,h,iden) {
	set_money_per_hour(mon);
}

void Cashier::set_money_per_hour(float money)
{
	if (money > 30 or money < 5)
		throw SalaryError(5, 30, "cashier", money);
	else money_per_hour = money;
}

void Cashier::print_schedule()
{
	vector<int> bufor = get_schedule();
	cout << "Schedule: ";
	for (int i = 1; i < 7; i++)
	{
		switch (i)
		{
		case 1:
			cout << "Monday: 8-" << bufor[i-1]+8 << ", ";
			break;
		case 2:
			cout << "Tuesady: 8-" << bufor[i-1]+8 << ", ";
			break;
		case 3:
			cout << "Wednesday: 8-" << bufor[i-1]+8<< ", ";
			break;
		case 4:
			cout << "Thursday : 8-" << bufor[i-1]+8 << ", ";
			break;
		case 5:
			cout << "Friday: 8-" << bufor[i-1]+8 << ", ";
			break;
		case 6:
			cout << "Saturday: 8-" << bufor[i-1]+8 << ", ";
			break;
		default:
			break;
		}
	}
}



float Cashier::calculate_salary()
{
	return (160 * get_money_per_hour() + (get_hours() - 160) * (get_money_per_hour() + 5));
}

float Cashier::get_money_per_hour()
{
	return money_per_hour;
}

ostream& operator<<(ostream& os, Cashier emp)
{
	emp.print_employer();
	return os;
}