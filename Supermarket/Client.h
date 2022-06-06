#pragma once

#include <string>
#include <vector>
#include <map>
#include "products/Product.h"
#include "Employees/Person.h"
#include "Address.h"
#include <stdexcept>
#include "ProductShelve.h"
#include "RNG.h"


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
    bool w8ting = false;
    bool is_done = false;
    bool rng = true;
    int currently_serched_prd = 0;
    RNG RNG;


    void check_if_done();

public:
    Client(string name, string surname,int id, vector<string> shopping_list, Address adderss, bool recipe);

    string get_name();
    string get_surname();
    string get_adress();
    bool get_is_done();
    vector<Product> get_shopping_cart();
    bool get_recipe();

    bool get_is_w8ting();
    void is_w8ting_end();


    int serch_product(ProductShelve &shop_shelve);
    void grab_product( map<Product, int>::iterator it); // modyfikacja 
    void grab_product_from_emplyee(Product prd);
    void ask_question__is_in_stock(RegisterWarehouseman &registerWHM);

    void update_currently_serched_product();

    friend ostream& operator<<(ostream& os, const Client& cl);
};

ostream& operator<<(ostream& os, const Client& cl);