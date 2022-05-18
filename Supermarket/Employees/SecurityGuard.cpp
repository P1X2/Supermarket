#include "SecurityGuard.h"
#include "SalaryError.h"

SecurityGuard::SecurityGuard(string n, string sur, int h, int iden, float mon) :
	Employee(n, sur, h, iden) {
	set_money_per_hour(mon);
}

void SecurityGuard::set_money_per_hour(float money)
{
	if (money > 40 or money < 10)
		throw SalaryError(40, 10, "SecurityGuard", money);
	else money_per_hour = money;
}

void SecurityGuard::print_schedule()
{
	vector<int> bufor = get_schedule();
	cout << "Schedule: ";
	for (int i = 1; i < 7; i++)
	{
		switch (i)
		{
		case 1:
			cout << "Monday: 9-" << bufor[i - 1] + 9 << ", ";
			break;
		case 2:
			cout << "Tuesady: 9-" << bufor[i - 1] + 9 << ", ";
			break;
		case 3:
			cout << "Wednesday: 9-" << bufor[i - 1] + 9 << ", ";
			break;
		case 4:
			cout << "Thursday : 9-" << bufor[i - 1] + 9 << ", ";
			break;
		case 5:
			cout << "Friday: 9-" << bufor[i - 1] + 9 << ", ";
			break;
		case 6:
			cout << "Saturday: 9-" << bufor[i - 1] + 9 << ", ";
			break;
		default:
			break;
		}
	}
}



float SecurityGuard::calculate_salary()
{
	return (160 * get_money_per_hour() + (get_hours() - 160) * (get_money_per_hour() + 7));
}

float SecurityGuard::get_money_per_hour()
{
	return money_per_hour;
}

ostream& operator<<(ostream& os, SecurityGuard emp)
{
	emp.print_employer();
	return os;
}