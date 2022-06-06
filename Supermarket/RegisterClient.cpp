#include "RegisterClient.h"

void RegisterClient::add_client(Client client)
{
	clients.push_back(client);
}

vector<Client> RegisterClient::get_clients()
{
	return clients;
}

void RegisterClient::set_clients(vector<Client> clients)
{
	this->clients = clients;
}

void RegisterClient::pass_time_unit()
{
	for (Client cl : clients)
	{
		cl.set_busy(cl.get_busy() - 1);
	}
}

ostream& operator<<(ostream& os, RegisterClient& rc)
{
	for (Client cl : rc.clients)
	{
		os << cl;
	}
	return os;
}