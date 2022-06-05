#pragma once
#include <string>
using namespace std;
class Person
{
	int busy;
public:
	Person(); 
	void set_busy(int);
	int get_busy();
	bool is_busy();
};

