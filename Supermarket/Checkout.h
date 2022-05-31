#pragma once
#include "Employees/Cashier.h"
#include "Client.h"
class Checkout
{
	Cashier checkout_cashier;
	bool is_open;
	vector<Client> client_queue;
	vector<Product> current_client_shopping_cart;
	int profit;
public:
	Checkout(Cashier checkout_cashier);
	void scan_product();
	int total();

	void release_cashier();
	void assign_cashier();

	void recipe();
	void invoice();

	void update_CCSC();
};

