#pragma once
#include <stdexcept>
class EmployeeDoesNotExistException : public std:: invalid_argument
{
public:
	EmployeeDoesNotExistException();
};

