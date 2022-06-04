#pragma once
#include <map>
#include <list>
#include"products/Product.h"
#include"Checkout.h"
#include "Client.h"
#include "Employees/Employee.h"
#include "..\Supermarket\Employees\RegisterCashiers.h"


class Supermarket
{
	map<Product, int> shop_shelve;
	map<Product, int> magazine_shelve;
	vector<Client> clients;
	RegisterCashiers cashier_register;

};
