// Supermarket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include"Employees/Cashier.h"
#include"products/Meat.h"
#include "products/Juice.h"
#include "Supermarket.h"
#include "RNG.h"
#include "Employees/RegisterWarehouseman.h"
#include "ProductShelve.h"
#include "Invoice.h"
#include "Recipe.h"
#include "RegisterBills.h"


using namespace std;
int main()
{



    Supermarket sprm("products.txt", "names.txt", "addresses.txt");
    sprm.load_registers();
    sprm.simulation(30);
}

