#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class Employee :public Person 
{
	string name;
	string surname;
	int hours;
	vector<int> schedule;
	float money_per_hours;
	int id;
public:
	Employee(string, string, int, int);
	string get_name();
	string get_surname();
	int get_id();
	vector<int> get_schedule();
	int get_hours();
	void set_hours(int);
	void calculate_schedule();
	void print_employer();
	bool operator==(const Employee) const;
	virtual float calculate_salary();
	virtual void set_money_per_hour(float);
};
