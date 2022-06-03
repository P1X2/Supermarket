// Supermarket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Employees/Cashier.h"
#include"products/Meat.h"
#include "products/Juice.h"
#include "RNG.h"


using namespace std;
int main()
{
    //Cashier xd("elo", "xd", 160, 20, 30);
    //std::cout << "Hello World!\n";
    //xd.print_employer();
    //Meat xdxd("elo1", 12, 23, "elss", "23123", "sdew");
    //Meat xdx("elo1", 12, 23, "elss", "23123", "sdew");
    //std::cout << xdxd.VAT() << endl;
    //std::cout << xd.get_busy();
    //vector<Product> a;
    //a.push_back(xdxd);
    //a.push_back(xdx);
    //vector<Product>::iterator it;
    ///* for (it = a.begin(); it != a.end(); it++)
    // {
    //     cout << it->getName();
    // }*/

    //cout << endl << (xdxd == xdx);




    
    RNG rng;
    cout << rng.generate_random_number(12);

    vector<int> a;
    a.push_back(1); a.push_back(2);
    cout << a[3];



}

