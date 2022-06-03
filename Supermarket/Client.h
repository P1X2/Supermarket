#pragma once
#include <string>
#include <vector>
#include "products/Product.h"
#include "Employees/Person.h"
#include "Address.h"
#include "Employees/Employee.h"
#include <stdexcept>

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
    int currently_serched_prd = 0; int current_prd_index_in_sh;

public:
    Client(string name, string surname, vector<string> shopping_list, Address adderss, bool recipe);
    string get_name();
    string get_surename();
    string get_adress();
    vector<Product> get_shopping_cart();


    void serch_product(vector<Product> shop_shelve);
    void grab_product(vector<Product> shop_shelve, int index);
    int ask_question__is_in_stock(vector<Employee> emp);
    void go_to_checkout();

    void update_currently_serched_product();
};

