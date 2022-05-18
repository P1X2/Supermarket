#pragma once
#include "Product.h"
class Fruit :
    public Product
{
    string orginCountry;

public:
    Fruit(string name, int price, int calories, string Producer,string barcode, string orginCountry);

    float VAT() const override;
    string Localization() const override;

    string getOrginCountry();

    bool operator==(const Fruit& second_friut)const;
};

