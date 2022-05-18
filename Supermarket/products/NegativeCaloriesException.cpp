#include "NegativeCaloriesException.h"

NegativeCaloriesException::NegativeCaloriesException() :
	std::invalid_argument("Negative value of the base Calories ") {}