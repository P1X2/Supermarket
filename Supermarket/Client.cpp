#include "Client.h"

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

void  Client::serch_product(vector<Product> shop_shelve)
{
    for (int it = 0; it != shop_shelve.size(); it++)
    {
        if (shop_shelve[it].getName() == shopping_list[currently_serched_prd])
        {
            current_prd_index_in_sh = it;
        }
    }
    current_prd_index_in_sh =-1;
}

void Client::grab_product(vector<Product> shop_shelve,int index)
{
    if (index == -1)
    {
        // akcja jak prd nie ma na pó³ce
    }
    shopping_cart.push_back(shop_shelve[index]);
    //update shopshelve zrobic
}

int Client::ask_question__is_in_stock(vector<Employee> emp)
{
    if (emp.size() == 0)
    
    Employee emp_to_ask = emp[0];


}

void Client::update_currently_serched_product()
{
    currently_serched_prd++;
}


