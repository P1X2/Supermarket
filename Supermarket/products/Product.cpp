#include "Product.h"
#include "NegativePriceException.h"
#include "NegativeCaloriesException.h"

Product::Product(string Name, string Producer,string barcode, int price, int calories) :name(Name), producer(Producer), barcode(barcode)
{
	if (price <= 0)
	{
		throw NegativePriceException();
	}

	if (calories <= 0)
	{
		throw NegativeCaloriesException();
	}

	this->price = price;
	this->calories = calories;
}
float Product::VAT() const
{
	return 0;
}
string Product::Localization() const
{
	return string();
}
string Product::getName() const
{
	return name;
}
string Product::getProducer() const
{
	return producer;
}
string Product::getBarcode() const
{
	return barcode;
}
int Product::getCalories() const
{
	return calories;
}

int Product::getPrice() const
{
	return price;
}


