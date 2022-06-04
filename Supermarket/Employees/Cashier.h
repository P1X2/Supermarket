#pragma once
#include "Employee.h"
#include <string>
class Cashier : public Employee
{
	float money_per_hour;
	bool on_checkout;
public:
	Cashier(string, string, int, int, float);
	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	float get_money_per_hour();
};

ostream& operator<<(ostream&, Cashier);