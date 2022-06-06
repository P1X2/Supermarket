#pragma once
#include <vector>
#include "Client.h"
#include <ostream>


using namespace std;
class RegisterClient
{
	vector<Client> clients;
public:
	vector<Client> get_clients();
	void set_clients(vector<Client> clients);
	void add_client(Client client);
	void pass_time_unit();

	friend class Supermarket_sandbox;
	friend class Supermarket;
	
	friend ostream& operator<<(ostream& os , RegisterClient& rc);
};

//przeci¹¿yæ operator
