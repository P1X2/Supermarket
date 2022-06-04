#include "Warehouseman.h"
#include "SalaryError.h"

Warehouseman::Warehouseman(string n, string sur, int h, int iden, float mon) :
	Employee(n, sur, h, iden) {
	set_money_per_hour(mon);
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

//Product Warehouseman::serch_product(Client client)
//{
//	
//}

ostream& operator<<(ostream& os, Warehouseman emp)
{
	emp.print_employer();
	return os;
}