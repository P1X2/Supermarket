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

	RNG rng_machine;
	RegisterCashiers cashiers;
	RegisterWarehouseman warehousemen;
	RegisterSecurityGuard security_guards;

	FileReader file_reader;
	RegisterClient clients;
	void generate_client(int=1);
	void generate_employees();
public:
	void simulation(int=1000);
	Supermarket(string products_path);

};