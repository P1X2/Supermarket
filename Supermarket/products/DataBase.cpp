#include "DataBase.h"
#include "Friut.h"
#include "Meat.h"
#include "Juice.h"
#include "Whiskey.h"
#include <vector>
#include <iostream> 
#include "ProductNotFoundException.h"
#include "BarcodeNotUniqueException.h"


using namespace std;

void DataBase::unique(string barcode) // elo21
{
	for (const auto& PTR : products)
	{
		if (PTR->getBarcode() == barcode)
		{
			throw BarcodeNotUniqueException();
		} 
	}
}



void DataBase::addFriut(string name, int price, int calories, string Producer,string barcode, string orginCountry)
{
	unique(barcode);
	unique_ptr<Fruit> addedFriut = make_unique<Fruit>(name, price, calories, Producer, barcode, orginCountry);
	products.push_back(move(addedFriut));
}

void DataBase::addJuice(string name, int price, int calories, string Producer, string barcode, int sugarPer100)
{
	unique(barcode);
	unique_ptr<Juice> addedJuice = make_unique<Juice>(name, price, calories, Producer, barcode, sugarPer100);
	products.push_back(move(addedJuice));
}

void DataBase::addMeat(string name, int price, int calories, string producer, string barcode, string animalOrgin)
{
	unique(barcode);
	unique_ptr<Meat> addedMeat = make_unique<Meat>(name, price, calories, producer, barcode, animalOrgin);
	products.push_back(move(addedMeat));
}

void DataBase::addWhiskey(string name, int price, int calories, string Producer, string barcode, int alcoholPercent)
{
	unique(barcode);
	unique_ptr<Whiskey> addedWhiskey = make_unique<Whiskey>(name,price, calories, Producer, barcode, alcoholPercent);
	products.push_back(move(addedWhiskey));
}





void DataBase::deleteProduct(string barcode)
{

	for (const auto& PTR : products)
	{
		if (PTR->getBarcode() == barcode)
		{
			products.remove(PTR);
			return;
		}
	}
	throw ProductNotFoundException();
}





void DataBase::VATlist() noexcept
{
	for (const auto& PTR : products)
	{
		cout <<"Product name: " << PTR->getName() << endl << "Barcode: " << PTR->getBarcode() << endl << "Base price: " << PTR->getPrice() << endl << "VAT: " << PTR->VAT() << endl << endl;
	}
}

void DataBase::localizationList() noexcept
{
	for (const auto& PTR : products)
	{
		cout << "Product name: " << PTR->getName() <<endl << "Barcode: " << PTR ->getBarcode() << endl << "Localization: " << PTR->Localization() << endl << endl;
	}
}
