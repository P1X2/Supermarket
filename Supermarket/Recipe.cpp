#include "Recipe.h"



Recipe::Recipe(vector<Product> products) : Bill(products) {}

float Recipe::get_price_with_vat(Product prod)
{
	float vat = prod.get_vat();
	return round(((prod.getPrice() + prod.getPrice() * (vat / 100)) / 100));
}

int Recipe::count_total()
{
	int total=0;
	for (Product prod : get_products())
	{
		total = total + get_price_with_vat(prod);
	}
	return total;
}

ostream& Recipe::operator<<(ostream& os)
{
	os << endl << "            Recipe" << endl;
	os << "_________________________________" << endl;
	os << "           Products:" << endl;
	for (Product prod : get_products())
	{
		os << prod.getName() << ": " << get_price_with_vat(prod) << " zl" << endl;
	}
	os << "Summary: " << count_total() << " zl" << endl;
	os << "_________________________________" << endl;
	return os;
}