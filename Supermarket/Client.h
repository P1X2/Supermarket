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
    bool is_done;
    int currently_serched_prd = 0; 

    void check_if_done(); // WYWO£AC W SUPERMARKECIE !!!!!!!!!!!!

public:
    Client(string name, string surname, vector<string> shopping_list, Address adderss, bool recipe);

    string get_name();
    string get_surename();
    string get_adress();
    bool get_is_done();
    vector<Product> get_shopping_cart();
    bool get_recipe();



    int serch_product(ProductShelve &shop_shelve);
    void grab_product( map<Product, int>::iterator it); // modyfikacja 
    void grab_product_from_emplyee(Product prd);
    void ask_question__is_in_stock(RegisterWarehouseman &registerWHM);

    void update_currently_serched_product();

    friend ostream& operator<<(ostream& os, const Client& cl);
};

ostream& operator<<(ostream& os, const Client& cl);