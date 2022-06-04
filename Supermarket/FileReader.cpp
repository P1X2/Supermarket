#include "FileReader.h"
#include <string>
#include <fstream>
#include <sstream>
#include<iostream>
using namespace std;



void FileReader::load_names_surnames(string path)
{
	
	fstream handle;
	int j = 0;
	handle.open(path,ios::in);

	if (handle.good())
	{
		string line;
		while (getline(handle, line))
		{
			j++;

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

void FileReader::load_products(string path)
{
	fstream handle;
	int j = 0;
	handle.open(path, ios::in);
	if (handle.good())
	{
		string line;
		while (getline(handle, line))
		{
			j++;
			stringstream ss(line);
			string item;
			string product;
			string name;
			string producer;
			string barcode;
			int price;
			int calories;
			int i = 0;
			while (getline(ss, item, ','))
			{
				i++;
				switch (i)
				{
				case 1:
					product = item;
					break;
				case 2:
					name = item;
					break;
				case 3:
					producer = item;
					break;
				case 4:
					barcode = item;
					break;
				case 5:
					price = stoi(item);
					break;
				case 6:
					calories = stoi(item);
					break;
				
				case 7:
					if (product == "juice")
					{
						int suger_per_100=stoi(item);
						//Dodaj do database
						break;
					}
					else if (product == "fruit")
					{
						string orgin_country = item;
						//Dodaj do database
						break;
					}
					else if (product == "meat")
					{
						string animal_origin = item;
						//Dodaj do database
						break;
					}
					else if (product == "whiskey")
					{
						int alcohol_percent = stoi(item);
						//Dodaj do database
						break;
					}
					}
				}
			}
		}
	handle.close();
	}
