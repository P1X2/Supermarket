#include "Client.h"

void Client::check_if_done()
{
    if (shopping_cart.size() == currently_serched_prd)
    {
        is_done = true;
    }
}

Client::Client(string name, string surname, vector<string> shopping_list, Address adderss, bool recipe) : name(name), surname(surname), shopping_list(shopping_list),
address(adderss), recipe(recipe)
{
}

string Client::get_name()
{
    return name;
}

string Client::get_surename()
{
    return surname;
}

string Client::get_adress()
{

    return (address.get_country() + ", " + address.get_city() + "\n" + address.get_street() +" " + to_string(address.get_house_number()));
}

bool Client::get_is_done()
{
    return is_done;
}

vector<Product> Client::get_shopping_cart()
{
    return shopping_cart;
}

bool Client::get_recipe()
{
    return recipe;
}

int  Client::serch_product(ProductShelve &shop_shelve)
{
    map<Product, int>::iterator it;
    map<Product, int> inventory = shop_shelve.get_inventory();

    for (it = inventory.begin(); it != inventory.end(); it++)
    {
        Product prd_map = it->first;

        if (prd_map.getName() == shopping_list[currently_serched_prd])
        {
            if (it->second == 0)
            {
                return 1; // spr w supersamie
            }
            else
            {
                grab_product(it);
                shop_shelve.update_inventory(it->first);
                update_currently_serched_product();
                check_if_done();
                return 0;
            }
        }
    }

}

void Client::grab_product(map<Product, int>::iterator it)
{
    shopping_cart.push_back(it->first);
}

void Client::grab_product_from_emplyee(Product prd)
{
    shopping_cart.push_back(prd);
    update_currently_serched_product();
    check_if_done();
}

void Client::ask_question__is_in_stock(RegisterWarehouseman &registerWHM)
{
    for (vector<Warehouseman>::iterator emp_ptr = registerWHM.employees.begin(); emp_ptr != registerWHM.employees.end(); emp_ptr++)
    {
        if (emp_ptr->get_is_serching_prd() == false)
        {
            emp_ptr->serch_product(surname, shopping_list[currently_serched_prd]);
            return;
        }
        else
        {
            continue;
        }
    }
}

void Client::update_currently_serched_product()
{
    currently_serched_prd++;
}

ostream& operator<<(ostream& os, const Client& cl)
{
    os << cl.name << " " << cl.surname << " Shopping cart: ";
    for (Product prod : cl.shopping_cart)
    {
        os << prod << ",";
    }
    return os;
}