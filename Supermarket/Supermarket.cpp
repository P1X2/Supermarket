#include "Supermarket.h"

#pragma once

void Supermarket::simulation(int iterations)
{
	
	vector<Product> xd;
	
	for (Address adr : file_reader.addresses)
	{
		cout << adr << endl;
	}
	for (Product pr : xd)
	{
		cout<<pr.getName()<<"  "<<pr.getBarcode() << endl;
	}
	
	generate_employees();
	int i = 0;
	cashiers.print_employees();
	warehousemen.print_employees();
	security_guards.print_employees();
	generate_client(20);
	for (Client cl : clients.get_clients())
	{
		cout << cl.get_name() << " " << cl.get_surename() << " "<<cl.get_adress() << endl;
	}
	while (iterations<++i)
	{
		
	}
}

void Supermarket::generate_employees()
{
	for (int i=1;i<rng_machine.generate_random_number(1, 10);i++)
	{
		string name = rng_machine.random_string_vector_element(file_reader.names);
		string surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int hours = rng_machine.generate_random_number(160, 320);
		float money_per_hour = rng_machine.generate_random_number(15, 40);
		cashiers.add_cashier(name,surname,hours,i,money_per_hour);
	}
	for (int j = 1; j < rng_machine.generate_random_number(1, 50); j++)
	{
		string name = rng_machine.random_string_vector_element(file_reader.names);
		string surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int hours = rng_machine.generate_random_number(160, 320);
		float money_per_hour = rng_machine.generate_random_number(5, 20);
		warehousemen.add_warehouseman(name, surname, hours, j + 4, money_per_hour);
	}
	for (int j = 1; j < rng_machine.generate_random_number(1, 50); j++)
	{
		string name = rng_machine.random_string_vector_element(file_reader.names);
		string surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int hours = rng_machine.generate_random_number(160, 320);
		float money_per_hour = rng_machine.generate_random_number(500, 1000);
		security_guards.add_security_guard(name, surname, hours, j + 4, money_per_hour);
	}
}

void Supermarket::generate_client(int number_to_generate)
{
	string name;
	string surname;
	vector<string>shopping_list;
	int reccp;
	bool recipe;
	for (int i = 1; i < number_to_generate; i++)
	{
		shopping_list.clear();
		name = rng_machine.random_string_vector_element(file_reader.names);
		surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int shop_cart_len = rng_machine.generate_random_number(1, 20);
		for (int k = 1; k < shop_cart_len; k++)
		{
			string product = products[rng_machine.generate_random_number(0, products.size()-1)].getName();
			shopping_list.push_back(product);
		}
		recipe = rng_machine.generate_random_number(0,1);
		Address sa = file_reader.addresses[rng_machine.generate_random_number(0, file_reader.addresses.size()-1)];
		Client client(name, surname, shopping_list,
			sa, recipe);
		clients.add_client(client);
		
	}
}

Supermarket::Supermarket(string products_path,string names_surnames_path,string addresses_path) :
	products(file_reader.load_products(products_path)),
	shop_shelve(products, rng_machine.random_numbers_vector(1, 3, products.size())),
		magazine(products, rng_machine.random_numbers_vector(1, 3, products.size()))
{
	try
	{
		file_reader.load_names_surnames(names_surnames_path);
		file_reader.load_addresses(addresses_path);
	}
	catch (const FileReadError e)
	{
		cout << "Caught an exception FileReadError" << endl << e.what() << endl;
	}
}