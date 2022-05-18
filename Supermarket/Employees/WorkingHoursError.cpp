#include "WorkingHoursError.h"
#include <string>


WorkingHoursError::WorkingHoursError(int wrong_hours) :
	invalid_argument("Minimum working hours is 160, maximum is 320, " + to_string(wrong_hours)+" is a wrong value") {}
