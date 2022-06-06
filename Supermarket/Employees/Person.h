#pragma once
#include <string>
using namespace std;
class Person
{
	int busy;
	int id;
public:
	Person(int id);
	void set_busy(int);
	int get_busy();
	bool is_busy();
	int get_id();
	bool operator==(const Person person2)const;
};

