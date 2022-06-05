#include "Checkout.h"
#include <stdexcept>

Checkout::Checkout():checkout_cashier("empty", "empty",0,0,0)
{
}

Checkout::Checkout(Cashier checkout_cashier, bool is_open) :checkout_cashier(checkout_cashier), is_open(is_open)
{}

void Checkout::scan_product()
{
	int cs = current_shopping_cart_index;
	for (int i = current_shopping_cart_index; i < get_scanning_speed()+cs; i++)
	{
		try
		{
			current_cart_profit += current_client_shopping_cart[i].getPrice();
			current_shopping_cart_index++;

		}
		catch (exception)
		{
			break;
		}
		
	}
}

int Checkout::get_scanning_speed()
{
	return get_client_queue_lenght() * 2;
}

void Checkout::checkout_action()
{
	if (current_shopping_cart_index < current_client_shopping_cart.size())
	{
		scan_product();
	}
	else
	{
		current_shopping_cart_index = 0;
		//wystawia fakture
	}
	
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

int Checkout::get_client_queue_lenght()
{
	return client_queue.size();
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

bool Checkout::operator<(const Checkout& second_checkout) const
{
	return (client_queue.size() < second_checkout.client_queue.size());
}

ostream& operator<<(ostream& os, const Checkout& check)
{
	if (check.is_open)
	{
		os << "Cashier on checkout: " << check.checkout_cashier << " Number of clients in line: " << check.client_queue.size() << endl;
	}
	return os;
}