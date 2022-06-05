#pragma once

#include "Employee.h"
#include <vector>




class Warehouseman : public Employee
{
	float money_per_hour;
	vector<Product> pocket;
	bool is_serching_prd;
	string searched_prd;
	string served_client;

public:
	Warehouseman(string, string, int, int, float);

	bool get_is_serching_prd();
	string get_searched_prd();

	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	float get_money_per_hour();

	void serch_product(string surename, string product); // uwaga tutaj moze sie pierolic
	void stop_searching();
	void add_prd_to_pocket(Product prd);
	void empty_pocket();

};

