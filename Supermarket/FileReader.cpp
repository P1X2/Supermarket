#include "FileReader.h"
#include <string>
#include <fstream>
#include <sstream>
#include<iostream>
#include"RNG.h"
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
					throw FileReadError(path, j);
				}
			}
		}
		handle.close();
	}
	cout << names.size() << endl;
	cout << surnames.size() << endl;
}

vector<Product> FileReader::load_products(string path)
{
	RNG barcode_generator;
	vector<Product> products;
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
				
				int price;
				int calories;
				int i = 0;
				
				
				while (getline(ss, item, ','))
				{
					string barcode="";
					int k;
					for (k = 1; k <= 10; k++)
					{
						barcode = barcode + to_string(barcode_generator.generate_random_number(0, 9));
					}
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
						price = stoi(item);
						break;
					case 5:
						calories = stoi(item);
						break;
					case 6:
						if (product == "juice")
						{
							int suger_per_100=stoi(item);
							Juice juice(name, price, calories, producer, barcode, suger_per_100);
							products.push_back(juice);
							break;
						}
						else if (product == "fruit")
						{
							string origin_country = item;
							Fruit fruit(name, price, calories, producer, barcode, origin_country);
							products.push_back(fruit);
							break;
						}
						else if (product == "meat")
						{
							string animal_origin = item;
							Meat meat(name, price, calories, producer, barcode, animal_origin);
							products.push_back(meat);
							break;
						}
						else if (product == "whiskey")
						{
							int alcohol_percent = stoi(item);
							Whiskey whiskey(name, price, calories, producer, barcode, alcohol_percent);
							products.push_back(whiskey);
							break;
						}
						}
			
					}
				if (i != 6)
				{
					throw FileReadError(path, j);
				}
				}
			}
	handle.close();
	return products;
}

void FileReader::load_addresses(string path)
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
			string country;
			string city;
			string street;
			int house_number;
			int i = 0;
			while (getline(ss, item, ' '))
			{
				i++;
				switch (i)
				{
				case 1:
					country = item;
					break;
				case 2:
					city = item;
					break;
				case 3:
					street = item;
					break;
				case 4:
					house_number = stoi(item);
					break;
				}
			}
			
			if (i != 4)
			{
					throw FileReadError(path, j);
			}
			Address adr(country, city, street, house_number);
			addresses.push_back(adr);
		}
		handle.close();
	}
	
}



void FileReader::write_to_file()
{
	fstream handle;
	handle.open("bills.txt", ios::out);
	if (handle.good())
	{
		
	}
}