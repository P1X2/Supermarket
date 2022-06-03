#pragma once
#include "Product.h"
#include "Friut.h"
class Juice :
    public Product
{
private:
    int sugarPer100;

public:
    Juice(string name, int price, int calories, string Producer,string barcode, int sugarPer100);

    float VAT() const override;
    string Localization() const override;

    int getSugarPer100() const;
    

    bool operator==(const Juice& second_Juice)const;
};

