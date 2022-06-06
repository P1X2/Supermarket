#pragma once
#include "Employees/Cashier.h"
#include "Client.h"
#include "RegisterClient.h"
#include <ostream>
#include "Invoice.h"
#include "Recipe.h"
#include "RegisterBills.h"

class Checkout
{
	Cashier checkout_cashier;
	
	vector<Client> client_queue;
	vector<Product> current_client_shopping_cart;

	int current_shopping_cart_index = 0;
	int id;
	int current_cart_profit = 0;
	int profit = 0;
	bool is_open;
	int get_scanning_speed();
public:
	Checkout();
	Checkout(Cashier checkout_cashier, bool is_open, int id);

	Cashier get_cashier();
	void set_cashier_activity(string activity);
	
	void checkout_action(); 
	int scan_product(); 
	int get_client_queue_lenght();

	void release_cashier();
	void assign_cashier();

	void recipe(Client cl);
	void invoice(Client cl);

	void reset_CSCI();
	void update_CCSC();

	void add_client_to_queue(Client client);

	friend class Supermarket_sandbox;
	friend class Supermarket;
	bool operator<(const Checkout& second_checkout)const;
	friend ostream& operator<<(ostream& os, Checkout& check);
};
