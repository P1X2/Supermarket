#pragma once
#include "Employees/Cashier.h"
#include "Client.h"
#include "RegisterClient.h"
#include <ostream>

class Checkout
{
	Cashier checkout_cashier;
	
	vector<Client> client_queue;
	vector<Product> current_client_shopping_cart;
	int profit;
	bool is_open;
public:
	Checkout();
	Checkout(Cashier checkout_cashier, bool is_open);
	
	void scan_product(); // do zrobienia jak bedzie g�owna petla czasu
	int total();
	int get_client_queue_lenght();

	void release_cashier();
	void assign_cashier();

	void recipe();
	void invoice();

	void update_CCSC();
	void update_profit();

	void add_client_to_queue(Client client);

	friend class Supermarket_sandbox;
	bool operator<(const Checkout& second_checkout)const;
	friend ostream& operator<<(ostream& os, const Checkout& check);
};

ostream& operator<<(ostream& os, const Checkout check);