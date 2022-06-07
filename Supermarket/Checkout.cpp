#include "Checkout.h"
#include <stdexcept>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <cstdlib>
#include "FileReader.h"



Checkout::Checkout():checkout_cashier("empty", "empty",0,0,0), is_open(false),id(0)
{
}

Checkout::Checkout(Cashier checkout_cashier, bool is_open,int id) :checkout_cashier(checkout_cashier), is_open(is_open),id(id)
{

	set_cashier_activity("opened");
}

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
	set_cashier_activity("scanning client");
	cout << *this;
	FileReader writer;
	writer.write_checkout_to_simulation_file(*this);
	int prd_left_to_scan = (current_client_shopping_cart.size()) - (current_shopping_cart_index );
	if (prd_left_to_scan < this->get_scanning_speed())
	{
		int krk = current_client_shopping_cart.size() - (current_shopping_cart_index);
		int index = current_shopping_cart_index;

		if (krk == 0)
		{
			set_cashier_activity("done scanning client");
			cout << *this;
			FileReader writer;
			writer.write_checkout_to_simulation_file(*this);
			vector<Product> prod = client_queue[0].get_shopping_cart();
			Recipe rec(prod);
			rec.operator<<(cout);
			writer.write_recipe_to_file(rec);
			
			reset_CSCI();
			return 1;
		}

		for (int i = index; i < krk+index; i++)
		{
			current_cart_profit += current_client_shopping_cart[i].getPrice();
			profit += current_cart_profit;
			current_shopping_cart_index++;
			if (i = krk + current_shopping_cart_index - 1)
			{
				set_cashier_activity("done scanning client");
				cout << *this;
				FileReader writer;
				writer.write_checkout_to_simulation_file(*this);
				string name = client_queue[0].get_name();
				string surname = client_queue[0].get_surname();
				Address adr = client_queue[0].address;
				vector<Product> prod = client_queue[0].get_shopping_cart();
				Invoice inv(name, surname, adr, prod);
				inv.operator<<(cout);
				writer.write_invoice_to_file(inv);
				
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
			FileReader writer;
			checkout_cashier.set_activity("recipe");
			cout << *this;
			writer.write_checkout_to_simulation_file(*this);

			checkout_cashier.set_activity("Leave");
			cout << *this;
			writer.write_checkout_to_simulation_file(*this);

			Sleep(2000);
			recipe(client_queue[0]);
			vector<Client>::iterator it = client_queue.begin();
			client_queue.erase(it);
		}
		else
		{
			FileReader writer;
			checkout_cashier.set_activity("invoice");
			cout << *this;
			writer.write_checkout_to_simulation_file(*this);
			checkout_cashier.set_activity("Leave");
			cout << *this;
			
			writer.write_checkout_to_simulation_file(*this);

			Sleep(2000);
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
	set_cashier_activity("opened");
	cout << *this;
	FileReader writer;
	writer.write_checkout_to_simulation_file(*this);
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
		os << endl << endl << endl << "Cashier " << check.get_cashier().get_name() << " " << check.get_cashier().get_surname() << " on checkout " << check.id << " served client " << check.client_queue[0].get_name() << " " << check.client_queue[0].get_surname() << endl << endl;
	}
	else if (check.get_cashier().get_activity() == "scanning client")
	{
		os <<endl<< "Cashier " << check.get_cashier().get_name() << " " << check.get_cashier().get_surname() << " on checkout " << check.id << " is serving client " << check.client_queue[0].get_name() << " " << check.client_queue[0].get_surname() << endl;
	}
	else if (check.get_cashier().get_activity() == "opened")
	{
		os <<endl<<"Checkout with id " << check.id << " has just opened" <<endl;
	}
	else if (check.get_cashier().get_activity() == "recipe")
	{
		os << "Client " << check.client_queue[0].get_name() << " " << check.client_queue[0].get_surname()<<" recived recipe" << endl<<endl << endl;
	}
	else if (check.get_cashier().get_activity() == "invoice")
	{
		os << "Client " << check.client_queue[0].get_name() << " " << check.client_queue[0].get_surname() << " recived invoice" << endl<<endl << endl;
	}
	return os;
}