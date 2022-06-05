#pragma once

#include <string>
#include <vector>
#include <map>
#include "products/Product.h"
#include "Employees/Person.h"
#include "Address.h"
#include <stdexcept>
#include "ProductShelve.h"
#include "Employees/Warehouseman.h"
class Supermarket;
using namespace std;

// dorobic czasy wykonywana czynnoœci

class Client :
    public Person
{
    string name, surname;
    vector<string> shopping_list;
    vector<Product> shopping_cart;
    Address address;
    bool recipe;
    int currently_serched_prd = 0; 


public:
    Client(string name, string surname, vector<string> shopping_list, Address adderss, bool recipe);
    string get_name();
    string get_surename();
    string get_adress();
    vector<Product> get_shopping_cart();


    void serch_product(ProductShelve shop_shelve);
    void grab_product(map<Product, int> shop_shelve, map<Product, int>::iterator it);
    void ask_question__is_in_stock(Warehouseman WHM);
    void go_to_checkout();

    void update_currently_serched_product();
};
