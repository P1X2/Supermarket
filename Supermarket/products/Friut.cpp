#include "Friut.h"
#include "Product.h"

Fruit::Fruit(string name, int price, int calories, string Producer, string barcode, string orginCountry):
	Product(name,Producer,barcode, price, calories)
{
	this->orginCountry = orginCountry;
}

float Fruit::VAT() const
{
	return price*0.07;
}

string Fruit::Localization() const
{
	return "Alley 5";
}

string Fruit::getOrginCountry()
{
	return orginCountry;
}

bool Fruit::operator==(const Fruit& second_friut) const
{
	return (name == second_friut.name and price == second_friut.price and producer == second_friut.producer and orginCountry == second_friut.orginCountry and calories == second_friut.calories);
}
