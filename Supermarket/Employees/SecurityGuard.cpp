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