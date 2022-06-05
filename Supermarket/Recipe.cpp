#include "Recipe.h"


Recipe::Recipe(vector<Product> products) : Bill(products) {}

int Recipe::get_price_with_vat(Product prod)
{
	return prod.getPrice() * (prod.get_vat() / 100 + 1);
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

void Recipe::print_bill()
{
	cout << endl << "            Recipe" << endl;
	cout << "_________________________________" << endl;
	cout << "           Products:" << endl;
	for (Product prod : get_products())
	{
		cout << prod.getName() << ": " << get_price_with_vat(prod)/100 << " zl" << endl;
	}
	cout << "Summary: " << count_total() << " zl" << endl;
	cout << "_________________________________" << endl;
}