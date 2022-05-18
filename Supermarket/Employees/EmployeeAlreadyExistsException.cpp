#include "EmployeeAlreadyExistsException.h"


EmployeeAlreadyExistsException::EmployeeAlreadyExistsException() :
	invalid_argument("You cannot add employee that already exists") {}