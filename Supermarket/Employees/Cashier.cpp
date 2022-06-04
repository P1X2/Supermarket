#include "Cashier.h"
#include "SalaryError.h"

Cashier::Cashier(string n, string sur, int h,int iden, float mon) :
	Employee(n, sur,h,iden) {
	set_money_per_hour(mon);
}

void Cashier::set_money_per_hour(float money)
{
	if (money > 40 or money < 15)
		throw SalaryError(5, 30, "cashier", money);
	else money_per_hour = money;
}

float Cashier::calculate_salary()
{
	return (160 * get_money_per_hour() + (get_hours() - 160) * (get_money_per_hour() + 7));
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