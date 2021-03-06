#include "Supermarket.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <cstdlib>

#pragma once

void Supermarket::load_registers()
{
	generate_employees();
	generate_client(rng_machine.generate_random_number(10,30));
}

void Supermarket::generate_employees()
{
	int flag1 = 0;
	int checkout_id = 1;

	for (int i = 1; i <= rng_machine.generate_random_number(2, 10); i++)
	{
		string name = rng_machine.random_string_vector_element(file_reader.names);
		string surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int hours = rng_machine.generate_random_number(161, 319);
		float money_per_hour = rng_machine.generate_random_number(15, 40);
		cashiers.add_cashier(name, surname, hours, i, money_per_hour);
		if (flag1 == 0)
		{
			checkouts.push_back(Checkout(Cashier(name, surname, hours, i, money_per_hour), true,checkout_id));
			flag1 += 1;
			checkout_id++;
		}
		else
		{
			checkouts.push_back(Checkout(Checkout(Cashier(name, surname, hours, i, money_per_hour), false,checkout_id)));
			checkout_id++;
		}



	}
	for (int j = 1; j <= rng_machine.generate_random_number(1, 50); j++)
	{
		string name = rng_machine.random_string_vector_element(file_reader.names);
		string surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int hours = rng_machine.generate_random_number(161, 319);
		float money_per_hour = rng_machine.generate_random_number(5, 20);
		warehousemen.add_warehouseman(name, surname, hours, j + 4, money_per_hour);
	}
}

void Supermarket::randomly_generate_client(int percent)
{
	if (rng_machine.generate_random_number(1, 101) <= percent)
	{
		generate_client();
	}
}


void Supermarket::generate_client(int number_to_generate)
{
	string name;
	string surname;
	vector<string>shopping_list;
	int reccp;
	bool recipe;
	for (int i = 1; i <= number_to_generate; i++)
	{
		shopping_list.clear();
		name = rng_machine.random_string_vector_element(file_reader.names);
		surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int shop_cart_len = rng_machine.generate_random_number(3, 5);
		for (int k = 1; k <= shop_cart_len; k++)
		{
			string product = products[rng_machine.generate_random_number(0, products.size() - 1)].getName();
			shopping_list.push_back(product);
		}
		recipe = rng_machine.generate_random_number(0, 2); 
		Address sa = file_reader.addresses[rng_machine.generate_random_number(0, file_reader.addresses.size() - 1)];
		last_client_id++;
		Client client(name, surname,last_client_id, shopping_list,
			sa, recipe);

		client.set_activity("Enter");
		file_reader.write_client_to_simulation_file(client);
		cout << client;

		Sleep(300);
		clients.add_client(client);

	}
}

Supermarket::Supermarket(string products_path, string names_surnames_path, string addresses_path)
{
	try
	{
		products = file_reader.load_products(products_path);
		file_reader.load_names_surnames(names_surnames_path);
		file_reader.load_addresses(addresses_path);
	}
	catch (const FileReadError e)
	{
		cout << "Caught an exception FileReadError" << endl << e.what() << endl;
	}

	Product Ghost("", "", "", 0, 0);
	vector<Product>::iterator it = products.begin();
	shop_shelve.set_inventory(products, rng_machine.random_numbers_vector(2, 3, products.size())); 
	products.insert(it, Ghost);
	magazine.set_inventory(products, rng_machine.random_numbers_vector(3, 5, products.size()));
	vector<Product>::iterator it2 = products.begin();
	products.erase(it2);
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//																	 Simulation functions
// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void Supermarket::do_shopping() //1
{
	vector<Client> to_delete;

	for (vector<Client>::iterator it = clients.clients.begin(); it != clients.clients.end(); it++)
	{

		if (it->get_is_done() == true) 
		{
			vector<Checkout>::iterator best_checkout;
			int min_queue = 9999999;
			for (vector<Checkout>::iterator it2 = checkouts.begin(); it2 != checkouts.end(); it2++)
			{
				if (it2->get_client_queue_lenght() <= min_queue && it2->is_open == true)
				{
					best_checkout = it2;
					min_queue = it2->get_client_queue_lenght();
				}
			}
			best_checkout->add_client_to_queue(*it);
			to_delete.push_back(*it);
			continue;

		}
		if (it->get_is_w8ting() == true)
		{
			continue; 
		}
		else 
		{
			int flag = it->serch_product(shop_shelve);
			if (flag == 1)
			{
				it->ask_question__is_in_stock(warehousemen); 
			}
			else if (flag == 0)
			{

			}
			else
			{
				continue;
			}

		}
	}

	for (int i = 0; i != to_delete.size(); i++)
	{
		for (vector<Client>::iterator it = clients.clients.begin(); it != clients.clients.end(); it++)
		{
			int index = 0;
			if (*it == to_delete[index])
			{
				clients.clients.erase(it);
				index++;
				break;
			}
		}
	}

}

void Supermarket::go_to_magazine()
{
	magazine.who_is_looking_for_prd(warehousemen);
}

void Supermarket::give_prd_to_client()
{
	for (vector<Warehouseman>::iterator it = warehousemen.employees.begin(); it != warehousemen.employees.end(); it++)
		if (it->pocket.size() == 1)
		{
			for (vector<Client>::iterator it2 = clients.clients.begin(); it2 != clients.clients.end(); it2++)
			{
				if (it2->get_id() == it->served_client)
				{
					if (it->pocket[0].getName() == "") 
					{
						it2->is_w8ting_end();
						it->empty_pocket();
						break;
					}
					else
					{
						it2->grab_product_from_emplyee(it->pocket[0]);
						it2->is_w8ting_end();
						it->empty_pocket();
						break;
					}
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			continue;
		}

}

void Supermarket::opening_checkouts() 
{
	int clients_checkout_sum = 0, opened_checkouts = 0;

	for (vector<Checkout>::iterator it = checkouts.begin(); it != checkouts.end(); it++)
	{
		if (it->is_open)
		{
			clients_checkout_sum = +it->client_queue.size();
			opened_checkouts += 1;
		}
	}

	float new_checkout_condition = clients_checkout_sum / opened_checkouts;
	if (new_checkout_condition >= 3)
	{
		if (opened_checkouts == checkouts.size())
		{
		}
		else
		{
			checkouts[opened_checkouts].assign_cashier();
		}
	}

}

void Supermarket::scan_products()
{
	for (vector<Checkout>::iterator it = checkouts.begin(); it != checkouts.end(); it++)
	{
		if (it->client_queue.size() == 0)
		{
			continue;
		}
		else
		{
			it->checkout_action();
		}

	}

}

void Supermarket::simulation(int iterations)
{
	int it = 0;
	while (it<=iterations)
	{

		do_shopping();
		go_to_magazine();
		give_prd_to_client();
		opening_checkouts();
		scan_products();

		int i = rng_machine.generate_random_number(2, 4);
		for (int w = 0; w != i; w++)
		{
			int chance = rng_machine.generate_random_number(15,30);
			randomly_generate_client(chance);
		}

		it++;
	}


}