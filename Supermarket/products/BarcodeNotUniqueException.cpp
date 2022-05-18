#include "BarcodeNotUniqueException.h"

BarcodeNotUniqueException::BarcodeNotUniqueException() :
	std::invalid_argument("Product's barecode must be unique") {}