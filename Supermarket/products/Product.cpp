#include "Product.h"
#include "NegativePriceException.h"
#include "NegativeCaloriesException.h"

Product::Product(string Name, string Producer,string barcode, int price, int calories) :name(Name), producer(Producer), barcode(barcode)
{
	//if (price <= 0)
	//{
	//	throw NegativePriceException();             // mod zb dzia³a³o
	//}

	//if (calories <= 0)
	//{
	//	throw NegativeCaloriesException();
	//}

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

int Product::get_vat() const
{
	return vat;
}

bool Product::operator==(const Product& second_product) const
{
	return (name == second_product.name);
}

bool Product::operator!=(const Product& second_product) const
{
	return !(*this == second_product);
}

bool Product::operator<(const Product& second_product) const
{
	return (price < second_product.price);
}

ostream& operator<<(ostream& os, const Product& prod)
{
	os << prod.name << " price: " << prod.price;
	return os;
}