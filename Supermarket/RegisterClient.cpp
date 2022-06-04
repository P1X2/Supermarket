#include "RegisterClient.h"

void RegisterClient::add_client(Client cl)
{
	clients.push_back(cl);
}

vector<Client> RegisterClient::get_clients()
{
	return clients;
}

void RegisterClient::pass_time_unit()
{
	for (Client cl : clients)
	{
		cl.set_busy(cl.get_busy() - 1);
	}
}