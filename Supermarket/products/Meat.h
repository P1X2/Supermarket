#pragma once
#include "Product.h"


class Meat :
    public Product
{
    string animal;

public:
    Meat(string name, int price, int calories, string producer,string barcode, string animalOrgin);

    float VAT() const override;
    string Localization() const override;

    string getAnimal();

    bool operator==(const Meat& second_meat)const;
};

