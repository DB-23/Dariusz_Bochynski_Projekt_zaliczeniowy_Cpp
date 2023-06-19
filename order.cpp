#include "order.h"


Order::Order()
{

}

Order::~Order()
{

}

vector<good2> Order::availableGoodies;

void Order::loadAvailableGoodies()
{
    QFile file(":/availableGoodies.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Blad otwarcia pliku availableGoodies.txt.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(';');
        if(parts.size() == 2)
        {
            good2 item;
            item.nazwa = parts[0].toStdString();
            item.ilosc = parts[1].toInt();
            availableGoodies.push_back(item);
        }
        else
        {
            qDebug() << "Blad wczytywania linii:" << line;
        }
    }

    file.close();
}

void Order::showAvailableGoodies()
{
    cout<<"Dostepne produkty:"<<endl;
    int i=0;
    for (const auto& item : availableGoodies)
    {
        cout<<i+1<<". Nazwa: "<<item.nazwa<<", Ilosc: "<<item.ilosc<<endl;
        i++;
    }
}

float Order::getCaleZamowienie() const
{
    return caleZamowienie;
}

string Order::getSposobPlatnosci() const
{
    return sposobPlatnosci;
}

good Order::getGood() const
{
    return Good;
}

myData Order::getDataZamowienia() const
{
    return dataZamowienia;
}


float getRandomPrice(float minPrice, float maxPrice)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(minPrice, maxPrice);
    return dis(gen);
}

float getRandomTax(float minTaxRate, float maxTaxRate) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(minTaxRate, maxTaxRate);
    return dis(gen);
}

void Order::createOder()
{
    cout<<"Podaj date zlozenia zamowienia: \n";
    cout<<"Podaj dzien: ";
    cin>>dataZamowienia.dzien;
    cout<<"Podaj miesiac: ";
    cin>>dataZamowienia.miesiac;
    cout<<"Podaj rok: ";
    cin>>dataZamowienia.rok;

    cout<<"\nPodaj sposob platnosci: ";
    cin>>this->sposobPlatnosci;

    showAvailableGoodies();
    int index;
    int ilosc;
    cout<<"Podaj numer produktu ktory chcesz dodac do zamowienia: ";
    cin>>index;
    cout<<"Podaj ilosc produktu ktory chcesz dodac do zamowienia: ";
    cin>>ilosc;
    if(availableGoodies[index-1].ilosc < ilosc)
    {
        cout<<availableGoodies[index-1].nazwa<<availableGoodies[index-1].ilosc;
        cout<<"\nBlad zamowienia: za duza ilosc!\n";
        return;
    }

    availableGoodies[index-1].ilosc -= ilosc;

    Good = {availableGoodies[index-1].nazwa,ilosc,getRandomPrice(1,100),getRandomTax(10,30)};
    caleZamowienie = ilosc * Good.cena;
    cout<<"Zamowienie kosztuje: "<<this->caleZamowienie<<"\n";
}

void Order::showOrder() const
{
    if(Good.nazwa == "")
        return;
    cout << "--------------------" <<endl;
    cout << "Zawartosc zamowienia:" <<endl;
    cout << "Nazwa: " << Good.nazwa <<endl;
    cout << "Ilosc: " << Good.ilosc <<endl;
    cout << "Cena: " << Good.cena << endl;
    cout << "Podatek: " << Good.podatek <<endl;

}


