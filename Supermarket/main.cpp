// Supermarket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Employees/Cashier.h"
#include"products/Meat.h"
#include "products/Juice.h"
#include "Supermarket.h"

using namespace std;
int main()
{
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
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
