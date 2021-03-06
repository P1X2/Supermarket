#pragma once
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include <iostream>


using namespace std;


class Product
{
protected:
	string name, barcode;
	int price, calories;
	string producer;
	int vat;
public:
	Product(string Name, string Producer,string barcode, int price, int calories);

	virtual float VAT() const;
	virtual string Localization() const;

	string getName() const;
	string getProducer() const;
	string getBarcode() const;
	int getCalories() const;
	int getPrice() const;
	int get_vat() const;

	bool operator==(const Product& second_product)const;
	bool operator!=(const Product& second_product)const;
	bool operator<(const Product& second_product)const;

	friend ostream& operator<<(ostream& os, const Product& prod);
};

ostream& operator<<(ostream& os, const Product& prod);

