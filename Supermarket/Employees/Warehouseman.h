#pragma once

#include "Employee.h"
#include"..\Client.h"


class Warehouseman : public Employee
{
	float money_per_hour;
public:
	Warehouseman(string, string, int, int, float);
	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	float get_money_per_hour();

	Product serch_product(Client client);
};

