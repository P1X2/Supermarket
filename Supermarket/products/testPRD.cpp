/*
#include "catch.hpp"
#include "DataBase.h"
#include "Friut.h"
#include "Juice.h"
#include "Meat.h"
#include "Whiskey.h"
#include "BarcodeNotUniqueException.h"
#include "NegativeCaloriesException.h"
#include "NegativePriceException.h"
#include "ProductNotFoundException.h"

TEST_CASE("Product inherited objects tests")
{
	vector<Fruit> v;
	Fruit a("Apple", 100, 50, "Sady Sandomierz", "12345678", "Poland");
	Meat b("Chicken breast", 2000, 300, "Chicekn sp. zoo", "1724578", "Chicken");
	Whiskey c("Whiskey 1", 5000, 170, "Gorzelina", "12312445", 35);
	Juice d("Apple juice", 350, 70, "Sady Sandomierz", "fghfh236", 10, v);

	SECTION("fruit")
	{
		CHECK(a.getName() == "Apple");
		CHECK(a.getPrice() == 100);
		CHECK(a.getCalories() == 50);
		CHECK(a.getProducer() == "Sady Sandomierz");
		CHECK(a.getBarcode() == "12345678");
		CHECK(a.getOrginCountry() == "Poland");
	}

	SECTION("Meat")
	{
		CHECK(b.getName() == "Chicken breast");
		CHECK(b.getPrice() == 2000);
		CHECK(b.getCalories() == 300);
		CHECK(b.getProducer() == "Chicekn sp. zoo");
		CHECK(b.getBarcode() == "1724578");
	}

	SECTION("Whiskey")
	{
		CHECK(c.getName() == "Whiskey 1");
		CHECK(c.getPrice() == 5000);
		CHECK(c.getCalories() == 170);
		CHECK(c.getProducer() == "Gorzelina");
		CHECK(c.getBarcode() == "12312445");
		CHECK(c.getAlcoholPercent() == 35);
	}
	SECTION("Juice")
	{
		CHECK(d.getName() == "Apple juice");
		CHECK(d.getPrice() == 350);
		CHECK(d.getCalories() == 70);
		CHECK(d.getProducer() == "Sady Sandomierz");
		CHECK(d.getBarcode() == "fghfh236");
		CHECK(d.getSugarPer100() == 10);
		CHECK(d.getFruitss() == v);
	}
	


	SECTION("Polimorfizm - fruit")
	{
		CHECK(a.VAT() == 7);
		CHECK(a.Localization() == "Alley 5");
	}

	SECTION("Polimorfizm - juice")
	{
		CHECK(d.VAT() == 42);
		CHECK(d.Localization() == "Alley 1; Shelve 12, 13, 14");
	}

	SECTION("Polimorfizm - meat")
	{
		CHECK(b.VAT() == 420);
		CHECK(b.Localization() == "Alley 12; Meat station\nAlley 11; Frezzer 2, 3");
	}

	SECTION("Polimorfizm - whiskey")
	{
		CHECK(c.VAT() == 1500);
		CHECK(c.Localization() == "Alley 15; Shelve 15, 16");
	}

}

TEST_CASE("Data base tests")
{
	DataBase data;
	vector<Fruit> v;

	data.addFriut("Apple", 100, 50, "Sady Sandomierz", "12345678", "Poland");
	data.addJuice("Apple juice", 350, 70, "Sady Sandomierz", "fghfh236", 10, v);
	data.addMeat("Chicekn breast", 2000, 300, "Chicekn sp. zoo", "1724578", "Chicken");
	data.addWhiskey("Whiskey 1", 5000, 170, "Gorzelina Namus³ów", "12312445", 35);


	SECTION("invaild constructor arguments [price and calories]")
	{
		CHECK_THROWS(data.addFriut("Apple", -100, 50, "Sady Sandomierz", "12345618", "Poland"));
		CHECK_THROWS(data.addFriut("Apple", 100, -50, "Sady Sandomierz", "12345618", "Poland"));
	}
	SECTION("Barcode not unique")
	{
		CHECK_THROWS(data.addFriut("Apple", 100, 50, "Sady Sandomierz", "fghfh236", "Poland"));
	}
	SECTION("Deleate product")
	{
		data.deleteProduct("12345678");
		CHECK_NOTHROW(data.addFriut("Apple", 100, 50, "Sady Sandomierz", "12345678", "Poland"));
	}
	SECTION("Product not fund")
	{
		CHECK_THROWS(data.deleteProduct("ajajajaj"));
		CHECK_NOTHROW(data.deleteProduct("12312445"));
	}

	SECTION("4 elements in database")
	{
		CHECK_THROWS(data.addFriut("Apple", 100, 50, "Sady Sandomierz", "12345678", "Poland"));
		CHECK_THROWS(data.addJuice("Apple juice", 350, 70, "Sady Sandomierz", "fghfh236", 10, v));
		CHECK_THROWS(data.addMeat("Chicekn breast", 2000, 300, "Chicekn sp. zoo", "1724578", "Chicken"));
		CHECK_THROWS(data.addWhiskey("Whiskey 1", 5000, 170, "Gorzelina Namus³ów", "12312445", 35));
	}
}
*/