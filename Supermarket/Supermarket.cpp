#include "Supermarket.h"
#include <string>
#include <fstream>
#include <sstream>
#include<iostream>
using namespace std;

Supermarket::Supermarket()
{
	Register employees;
	vector<string>names;
	vector<string>surnames;
}

void Supermarket::load_names_surnames(string path)
{
	
	fstream elsa,handle,xdxd;
	
	//elsa.open("names.txt", ios::out);
	string name;
	string surname;	
	int j = 0;
	/*if (elsa.is_open())
	{
		elsa << "xDXXDXD\n";
		elsa << "xsdafsda";
		elsa.close();
	}
	xdxd.open("names.txt", ios::in);
	if (xdxd.good())
	{
		while (getline(xdxd, name))
		{
			cout << name << endl;
		}
		xdxd.close();
	}*/
	handle.open("names.txt",ios::in);

	if (handle.good())
	{
		string line;
		while (getline(handle, line))
		{
			j++;
			cout << line << endl;

			stringstream ss(line);
			string item;
			int i = 0;
			while (getline(ss, item, ' '))
			{
				i++;
				switch (i)
				{
				case 1:
					names.push_back(item);
					break;
				case 2:
					surnames.push_back(item);
					break;
				default:
					throw FileReadError("names and surnames", j);
				}
			}
		}
		handle.close();
	}
	
	
	
	cout << names.size() << endl;
	cout << surnames.size() << endl;
	
}
