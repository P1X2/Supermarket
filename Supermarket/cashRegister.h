#pragma once
#include "Employees/Cashier.h"
#include "Client.h"
class CashRegister
{
	Cashier register_cashier;
	bool is_open;
	vector<Client> client_queue;
	vector<Product> current_clinet_shopping_cart;
	int profit;
public:
	void scan_product();
	int total();


};

