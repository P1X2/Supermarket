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
#include "Employees/Warehouseman.h"
#include "..\Supermarket\Employees\RegisterCashiers.h"


class Supermarket
{
	ProductShelve shop_shelve;
	ProductShelve magazine;

	vector<Client> cl;
	RegisterWarehouseman warehousemen;
	RegisterSecurityGuard security_guards;
	RegisterCashiers cashiers;

	RNG rng_machine;

	FileReader file_reader;

	void generate_client();
	void generate_employees();
public:
	void simulation(int=1000);



};