#include "clientcontroller.h"

ClientController::ClientController()
{

}

void ClientController::addClient(Client * client)
{
    this->listClient.push_back(client);
}

Client* ClientController::getClientAt(unsigned int index)
{
    if(index < this->listClient.size())
        return this->listClient[index];
    else
        return nullptr;
}

unsigned int ClientController::getClientCount()
{
    return this->listClient.size();
}



