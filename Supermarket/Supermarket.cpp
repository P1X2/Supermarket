#include "Supermarket.h"

#pragma once

void Supermarket::simulation(int iterations)
{
	file_reader.load_names_surnames("names.txt");
	vector<Product> xd;
	try
	{
		xd = file_reader.load_products("products.txt");
	}
	catch (const FileReadError e)
	{
		cout << "Caught an exception FileReadError" << endl << e.what() << endl;
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
	for (int i = 1; i < number_to_generate; i++)
	{
		
	}
}
