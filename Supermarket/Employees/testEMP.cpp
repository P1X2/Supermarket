//
//#include "catch.hpp"
//#include "Cashier.h"
//#include "Employee.h"
//#include "Warehouseman.h"
//#include "EmployeeAlreadyExistsException.h"
//#include "EmployeeDoesNotExistException.h"
//#include "SalaryError.h"
//#include "RegisterCashiers.h"
//#include "RegisterWarehouseman.h"
//
//using namespace std;
//
//
//TEST_CASE("Employee tests", "[Employee]")
//{
//	Employee employee1("dawid", "filipiak", 160, 1);
//	SECTION("Getters and Setters")
//	{
//		CHECK(employee1.get_name() == "dawid");
//		CHECK(employee1.get_surname() == "filipiak");
//		CHECK(employee1.get_hours() == 160);
//		CHECK(employee1.get_id() == 1);
//		
//		employee1.set_hours(200);
//		CHECK(employee1.get_hours() != 160);
//		CHECK(employee1.get_hours() == 200);
//		
//		CHECK_THROWS(employee1.set_hours(20));
//		CHECK_THROWS(employee1.set_hours(330));
//	}
//}
//
//TEST_CASE("Cashier tests", "[Cashier]")
//{
//	Cashier cashier1("dawid", "filipiak", 160, 1, 20);
//	CHECK(cashier1.get_surname() == "filipiak");
//	CHECK(cashier1.get_name() == "dawid");
//	CHECK(cashier1.get_id() == 1);
//	CHECK(cashier1.calculate_salary() == 160 * 20);
//	cashier1.set_hours(200);
//	CHECK(cashier1.calculate_salary() == 160 * 20 + 40 * 25);
//	CHECK_THROWS(cashier1.set_money_per_hour(4));
//	CHECK_THROWS(cashier1.set_money_per_hour(100));
//}
//
//TEST_CASE("Warehouseman tests", "[Warehouseman]")
//{
//	Warehouseman warehouseman1("dawid", "filipiak", 160, 1, 20);
//	CHECK(warehouseman1.get_surname() == "filipiak");
//	CHECK(warehouseman1.get_name() == "dawid");
//	CHECK(warehouseman1.get_id() == 1);
//	CHECK(warehouseman1.calculate_salary() == 160 * 20);
//	warehouseman1.set_hours(200);
//	CHECK(warehouseman1.calculate_salary() == 160 * 20 + 40 * 24);
//	CHECK_THROWS(warehouseman1.set_money_per_hour(4));
//	CHECK_THROWS(warehouseman1.set_money_per_hour(100));
//}
//
//TEST_CASE("Register tests", "[Register]")
//{
//	SECTION("Cashier")
//	{
//		RegisterCashiers register1;
//		register1.add_cashier("dawid", "filipiak", 160, 1, 16);
//		register1.add_cashier("kamil", "maciak", 200, 2, 16);
//		register1.add_cashier("mariusz", "fer", 160, 3, 20);
//		CHECK(register1.how_many_workers() == 3);
//		CHECK(register1.in_register(3) == true);
//		CHECK(register1.in_register(4) == false);
//		CHECK(register1.count_salaries() == 160 * 16 + 160 * 16 + 40 * 21 + 160 * 20);
//
//		register1.remove_employee(3);
//		CHECK(register1.in_register(3) == false);
//		CHECK(register1.how_many_workers() == 2);
//		CHECK(register1.count_salaries() == 160 * 16 + 160 * 16 + 40 * 21);
//
//		CHECK_THROWS(register1.add_cashier("dawid", "filipiak", 160, 2, 20));
//		CHECK_THROWS(register1.add_cashier("dawid", "filipiak", 160, 10, 1000));
//		CHECK_THROWS(register1.add_cashier("dawid", "filipiak", 140, 12, 20));
//		CHECK_THROWS(register1.remove_employee(3));
//	}
//
//	SECTION("Warehouseman")
//	{
//		RegisterWarehouseman register1;
//		register1.add_warehouseman("dawid", "filipiak", 160, 1, 10);
//		register1.add_warehouseman("kamil", "maciak", 200, 2, 10);
//		register1.add_warehouseman("mariusz", "fer", 160, 3, 20);
//		CHECK(register1.how_many_workers() == 3);
//		CHECK(register1.in_register(3) == true);
//		CHECK(register1.in_register(4) == false);
//		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 14 + 160 * 20);
//
//		register1.remove_employee(3);
//		CHECK(register1.in_register(3) == false);
//		CHECK(register1.how_many_workers() == 2);
//		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 14);
//
//		CHECK_THROWS(register1.add_warehouseman("dawid", "filipiak", 160, 2, 22));
//		CHECK_THROWS(register1.add_warehouseman("dawid", "filipiak", 160, 10, 31));
//		CHECK_THROWS(register1.add_warehouseman("dawid", "filipiak", 140, 12, 20));
//		CHECK_THROWS(register1.remove_employee(3));
//	}
//}
