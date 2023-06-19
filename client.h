#ifndef CLIENT_H
#define CLIENT_H


#include "order.h"


#include <iostream>
#include <string>


using namespace std;


class Client
{
public:
    Client();
    Client(string imie, string nazwisko, string adres, int wiek, char plec): imie(imie), nazwisko(nazwisko), adres(adres), wiek(wiek), plec(plec){};
    ~Client();

    void showClient() const;
    void editClient();
    void addOrder();
    void showOrders();

    string getImie() const;
    string getNazwisko() const;
    string getAdres() const;
    int getWiek() const;
    char getPlec() const;
    vector<Order> getZamowienia() const;

private:
    string imie;
    string nazwisko;
    string adres;
    int wiek;
    char plec;
    vector<Order> zamowienia;
};


#endif // CLIENT_H
