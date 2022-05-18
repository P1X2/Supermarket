#pragma once
#include <stdexcept>
using namespace std;
class SalaryError : public invalid_argument
{
public:
	SalaryError(float,float,string,float);
};

