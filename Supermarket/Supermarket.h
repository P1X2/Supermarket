#pragma once
#include <map>
#include <list>
#include"products/Product.h"
#include"Checkout.h"
#include "Client.h"
#include "Employees/RegisterCashiers.h"
#include "Employees/RegisterWarehouseman.h"
#include "Employees/RegisterSecurityGuard.h"
#include "RNG.h"
#include "FileReader.h"


class Supermarket
{
	map<Product, int> shop_shelve;
	vector<Client> cl;
	RNG rng_machine;
	RegisterCashiers cashiers;
	RegisterWarehouseman warehousemen;
	RegisterSecurityGuard security_guards;
	FileReader file_reader;

	void generate_employees();
public:
	void simulation(int=1000);
};
