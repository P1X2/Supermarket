#include "Meat.h"

Meat::Meat(string name, int price, int calories, string producer,string barcode, string animalOrgin)
	:Product(name, producer,barcode, price, calories), animal(animal)
{}
float Meat::VAT() const
{
	return price*0.21;
}

string Meat::Localization() const
{
	return "Alley 12; Meat station\nAlley 11; Frezzer 2, 3";
}

string Meat::getAnimal()
{
	return animal;
}

bool Meat::operator==(const Meat& second_meat) const
{
	return (name == second_meat.name and price == second_meat.price and producer == second_meat.producer and animal == second_meat.animal and calories == second_meat.calories);
}

;