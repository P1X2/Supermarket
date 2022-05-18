#pragma once
#include <stdexcept>
using namespace std;
class WorkingHoursError :public invalid_argument
{
public:
	WorkingHoursError(int);
};

