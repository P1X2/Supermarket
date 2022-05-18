#include "ProductNotFoundException.h"


ProductNotFoundException::ProductNotFoundException() :
	std::invalid_argument("Product not found [invaild barcode]") {}

