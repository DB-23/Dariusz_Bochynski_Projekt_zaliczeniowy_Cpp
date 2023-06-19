#include "client.h"

Client::Client()
{

}

Client::~Client()
{

}

void Client::showClient() const
{
    cout<<"Imie: "<<this->imie<<"\n";
    cout<<"Nazwisko: "<<this->nazwisko<<"\n";
    cout<<"Adres: "<<this->adres<<"\n";
    cout<<"wiek: "<<this->wiek<<"plec: "<<this->plec<<"\n";
}

void Client::editClient()
{
    cout<<"Podaj imie: ";
    cin>>this->imie;
    cout<<"Podaj nazwisko: ";
    cin>>this->nazwisko;
    cout<<"Podaj adres: (bez spacji)";
    cin>>this->adres;
    cout<<"Podaj wiek: ";
    cin>>this->wiek;
    cout<<"Podaj plec(m - mezczyzna, k - kobieta): ";
    cin>>this->plec;
}

void Client::addOrder()
{
    Order zamowienie;
    zamowienie.createOder();
    zamowienia.push_back(zamowienie);
}

void Client::showOrders()
{
    cout << "Zamowienia klienta: " << imie << " " << nazwisko <<endl;
    for(const auto& order : zamowienia)
    {
        order.showOrder();
        cout << "--------------------" <<endl;
    }
}

string Client::getImie() const
{
    return imie;
}

string Client::getNazwisko() const
{
    return nazwisko;
}

string Client::getAdres() const
{
    return adres;
}

int Client::getWiek() const
{
    return wiek;
}

char Client::getPlec() const
{
    return plec;
}

vector<Order> Client::getZamowienia() const
{
    return this->zamowienia;
}

