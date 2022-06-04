// Supermarket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include"Employees/Cashier.h"
#include"products/Meat.h"
#include "products/Juice.h"
#include "Supermarket.h"
#include "RNG.h"


using namespace std;
int main()
{
    //Cashier xd("elo", "xd", 160, 20, 30);
    //std::cout << "Hello World!\n";
    //xd.print_employer();
    Meat xdxd("elo1", 12, 23, "elss", "23123", "sdew");
    Meat xdx("elo1", 12, 23, "elss", "23123", "sdew");
    //std::cout << xdxd.VAT() << endl;
    //std::cout << xd.get_busy();
    vector<Product> a;
    a.push_back(xdxd);
    a.push_back(xdx);
    vector<Product>::iterator it;
     for (it = a.begin(); it != a.end(); it++)
     {
         cout << it->getName();
     }

    //cout << endl << (xdxd == xdx);




    
    RNG rng;
    cout << rng.generate_random_number(1,12);

    vector<int> b;
    b.push_back(1); b.push_back(2);
    cout << b[1];


    /*
    Cashier xd("elo", "xd", 160, 20, 30);
    std::cout << "Hello World!\n";
    xd.print_employer();
    Meat xdxd("elo1",12,23,"elss","23123","sdew");
    Meat xdx("elo2", 12, 23, "elss", "23123", "sdew");
    std::cout << xdxd.VAT() << endl;
    std::cout << xd.get_busy();
    vector<Product> a;
    a.push_back(xdxd);
    a.push_back(xdx);
    vector<Product>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
    {
        cout << it->getName();
    }
    */
    Supermarket super;
    super.load_names_surnames("names.txt");
    
    map <int, int> w;
    w[1] = 1;
    w[2] = 2;
    

}

