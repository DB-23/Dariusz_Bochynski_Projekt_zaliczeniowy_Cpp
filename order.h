#ifndef ORDER_H
#define ORDER_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>


#include <QFile>
#include <QTextStream>
#include <QDebug>


using namespace std;


struct myData
{
    int dzien,miesiac,rok;
};


struct good //towar
{
    string nazwa;
    int ilosc;
    float cena;
    float podatek;
};


struct good2
{
    string nazwa;
    int ilosc;
};


class Order
{
    public:
        Order();
        ~Order();
        void createOder();
        void showOrder() const;
        static void loadAvailableGoodies();
        static void showAvailableGoodies();

        float getCaleZamowienie() const;
        string getSposobPlatnosci() const;

        good getGood() const;
        myData getDataZamowienia() const;

    private:
        good Good;
        static vector<good2> availableGoodies;
        myData dataZamowienia;
        float caleZamowienie;
        string sposobPlatnosci;
};

#endif // ORDER_H
