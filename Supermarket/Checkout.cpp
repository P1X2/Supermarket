#include "Checkout.h"
#include <stdexcept>

Checkout::Checkout():checkout_cashier("empty", "empty",0,0,0), is_open(false),id(0)
{
}

Checkout::Checkout(Cashier checkout_cashier, bool is_open,int id) :checkout_cashier(checkout_cashier), is_open(is_open),id(id)
{}

Cashier Checkout::get_cashier()
{
	return checkout_cashier;
}

void Checkout::set_cashier_activity(string activity)
{
	checkout_cashier.set_activity(activity);
}

int Checkout::scan_product()
{
	int prd_left_to_scan = (current_client_shopping_cart.size()) - (current_shopping_cart_index );
	if (prd_left_to_scan < this->get_scanning_speed())
	{
		int krk = current_client_shopping_cart.size() - (current_shopping_cart_index);
		int index = current_shopping_cart_index;

		for (int i = index; i < krk+index; i++)
		{
			current_cart_profit += current_client_shopping_cart[i].getPrice();
			profit += current_cart_profit;
			current_shopping_cart_index++;
			if (i = krk + current_shopping_cart_index - 1)
			{
				reset_CSCI();
				return 1;
			}
		}
	}
	else
	{
		int index = current_shopping_cart_index;
		for (int i = index; i < get_scanning_speed() + index; i++) // impostor wojtaz
		{
			current_cart_profit += current_client_shopping_cart[i].getPrice(); // error
			current_shopping_cart_index++;
		}
		return 0;
	}
	
}

int Checkout::get_scanning_speed()
{
	return get_client_queue_lenght() * 2;
}

void Checkout::checkout_action()
{
	current_client_shopping_cart = client_queue[0].get_shopping_cart();
	int flag = scan_product();

	if (flag == 1)
	{
		if (client_queue[0].get_recipe() == true)
		{
			recipe(client_queue[0]);
			vector<Client>::iterator it = client_queue.begin();
			client_queue.erase(it);
		}
		else
		{
			invoice(client_queue[0]);
			vector<Client>::iterator it = client_queue.begin();
			vector<Client>::iterator it2 = client_queue.erase(it);
		}
	}
	else
	{
		return;
	}
	
}




int Checkout::get_client_queue_lenght()
{
	return client_queue.size();
}

void Checkout::reset_CSCI()
{
	current_shopping_cart_index = 0;
	current_cart_profit = 0;
}

void Checkout::release_cashier()
{
	is_open = false;
}

void Checkout::assign_cashier()
{
	is_open = true;
}

void Checkout::recipe(Client cl)
{
}

void Checkout::invoice(Client cl)
{
}

void Checkout::update_CCSC()
{
	current_client_shopping_cart = client_queue[0].get_shopping_cart();
}

void Checkout::add_client_to_queue(Client client)
{
	client_queue.push_back(client);
}

bool Checkout::operator<(const Checkout& second_checkout) const
{
	return (client_queue.size() < second_checkout.client_queue.size());
}

ostream& operator<<(ostream& os, Checkout& check)
{
	if (check.get_cashier().get_activity() == "done scanning client")
	{
		os << "Cashier on checkout " << check.id << " served client " << check.client_queue[0].get_name() << " " << check.client_queue[0].get_surname() << endl;
		os << "The total is " << check.current_cart_profit << "\n\n";
	}
	else if (check.get_cashier().get_activity() == "scanning client")
	{
		os << "Cashier on checkout " << check.id << " served client " << check.client_queue[0].get_name()<<" " << check.client_queue[0].get_surname() << endl;
	}
	else if (check.get_cashier().get_activity() == "opened")
	{
		os <<"Checkout with id " << check.id << " has just opened" <<endl;
	}
	return os;
}