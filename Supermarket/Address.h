#pragma once
#include <string>
using namespace std;

class Address
{
	int house_number;
	string street, city, country;
public:
	Address(string country, string city, string street, int house_number);
	int get_house_number();
	string get_street();
	string get_city();
	string get_country();
};

