#include "Address.h"

Address::Address(string country, string city, string street, int house_number): country(country), city(city), street(street), house_number(house_number)
{
}

int Address::get_house_number()
{
    return  house_number;
}

string Address::get_street()
{
    return street;
}

string Address::get_city()
{
    return city;
}

string Address::get_country()
{
    return country;
}
