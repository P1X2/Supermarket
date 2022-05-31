#pragma once
#include <string>
#include <vector>
#include "products/Product.h"
#include "Employees/Person.h"
#include "Address.h"

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
public:
    Client(string name, string surname, vector<string> shopping_list, Address adderss, bool recipe);
    string get_name();
    string get_surename();
    string get_adress();
    vector<Product> get_shopping_cart();

    void go_to_next_shelve();
    void grab_product();
    void ask_question__is_in_stock();
    void go_to_checkout();
};

