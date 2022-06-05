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
	void add_client(Client);
	void pass_time_unit();
};

//przeci¹¿yæ operator
ostream operator<<(ostream&, RegisterClient&);