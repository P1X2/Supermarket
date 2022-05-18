#include "SalaryError.h"
#include <string>
SalaryError::SalaryError(float minimum, float maximum, string c,float wrong_salary) :
	invalid_argument("Salary of " + c + " cannot exceed "+to_string(maximum)+" and cannot be lower than "+to_string(minimum)+"salary given: "+to_string(wrong_salary)) {}