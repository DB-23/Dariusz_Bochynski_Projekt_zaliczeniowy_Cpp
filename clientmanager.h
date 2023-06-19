#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H


#include <vector>


#include "client.h"


class clientManager
{
    public:
        clientManager();
        ~clientManager();

        void showClients();
        void addClient();
        void removeClient();
        void editClient();
        void saveToTxt(const vector<Client>& clients, const string& filename);
        void saveToBinary();
        vector<Client> clients;

    private:
        //vector<Client> clients;
};

#endif // CLIENTMANAGER_H
