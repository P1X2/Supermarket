#pragma once
#include <list>
#include <string>
#include <vector>
#include <memory>
#include "Product.h"
#include "Friut.h"
#include "Meat.h"
#include "Juice.h"
#include "Whiskey.h"

using namespace std;

class DataBase
{
private:
	list <unique_ptr<Product>> products;
	void unique(string barecode); 
public:
	void addFriut(string name, int price, int calories, string Producer,string barcode, string orginCountry);
	void addJuice(string name, int price, int calories, string Producer, string barcode, int sugarPer100);
	void addMeat(string name, int price, int calories, string producer, string barcode, string animalOrgin);
	void addWhiskey(string name, int price, int calories, string Producer, string barcode, int alcoholPercent);

	void deleteProduct(string barcode);

	void VATlist() noexcept;
	void localizationList() noexcept;

};
