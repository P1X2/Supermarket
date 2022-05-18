#pragma once
#include <stdexcept>
class EmployeeAlreadyExistsException :
    public std::invalid_argument
{
public:
    EmployeeAlreadyExistsException();
};

