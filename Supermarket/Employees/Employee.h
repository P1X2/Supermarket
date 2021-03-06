#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "..\products\Product.h"
using namespace std;

class Employee :public Person 
{
	string name;
	string surname;
	int hours;
	vector<int> schedule;
	float money_per_hours;
public:
	Employee(string name, string surname, int work_hours, int iden);
	string get_name();
	string get_surname();
	vector<int> get_schedule();
	int get_hours();
	void set_hours(int);
	void calculate_schedule();
	void print_employer();
	virtual float calculate_salary();
	virtual void set_money_per_hour(float);
};
