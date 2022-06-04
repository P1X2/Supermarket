#pragma once
#include <map>
#include <list>
#include"products/Product.h"
#include"Checkout.h"
#include "Client.h"


class Supermarket
{
	map<Product, int> shop_shelve;
	vector<Client> cl;
};
