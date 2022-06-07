#pragma once
#include <map>
#include <list>
#include"products/Product.h"
#include"Checkout.h"
#include "Client.h"
#include "Employees/RegisterCashiers.h"
#include "Employees/RegisterWarehouseman.h"
#include "Employees/RegisterSecurityGuard.h"
#include "RegisterClient.h"
#include "RNG.h"
#include "FileReader.h"


class Supermarket
{
	ProductShelve shop_shelve;
	ProductShelve magazine;
	vector<Product> products;

	vector<Checkout> checkouts;

	RNG rng_machine;
	RegisterCashiers cashiers;
	RegisterWarehouseman warehousemen;
	RegisterSecurityGuard security_guards;
	RegisterClient clients;

	FileReader file_reader;
	int last_client_id=0;

	void generate_client(int=1);
	void generate_employees();


	void do_shopping();
	void go_to_magazine();
	void give_prd_to_client();
	void opening_checkouts();
	void scan_products();
	void randomly_generate_client(int percent);

public:
	Supermarket(string products_path,string names_surnames_path, string addresses_path);


	void load_registers();
	void simulation(int iterations);
};