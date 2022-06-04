#include "Checkout.h"

Checkout::Checkout(Cashier checkout_cashier, bool is_open) :checkout_cashier(checkout_cashier), is_open(is_open)
{}

void Checkout::scan_product()
{
	// zaimplementowaæ czekanko
}


int Checkout::total()
{
	int total = 0;
	for (vector<Product>::iterator it = current_client_shopping_cart.begin(); it != current_client_shopping_cart.end(); it++)
	{
		total = total + it->getPrice();
	}
	return total;
}

void Checkout::release_cashier()
{
	is_open = false;
}

void Checkout::assign_cashier()
{
	is_open = true;
}

void Checkout::update_CCSC()
{
	current_client_shopping_cart = client_queue[0].get_shopping_cart();
}

void Checkout::update_profit()
{
	profit += total();
}

void Checkout::add_client_to_queue(Client client)
{
	client_queue.push_back(client);
}
