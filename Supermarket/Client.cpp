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
