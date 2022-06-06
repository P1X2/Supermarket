#pragma once

#include "Employee.h"
#include "..\products\Product.h"
#include <vector>
#include "..\RNG.h"




class Warehouseman : public Employee
{
	float money_per_hour;
	vector<Product> pocket;

	bool is_serching_prd;

	string searched_prd;
	int served_client;
	RNG RNG;

public:
	Warehouseman(string, string, int, int, float);

	bool get_is_serching_prd();
	string get_searched_prd();
	int get_client_id();

	virtual float calculate_salary() override;
	virtual void set_money_per_hour(float) override;
	float get_money_per_hour();

	void serch_product(int id, string product); // uwaga tutaj moze sie pierolic
	void stop_searching();
	void add_prd_to_pocket(Product prd);
	void empty_pocket();


	friend class Supermarket_sandbox;
	friend class Supermarket;

	friend ostream& operator<<(ostream& os, Warehouseman& emp);
};

