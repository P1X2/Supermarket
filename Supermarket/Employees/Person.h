#pragma once
class Person
{
	int busy;
	Supermarket supermarket;
public:
	Person(); // zrobic kostruktor z supermarketem
	void set_busy(int);
	int get_busy();
	bool is_busy();
};

