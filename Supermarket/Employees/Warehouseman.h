#pragma once

#include "Employee.h"
//#include "..\ProductShelve.h"
#include <vector>




class Warehouseman : public Employee
{
	float money_per_hour;
	//ProductShelve magazine;
	vector<Product> pocket;

public:
	Warehouseman(string, string, int, int, float);
	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	float get_money_per_hour();

	void serch_product(string surename, string product);
	void grab_product(map<Product, int> shop_shelve, map<Product, int>::iterator it);
	void empty_pocket();


};

