#include "Client.h"
#include <stdexcept>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <cstdlib>
#include "FileReader.h"

void Client::check_if_done()
{
    if (shopping_list.size() == currently_serched_prd)
    {
        set_activity("done shopping");
        cout <<endl <<*this<< endl;
        FileReader writer;
        writer.write_client_to_simulation_file(*this);
        Sleep(2000);
        is_done = true;
        set_activity("in queue");
    }
}

Client::Client(string name, string surname, int id,vector<string> shopping_list, Address adderss, bool recipe) : Person(id),
name(name),surname(surname),shopping_list(shopping_list),
address(adderss), recipe(recipe)
{
}

string Client::get_name()
{
    return name;
}

string Client::get_surname()
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

vector<string> Client::get_shopping_list()
{
    return shopping_list;
}

bool Client::get_recipe()
{
    return recipe;
}

bool Client::get_is_w8ting()
{
    return w8ting;
}

void Client::is_w8ting_end()
{
    w8ting = false;
}

int Client::get_currently_serched_prd()
{
    return currently_serched_prd;
}

int  Client::serch_product(ProductShelve &shop_shelve)
{
    if (rng == true)
    {
        set_busy(RNG.generate_random_number(0, 3));
        rng = false;
    }
    map<Product, int>::iterator it;
    map<Product, int> inventory = shop_shelve.get_inventory();
    if (this->get_busy() == 0)
    {
        for (it = inventory.begin(); it != inventory.end(); it++)
        {
            Product prd_map = it->first;

            if (prd_map.getName() == shopping_list[currently_serched_prd])
            {
                if (it->second == 0)
                {
                    rng = true;
                    return 1; 
                }
                else
                {
                    grab_product(it);
                    shop_shelve.update_inventory(it->first);
                    update_currently_serched_product();
                    check_if_done();
                    rng = true;
                    return 0;
                }
            }
        }
    }
    else
    {
        this->set_busy(this->get_busy() - 1);
    }
    
}

void Client::grab_product(map<Product, int>::iterator it)
{

    shopping_cart.push_back(it->first); // nie tu
    set_activity("shopping");
    cout << *this;
    FileReader writer;
    writer.write_client_to_simulation_file(*this);
    //Sleep(1000);

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
            emp_ptr->serch_product(get_id(),get_name(),get_surname(), shopping_list[currently_serched_prd]);
            w8ting = true;
            set_activity("w8 WHM");
            cout << *this;
            FileReader writer;
            writer.write_client_to_simulation_file(*this);
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

ostream& operator<<(ostream& os, Client& cl)
{
    if (cl.get_activity() == "done shopping")
    {
        os<< "Client " << cl.get_name() << " " << cl.get_surname() << " has ended shopping, now he's going to checkout" << endl;
    }
    else if (cl.get_activity() == "shopping")
    {
        //wojtas is sus
        os << "Client " << cl.get_name() << " " << cl.get_surname() << " grabbed " << cl.get_shopping_cart()[cl.get_currently_serched_prd()] << " and put it in the shopping cart" << endl;
    }
    else if (cl.get_activity() == "w8 WHM")
    {
        os << "Client " << cl.get_name() << " " << cl.get_surname() << " is waiting for warehouseman, to get"<< "prds" << " from magazine" << endl;
    }

    return os;
}