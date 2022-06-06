#include "Employee.h"
#include "WorkingHoursError.h"
using namespace std;

Employee::Employee(string n, string sur, int h,int iden):
	Person(iden)
{
	name = n;
	surname = sur;
	set_hours(h);
	vector<int> schedule{};
	calculate_schedule();
}

string Employee::get_name()
{
	return name;
}

string Employee::get_surname()
{
	return surname;
}

int Employee::get_hours()
{
	return hours;
}

void Employee::set_hours(int new_hours)
{
	if (new_hours < 160 or new_hours>320)
	{
		//throw WorkingHoursError(new_hours); // symka changes
	}
	else hours = new_hours;
}

void Employee::calculate_schedule()
{
	int daily = get_hours() / 24;
	int xd = get_hours() % 6;
	for (int i = 1; i <= 6; i++)

	{
		if (get_hours() % 6 > i && get_hours() % 6 != 0)
			schedule.push_back(daily + 1);
		else
			schedule.push_back(daily);
	}
}

vector<int> Employee::get_schedule()
{
	return schedule;
}

void Employee::print_employer()
{
	cout << "Name: " << get_name() << " " << get_surname();
	cout << "   Salary: " << calculate_salary() << endl;
}





float Employee::calculate_salary() { return 0; }

void Employee::set_money_per_hour(float) {}


