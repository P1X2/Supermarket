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


using namespace std;
int main()
{
    //Cashier xd("elo", "xd", 160, 20, 30);
    //std::cout << "Hello World!\n";
    //xd.print_employer();
    //Meat xdxd("a", 1, 23, "ess", "23123", "w");
    //Meat xdx("b", 12, 3, "elss", "23", "sdew");
    //std::cout << xdxd.VAT() << endl;
    //std::cout << xd.get_busy();
    //vector<Product> a;
    //a.push_back(xdxd);
    //a.push_back(xdx);
    //vector<Product>::iterator it;
    // for (it = a.begin(); it != a.end(); it++)
    // {
    //     cout << it->getName();
    // }

    ////cout << endl << (xdxd == xdx);

   // Supermarket super;
    //super.simulation();



    
   /* RNG rng;
    for (int i = 1; i != 10; i++)
    {
        cout << rng.generate_random_number(1, 9);
    }
    cout << rng.generate_random_number(1,100);*/

    //vector<int> b;
    //b.push_back(1); b.push_back(2);
    //cout << b[1];


 /*  
    
    RegisterCashiers reg;
    reg.add_cashier("op", "as", 160, 13, 15);
    reg.add_cashier("oa", "ss", 160, 12, 20);
    cout << endl<< reg.how_many_workers() << endl;
    
    map <int, int> w;
    w[1] = 1;
    w[2] = 2;*/




    
 /*  RegisterCashiers reg;
    reg.add_cashier("op", "as", 160, 13, 15);
    reg.add_cashier("oa", "ss", 160, 12, 20);
    cout << endl<< reg.how_many_workers() << endl;*/
    //Supermarket super;
    //super.simulation();
    //vector<int> a;
    //map<vector, int> a;
     //test polki na bulki

























    /// TESTY SYMULACJI D;;D;D;D;D;D;D;D;D;D;

    //vector<int> pwr;
    //vector<Product> y;
    //pwr.push_back(0);
    //y.push_back(xdxd);
    //pwr.push_back(0);
    //y.push_back(xdx);
    //ProductShelve c(y,pwr);


    //vector<int> f;
    //f.push_back(3);
    //f.push_back(2);
    //ProductShelve m(y, f);
    //cout << endl<<endl<<c.get_inventory()[xdxd];
    //c.update_inventory(xdxd);
    //c.update_inventory(xdxd);
    //cout << endl << endl << c.get_inventory()[xdxd];

    //RegisterWarehouseman regW;
    //regW.add_warehouseman("Kononowicz", "Krzysztof", 160, 56, 16);




    //vector<string> p;
    //p.push_back("b");
    //Address ad("awa", "bw","af", 12);
    //Client cl("a", "b",p , ad, false);

    //RegisterClient regc;
    //regc.add_client(cl);
    //int i = 0;
    //while (i<=2) {
    //    int flag1 = cl.serch_product(c);
    //    if (flag1 == 0)
    //    {
    //    }
    //    if(flag1==1)
    //    {
    //        cl.ask_question__is_in_stock(regW);
    //    }
    //    else
    //    {
    //        i++;
    //        continue;
    //    }
    //    i++;
    //}

    


    //regW.employees[0].serch_product("ania", "21478");
    //regW.employees[0].stop_searching();
    //m.who_is_looking_for_prd(regW);

    //vector<int> test;
    //test.push_back(1); test.push_back(2);
    //vector<int>::iterator it = test.begin();
    //test.erase(it);
    //cout << test[0];


    //cout << *it;
    //Address ads("polsza", "kielcze", "war", 12);
    //vector<Product> lsl;
    //lsl.push_back(xdxd);
    //lsl.push_back(xdx);
    //Invoice inv("bart", "dab", ads, lsl);

    //inv.print_bill();
    //return 1;
 /*   cout << *it;
    Address ads("polsza", "kielcze", "war", 12);
    vector<Product> lsl;
    lsl.push_back(xdxd);
    lsl.push_back(xdx);
    Invoice inv("bart", "dab", ads, lsl);
    inv.print_bill();
    Recipe rec(lsl);
    rec.print_bill();
    */
    

    Supermarket sprm("products.txt", "names.txt", "addresses.txt");
   // sprm.simulation();
    sprm.simulation();
    while (int i = 0 <= 500)
    {
        sprm.do_shopping();
        sprm.go_to_magazine();
        sprm.give_prd_to_client();
        sprm.opening_checkouts();
        sprm.scan_products();

        i++;
    }
}

