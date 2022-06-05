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

vector<Product> Client::get_shopping_cart()
{
    return shopping_cart;
}

int  Client::serch_product(ProductShelve shop_shelve)
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
                return -1; // spr w supersamie
            }
            else
            {
                grab_product(inventory, it);
                shop_shelve.update_inventory(it->first);
                check_if_done();
                return 0;
            }
        }
    }

}

void Client::grab_product(map<Product, int> shop_shelve, map<Product, int>::iterator it)
{
    shopping_cart.push_back(it->first);
}

void Client::ask_question__is_in_stock(Warehouseman WHM)
{
    WHM.serch_product(surname, shopping_list[currently_serched_prd]);
}

void Client::update_currently_serched_product()
{
    currently_serched_prd++;
}


