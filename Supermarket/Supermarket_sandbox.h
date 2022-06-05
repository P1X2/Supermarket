#pragma once
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

class Supermarket_sandbox
{
	ProductShelve shop_shelve;
	ProductShelve magazine;

	RNG rng_machine;
	RegisterCashiers cashiers;
	RegisterWarehouseman warehousemen;
	RegisterSecurityGuard security_guards;
	RegisterClient clients;
	vector<Checkout> checkouts;



	FileReader file_reader;


public:


	void do_shopping();
	void go_to_magazine();
	void give_prd_to_client();
	void scanning_checkouts();

};

