#pragma once
#include "Product.h"
class Whiskey :
    public Product
{
private:
    int alcoholPercent;

public:
    Whiskey(string name, int price, int calories, string Producer,string barcode, int alcoholPercent);

    float VAT() const override;
    string Localization() const override;

    int getAlcoholPercent();

    bool operator==(const Whiskey& second_whiskey)const;
};

