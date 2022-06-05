#include "Person.h"
#include <stdexcept>


Person::Person()
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