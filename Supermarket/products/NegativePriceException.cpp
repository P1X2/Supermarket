#include "NegativePriceException.h"


NegativePriceException::NegativePriceException() :
	std::invalid_argument("Negative value of the base price ") {}
