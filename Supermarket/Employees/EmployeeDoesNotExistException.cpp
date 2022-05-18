#include "EmployeeDoesNotExistException.h"

EmployeeDoesNotExistException::EmployeeDoesNotExistException() :
	invalid_argument("There is no employee with such id in register") {}