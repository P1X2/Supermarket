#pragma once
#include<list>
#include<iostream>
#include"Cashier.h"
using namespace std;
class RegisterCashiers
{
	vector<Cashier> employees;
public:
	void add_cashier(string, string, int, int, float);
	float count_salaries();
	int how_many_workers();
	bool in_register(int);
	void remove_employee(int);
	void print_employees();
	void pass_time_unit();
};

