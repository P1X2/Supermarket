#pragma once
#include <string>
using namespace std;

class Adress
{
	int house_number;
	string street, city, country;
public:
	int get_house_number();
	string get_street();
	string get_city();
	string get_country();
};

