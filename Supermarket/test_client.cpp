//#include "Employees/catch.hpp"
//#include "Client.h"
//#include "products/Friut.h"
//#include "products/Juice.h"
//#include "products/Meat.h"
//#include "products/Whiskey.h"
//
//
//TEST_CASE("Client tests")
//{
//	Fruit a("Apple", 100, 50, "Sady Sandomierz", "12345678", "Poland");
//	Meat b("Chicken breast", 2000, 300, "Chicekn sp. zoo", "1724578", "Chicken");
//	Whiskey c("Whiskey 1", 5000, 170, "Gorzelina", "12312445", 35);
//	Juice d("Apple juice", 350, 70, "Sady Sandomierz", "fghfh236", 10);
//	vector<string> vec = { a.getName(),b.getName(),c.getName(),d.getName() };
//	Address adr("as", "sa", "as", 12);
//	Client cl("asd","sa",12,vec,adr,true);
//	CHECK(cl.get_name() == "asd");
//	CHECK(cl.get_is_done() == false);
//	CHECK(cl.get_is_w8ting() == false);
//	CHECK(cl.get_recipe() == true);
//	CHECK(cl.get_shopping_list() == vec);
//	CHECK(cl.get_activity() == "");
//	CHECK(cl.get_currently_serched_prd() == 0);
//	cl.update_currently_serched_product();
//	CHECK(cl.get_currently_serched_prd() == 1);
//}