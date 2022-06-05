#include "Supermarket_sandbox.h"
#include "Supermarket.h"

#pragma once


	


void Supermarket_sandbox::do_shopping() //1
{
	for (vector<Client>::iterator it = clients.clients.begin(); it != clients.clients.end(); it++)
	{
		if (it->get_is_done() == true)
		{
			Checkout best_checkout;
			int min_queue = 9999999;
			for (vector<Checkout>::iterator it2 = checkouts.begin(); it2 != checkouts.end(); it++)
			{
				if (it2->get_client_queue_lenght() <= min_queue)
				{
					best_checkout = *it2;
				}
				best_checkout.add_client_to_queue(*it);
				clients.clients.erase(it);
				return;
			}
		}
		else
		{
			int flag = it->serch_product(shop_shelve);
			if (flag == 1)
			{
				it->ask_question__is_in_stock(warehousemen);
			}
		}
	}
}

void Supermarket_sandbox::go_to_magazine() //2
{
	magazine.who_is_looking_for_prd(warehousemen);
}

void Supermarket_sandbox::give_prd_to_client() // 3
{
	for (vector<Warehouseman>::iterator it = warehousemen.employees.begin(); it != warehousemen.employees.end(); it++)
		if (it->pocket.size() == 1)
		{
			for (vector<Client>::iterator it2 = clients.clients.begin(); it2 != clients.clients.end(); it2++)
			{
				if (it2->get_surename() == it->served_client)
				{
					it2->grab_product_from_emplyee(it->pocket[0]);
					it->empty_pocket();
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








