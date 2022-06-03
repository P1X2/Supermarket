#include "Checkout.h"

Checkout::Checkout(Cashier checkout_cashier) :checkout_cashier(checkout_cashier)
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
