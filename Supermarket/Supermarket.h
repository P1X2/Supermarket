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

	RNG rng_machine;
	RegisterCashiers cashiers;
	RegisterWarehouseman warehousemen;
	RegisterSecurityGuard security_guards;
	RegisterCashiers cashiers;

	RNG rng_machine;

	FileReader file_reader;
	RegisterClient clients;
	void generate_client(int=1);
	void generate_employees();
public:
	void simulation(int=1000);
	map<Product, int> magazine_shelve;
	vector<Client> clients;
	RegisterCashiers cashier_register;


};