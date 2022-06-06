#pragma once

#include "Employee.h"
#include <vector>
#include "..\RNG.h"




class Warehouseman : public Employee
{
	float money_per_hour;
	vector<Product> pocket;

	bool is_serching_prd;

	string searched_prd;
	string served_client;
	RNG RNG;

public:
	Warehouseman(string, string, int, int, float);

	bool get_is_serching_prd();
	string get_searched_prd();
	string action;

	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	float get_money_per_hour();

	void serch_product(string surename, string product); // uwaga tutaj moze sie pierolic
	void stop_searching();
	void add_prd_to_pocket(Product prd);
	void empty_pocket();

	void go_to_magazine();
	void gave_to_client();

	friend class Supermarket_sandbox;
	friend class Supermarket;

	friend ostream& operator<<(ostream& os, const Warehouseman emp);
};

ostream& operator<<(ostream& os, const Warehouseman emp);