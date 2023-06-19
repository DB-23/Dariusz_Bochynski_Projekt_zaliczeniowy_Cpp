#include <QCoreApplication>


#include "clientmanager.h"
#include "order.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Order::loadAvailableGoodies();
    //Order::showAvailableGoodies();

    clientManager manager;
    manager.addClient();
    manager.clients[0].addOrder();
    manager.clients[0].addOrder();
    manager.clients[0].showOrders();
    manager.saveToTxt(manager.clients, "wyniki.txt");
    //manager.saveToBinary();
    return a.exec();
}
