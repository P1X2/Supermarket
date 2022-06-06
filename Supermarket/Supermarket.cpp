#include "Supermarket.h"

#pragma once

void Supermarket::simulation(int iterations)
{
	
	/*vector<Product> xd;
	
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
	security_guards.print_employees();*/
	generate_employees();
	generate_client(20);
	/*for (Client cl : clients.get_clients())
	{
		cout << cl.get_name() << " " << cl.get_surename() << " "<<cl.get_adress() << endl;
	}*/
	//while (iterations<++i)
	//{
	//	
	//}
}

void Supermarket::generate_employees()
{
	int flag1 = 0; 

	for (int i=1;i<=rng_machine.generate_random_number(2, 10);i++)
	{
		string name = rng_machine.random_string_vector_element(file_reader.names);
		string surname = rng_machine.random_string_vector_element(file_reader.surnames);
		int hours = rng_machine.generate_random_number(161, 319);
		float money_per_hour = rng_machine.generate_random_number(15, 40);
		cashiers.add_cashier(name,surname,hours,i,money_per_hour);
		if (flag1 == 0)
		{
			checkouts.push_back(Checkout(Cashier(name, surname, hours, i, money_per_hour),true));
			flag1 += 1;
		}
		else 
		{
			checkouts.push_back(Checkout(Checkout(Cashier(name, surname, hours, i, money_per_hour), false)));
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
	for (int j = 1; j <= rng_machine.generate_random_number(1, 50); j++)
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
		for (int k = 1; k <= shop_cart_len; k++)
		{
			string product = products[rng_machine.generate_random_number(0, products.size()-1)].getName();
			shopping_list.push_back(product);
		}
		recipe = rng_machine.generate_random_number(0,2); // impostor wojtas
		Address sa = file_reader.addresses[rng_machine.generate_random_number(0, file_reader.addresses.size()-1)];
		Client client(name, surname, shopping_list,
			sa, recipe);
		clients.add_client(client);
		
	}
}

Supermarket::Supermarket(string products_path,string names_surnames_path,string addresses_path)
{
	try
	{
		products=file_reader.load_products(products_path);
		file_reader.load_names_surnames(names_surnames_path);
		file_reader.load_addresses(addresses_path);
	}
	catch (const FileReadError e)
	{
		cout << "Caught an exception FileReadError" << endl << e.what() << endl;
	}
	shop_shelve.set_inventory(products, rng_machine.random_numbers_vector(1, 5, products.size())); // pierwszy produkt musi byc WIDMEMMMMMMMMMMMMMMMMMMM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	magazine.set_inventory(products, rng_machine.random_numbers_vector(2, 4, products.size()));
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//          Simulation functions
// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






void Supermarket::do_shopping() //1
{
	vector<Client> to_delete;

	for (vector<Client>::iterator it = clients.clients.begin(); it != clients.clients.end(); it++)
	{

		if (it->get_is_done() == true) // idzie do kasy
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
				//clients.clients.erase(it); // tutaj sie perdoli dorobic usuwanie koniecznie !!!!!!!!!!!!!!!!!!!!!!!
			continue;

		}
		if (it->get_is_w8ting() == true)
		{
			continue; // czeka na pracownika
		}
		else // szuka prd
		{
			int flag = it->serch_product(shop_shelve);
			if (flag == 1)
			{
				it->ask_question__is_in_stock(warehousemen);
			}
			if (flag == 0)
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

void Supermarket::go_to_magazine() // 2
{
	magazine.who_is_looking_for_prd(warehousemen);
}

void Supermarket::give_prd_to_client() // 3
{
	for (vector<Warehouseman>::iterator it = warehousemen.employees.begin(); it != warehousemen.employees.end(); it++)
		if (it->pocket.size() == 1)
		{
			for (vector<Client>::iterator it2 = clients.clients.begin(); it2 != clients.clients.end(); it2++)
			{
				if (it2->get_surename() == it->served_client)
				{
					if (it->pocket[0].getName() == "")
					{
						it2->is_w8ting_end();
						it2->update_currently_serched_product();
						it->empty_pocket();
					}
					else
					{
						it2->grab_product_from_emplyee(it->pocket[0]);
						it2->is_w8ting_end();
						it2->update_currently_serched_product();
						it->empty_pocket();
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

void Supermarket::opening_checkouts() //4
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
	if (new_checkout_condition >= 6)
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

void Supermarket::scan_products() // 5
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

