#include "Whiskey.h"

Whiskey::Whiskey(string name, int price, int calories, string Producer, string barcode, int alcoholPercent)
	:Product(name, Producer,barcode, price, calories), alcoholPercent(alcoholPercent)
{
	vat = 23;
}

float Whiskey::VAT() const
{
	return price*0.30;
}

string Whiskey::Localization() const
{
	return "Alley 15; Shelve 15, 16";
}

int Whiskey::getAlcoholPercent()
{
	return alcoholPercent;
}

bool Whiskey::operator==(const Whiskey& second_whiskey) const
{
	return (name == second_whiskey.name and price == second_whiskey.price and producer == second_whiskey.producer and alcoholPercent == second_whiskey.alcoholPercent and calories == second_whiskey.calories);
}

