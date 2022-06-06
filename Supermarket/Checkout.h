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

	int current_shopping_cart_index = 0;
	int current_cart_profit = 0;
	int profit = 0;
	bool is_open;
	int get_scanning_speed();
public:
	Checkout();
	Checkout(Cashier checkout_cashier, bool is_open);
	
	void checkout_action(); //metoda do wywo³ywania w symulacji co obrót pêtli
	int scan_product(); // do zrobienia jak bedzie g³owna petla czasu
	int get_client_queue_lenght();
	
	void reset_CSCI();
	void release_cashier();
	void assign_cashier();

	void recipe(Client cl);
	void invoice(Client cl);

	void update_CCSC();
	void update_profit();

	void add_client_to_queue(Client client);

	friend class Supermarket_sandbox;
	friend class Supermarket;
	bool operator<(const Checkout& second_checkout)const;
	friend ostream& operator<<(ostream& os, const Checkout& check);
};

ostream& operator<<(ostream& os, const Checkout check);