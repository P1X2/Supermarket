/*
#include "catch.hpp"
#include "Cashier.h"
#include "Employee.h"
#include "EmployeeAlreadyExistsException.h"
#include "EmployeeDoesNotExistException.h"
#include "Manager.h"
#include "Register.h"
#include "SalaryError.h"
#include "SecurityGuard.h"

using namespace std;


TEST_CASE("Employee tests", "[Employee]")
{
	Employee employee1("dawid", "filipiak", 160, 1);
	SECTION("Getters and Setters")
	{
		CHECK(employee1.get_name() == "dawid");
		CHECK(employee1.get_surname() == "filipiak");
		CHECK(employee1.get_hours() == 160);
		CHECK(employee1.get_id() == 1);
		
		employee1.set_hours(200);
		CHECK(employee1.get_hours() != 160);
		CHECK(employee1.get_hours() == 200);
		
		CHECK_THROWS(employee1.set_hours(20));
		CHECK_THROWS(employee1.set_hours(330));
	}
}

TEST_CASE("Manager tests","[Manager]")
{
	Manager manager1("dawid", "filipiak", 160, 1,80);
	CHECK(manager1.get_surname() == "filipiak");
	CHECK(manager1.get_name() == "dawid");
	CHECK(manager1.get_id() == 1);
	CHECK(manager1.calculate_salary() == 160 * 80);
	manager1.set_hours(200);
	CHECK(manager1.calculate_salary() == 160 * 80+40*100);
	CHECK_THROWS(manager1.set_money_per_hour(10));
	CHECK_THROWS(manager1.set_money_per_hour(1001));
}

TEST_CASE("Cashier tests", "[Cashier]")
{
	Cashier cashier1("dawid", "filipiak", 160, 1, 20);
	CHECK(cashier1.get_surname() == "filipiak");
	CHECK(cashier1.get_name() == "dawid");
	CHECK(cashier1.get_id() == 1);
	CHECK(cashier1.calculate_salary() == 160 * 20);
	cashier1.set_hours(200);
	CHECK(cashier1.calculate_salary() == 160 * 20 + 40 * 25);
	CHECK_THROWS(cashier1.set_money_per_hour(4));
	CHECK_THROWS(cashier1.set_money_per_hour(31));
}

TEST_CASE("Warehouseman tests", "[Warehouseman]")
{
	Warehouseman warehouseman1("dawid", "filipiak", 160, 1, 20);
	CHECK(warehouseman1.get_surname() == "filipiak");
	CHECK(warehouseman1.get_name() == "dawid");
	CHECK(warehouseman1.get_id() == 1);
	CHECK(warehouseman1.calculate_salary() == 160 * 20);
	warehouseman1.set_hours(200);
	CHECK(warehouseman1.calculate_salary() == 160 * 20 + 40 * 24);
	CHECK_THROWS(warehouseman1.set_money_per_hour(4));
	CHECK_THROWS(warehouseman1.set_money_per_hour(31));
}

TEST_CASE("SecurityGuard tests", "[SecurityGuard]")
{
	SecurityGuard securityguard11("dawid", "filipiak", 160, 1, 10);
	CHECK(securityguard11.get_surname() == "filipiak");
	CHECK(securityguard11.get_name() == "dawid");
	CHECK(securityguard11.get_id() == 1);
	CHECK(securityguard11.calculate_salary() == 160 * 10);
	securityguard11.set_hours(200);
	CHECK(securityguard11.calculate_salary() == 160 * 10 + 40 * 17);
	CHECK_THROWS(securityguard11.set_money_per_hour(9));
	CHECK_THROWS(securityguard11.set_money_per_hour(41));
}

TEST_CASE("Register tests", "[Register]")
{
	Register register1;
	SECTION("Cashier")
	{
		register1.add_cashier("dawid", "filipiak", 160, 1, 10);
		register1.add_cashier("kamil", "maciak", 200, 2, 10);
		register1.add_cashier("mariusz", "fer", 160, 3, 20);
		CHECK(register1.how_many_workers() == 3);
		CHECK(register1.in_register(3) == true);
		CHECK(register1.in_register(4) == false);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 15 + 160 * 20);

		register1.remove_employee(3);
		CHECK(register1.in_register(3) == false);
		CHECK(register1.how_many_workers() == 2);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 15);

		CHECK_THROWS(register1.add_cashier("dawid", "filipiak", 160, 2, 20));
		CHECK_THROWS(register1.add_cashier("dawid", "filipiak", 160, 10, 1000));
		CHECK_THROWS(register1.add_cashier("dawid", "filipiak", 140, 12, 20));
		CHECK_THROWS(register1.remove_employee(3));
	}

	SECTION("Manager")
	{
		register1.add_manager("dawid", "filipiak", 160, 4, 60);
		register1.add_manager("ewq", "filwqak", 300, 5, 100);
		CHECK(register1.how_many_workers() == 2);
		CHECK(register1.in_register(4) == true);
		CHECK(register1.in_register(2) == false);
		CHECK(register1.count_salaries() == 160*60+160*100+140*120);

		register1.remove_employee(4);
		CHECK(register1.in_register(4) == false);
		CHECK(register1.how_many_workers() == 1);
		CHECK(register1.count_salaries() == 160 * 100 + 140 * 120);

		CHECK_THROWS(register1.add_manager("dawid", "filipiak", 160, 5, 60));
		CHECK_THROWS(register1.add_manager("dawid", "filipiak", 160, 10, 20));
		CHECK_THROWS(register1.add_manager("dawid", "filipiak", 140, 12, 60));
		CHECK_THROWS(register1.remove_employee(4));
	}

	SECTION("SecurityGuard")
	{
		register1.add_security_guard("dawid", "filipiak", 160, 1, 10);
		register1.add_security_guard("kamil", "maciak", 200, 2, 10);
		register1.add_security_guard("mariusz", "fer", 160, 3, 20);
		CHECK(register1.how_many_workers() == 3);
		CHECK(register1.in_register(3) == true);
		CHECK(register1.in_register(4) == false);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 17 + 160 * 20);

		register1.remove_employee(3);
		CHECK(register1.in_register(3) == false);
		CHECK(register1.how_many_workers() == 2);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 17);

		CHECK_THROWS(register1.add_security_guard("dawid", "filipiak", 160, 2, 20));
		CHECK_THROWS(register1.add_security_guard("dawid", "filipiak", 160, 10, 60));
		CHECK_THROWS(register1.add_security_guard("dawid", "filipiak", 140, 12, 20));
		CHECK_THROWS(register1.remove_employee(3));
	}

	SECTION("Warehouseman")
	{
		register1.add_warehouseman("dawid", "filipiak", 160, 1, 10);
		register1.add_warehouseman("kamil", "maciak", 200, 2, 10);
		register1.add_warehouseman("mariusz", "fer", 160, 3, 20);
		CHECK(register1.how_many_workers() == 3);
		CHECK(register1.in_register(3) == true);
		CHECK(register1.in_register(4) == false);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 14 + 160 * 20);

		register1.remove_employee(3);
		CHECK(register1.in_register(3) == false);
		CHECK(register1.how_many_workers() == 2);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 14);

		CHECK_THROWS(register1.add_warehouseman("dawid", "filipiak", 160, 2, 20));
		CHECK_THROWS(register1.add_warehouseman("dawid", "filipiak", 160, 10, 31));
		CHECK_THROWS(register1.add_warehouseman("dawid", "filipiak", 140, 12, 20));
		CHECK_THROWS(register1.remove_employee(3));
	}

	SECTION("All together")
	{
		register1.add_cashier("dawid", "filipiak", 160, 1, 10);
		register1.add_cashier("kamil", "maciak", 200, 2, 10);
		register1.add_cashier("mariusz", "fer", 160, 3, 20);

		register1.add_manager("dawid", "filipiak", 160, 4, 60);
		register1.add_manager("ewq", "filwqak", 300, 5, 100);

		register1.add_security_guard("dawid", "filipiak", 160, 6, 10);
		register1.add_security_guard("kamil", "maciak", 200, 7, 10);
		register1.add_security_guard("mariusz", "fer", 160, 8, 20);

		register1.add_warehouseman("dawid", "filipiak", 160, 9, 10);
		register1.add_warehouseman("kamil", "maciak", 200, 10, 10);
		register1.add_warehouseman("mariusz", "fer", 160, 11, 20);

		CHECK(register1.how_many_workers() == 11);
		CHECK(register1.count_salaries() == 160 * 10 + 160 * 10 + 40 * 15 + 160 * 20 + 160 * 60 + 160 * 100 + 140 * 120 +
			160 * 10 + 160 * 10 + 40 * 17 + 160 * 20 + 160 * 10 + 160 * 10 + 40 * 14 + 160 * 20);

		register1.remove_employee(1);

		CHECK(register1.how_many_workers() == 10);
		CHECK(register1.count_salaries() == 160 * 10 + 40 * 15 + 160 * 20 + 160 * 60 + 160 * 100 + 140 * 120 +
			160 * 10 + 160 * 10 + 40 * 17 + 160 * 20 + 160 * 10 + 160 * 10 + 40 * 14 + 160 * 20);
		CHECK(register1.in_register(1) == false);
		CHECK(register1.in_register(2) == true);
		CHECK(register1.in_register(3) == true);
		CHECK(register1.in_register(4) == true);
		CHECK(register1.in_register(5) == true);
		CHECK(register1.in_register(6) == true);
		CHECK(register1.in_register(7) == true);
		CHECK(register1.in_register(8) == true);
		CHECK(register1.in_register(9) == true);
		CHECK(register1.in_register(10) == true);
		CHECK(register1.in_register(11) == true);

		CHECK_THROWS(register1.remove_employee(1));

		CHECK_THROWS(register1.add_manager("kamil", "maciak", 200, 2, 100));
		CHECK_THROWS(register1.add_cashier("kamil", "maciak", 200, 2, 10));
		CHECK_THROWS(register1.add_security_guard("kamil", "maciak", 200, 2, 10));
		CHECK_THROWS(register1.add_warehouseman("kamil", "maciak", 200, 2, 10));
	}
}
*/