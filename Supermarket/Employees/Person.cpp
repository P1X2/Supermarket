#include "Person.h"
#include <stdexcept>


Person::Person(int id):id(id)
{
	busy = 0;
	
}

int Person::get_busy()
{
	return busy;
}

void Person::set_busy(int bus)
{
	if (bus >= 0)
	{
		busy = bus;
	}
}

bool Person::is_busy()
{
	return busy > 0;
}

int Person::get_id()
{
	return id;
}

bool Person::operator==(const Person emp)const {
	return (id == emp.id);
}