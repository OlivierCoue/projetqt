#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include "client.h"

using namespace std;

class ClientController
{
private:
    vector<Client*> listClient;
public:
    ClientController();
    void addClient(Client * client);
    Client* getClientAt(unsigned int index);
    unsigned int getClientCount();
};

#endif // CLIENTCONTROLLER_H
