#pragma once
#include <string>
#include <vector>
#include "products/Product.h"
#include "Employees/Person.h"
#include "Adress.h"

using namespace std;

class Client :
    public Person
{
    string name, surname;
    vector<string> shopping_list;
    vector<Product> shopping_cart;
    Adress adress;
public:
    string get_name();
    string get_surename();
    string get_adress();
};

