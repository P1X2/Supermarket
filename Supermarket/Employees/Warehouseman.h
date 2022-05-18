#pragma once
#include "Employee.h"
class Warehouseman : public Employee
{
	float money_per_hour;
public:
	Warehouseman(string, string, int, int, float);
	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	virtual void print_schedule() override;
	float get_money_per_hour();
};

