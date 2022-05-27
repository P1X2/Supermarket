#include "Supermarket.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Supermarket::Supermarket()
{
	Register employees;
}

void Supermarket::load_eployees(string path)
{
	ifstream handle;
	handle.open(path);
	while (handle.good())
	{
		string line;
		getline(handle, line);
		string job;
		string name;
		string surname;
		int hours;
		int id;
		float money_per_hour;
}