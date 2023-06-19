#include "clientmanager.h"

clientManager::clientManager()
{

}

clientManager::~clientManager()
{

}

void clientManager::showClients()
{
    int i=0;
    for(const auto& client : clients)
    {

        cout<<"+===KLIENT "<<i+1<<"===+\n";
        client.showClient();
        i++;
    }
}

void clientManager::addClient()
{
    string imie,nazwisko,adres;
    int wiek;
    char plec;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj adres: (bez spacji)";
    cin>>adres;
    cout<<"Podaj wiek: ";
    cin>>wiek;
    cout<<"Podaj plec(m - mezczyzna, k - kobieta): ";
    cin>>plec;
    clients.push_back(Client(imie, nazwisko, adres, wiek, plec));
}

void clientManager::removeClient()
{
    showClients();
    int index;
    cout<<"Podaj ktorego klienta chcesz usunac: ";
    cin>>index;
    clients.erase(clients.begin() + index-1);
}

void clientManager::editClient()
{
    showClients();
    int index;
    cout<<"Podaj ktorego klienta chcesz edytowac: ";
    cin>>index;
    clients.at(index-1).editClient();
}


void clientManager::saveToTxt(const vector<Client>& clients, const string& filename)
{

    ofstream file(filename);
    if (!file) {
        cout << "Błąd otwarcia pliku" << endl;
            return;
    }

    for (const auto& client : clients) {
        file << "Klient: " << client.getImie() << " " << client.getNazwisko() << endl;
        file << "Zamówienia:" << endl;

        for (const auto& order : client.getZamowienia())
        {
            file << "Data zamówienia: " << order.getDataZamowienia().dzien << "." << order.getDataZamowienia().miesiac << "." << order.getDataZamowienia().rok << endl;
            file << "Cena zamówienia: " << order.getCaleZamowienie() << endl;
            file << "Sposób płatności: " << order.getSposobPlatnosci() << endl;
            file << endl;
        }
        file << "----------------------------------------" << endl;
    }

    file.close();
    cout << "Zapisano zamówienia do pliku: " << filename << endl;

}

/*void clientManager::saveToBinary(const vector<Client>& clients, const string& filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Błąd otwarcia pliku" << endl;
            return;
    }

    for (const auto& client : clients)
    {
        // Zapisanie danych klienta
        int imieLength = client.getImie().length();
        file.write(reinterpret_cast<const char*>(&imieLength), sizeof(int));
        file.write(client.getImie().c_str(), imieLength);

        int nazwiskoLength = client.getNazwisko().length();
        file.write(reinterpret_cast<const char*>(&nazwiskoLength), sizeof(int));
        file.write(client.getNazwisko().c_str(), nazwiskoLength);

        int adresLength = client.getAdres().length();
        file.write(reinterpret_cast<const char*>(&adresLength), sizeof(int));
        file.write(client.getAdres().c_str(), adresLength);

        file.write(reinterpret_cast<const char*>(&client.getWiek()), sizeof(int));
        file.write(reinterpret_cast<const char*>(&client.getPlec()), sizeof(char));

        // Zapisanie danych zamówień klienta
        int numOrders = client.getZamowienia().size();
        file.write(reinterpret_cast<const char*>(&numOrders), sizeof(int));

        for (const auto& order : client.getZamowienia())
        {
            file.write(reinterpret_cast<const char*>(&order.getDataZamowienia()), sizeof(myData));
            file.write(reinterpret_cast<const char*>(&order.getCaleZamowienie()), sizeof(float));

            int sposobPlatnosciLength = order.getSposobPlatnosci().length();
            file.write(reinterpret_cast<const char*>(&sposobPlatnosciLength), sizeof(int));
            file.write(order.getSposobPlatnosci().c_str(), sposobPlatnosciLength);
        }
    }

    file.close();
    cout << "Zapisano dane do pliku binarnego: " << filename << endl;
}*/
