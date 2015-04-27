#include "mainwindow.h"
#include <QApplication>
#include <okno1.h>
#include <okno2.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    okno1* o1 = new okno1(&w);
    okno2* o2 = new okno2(&w);
    Nadajnik* n1 = new Nadajnik();
    Odbiornik* odb1 = new Odbiornik();

    QObject::connect(n1, SIGNAL(dajSygnal()),
                     odb1, SLOT(odbierzSygnal()));
    QObject::connect(n1, SIGNAL(wyslijWiadomosc(QString)),
                     odb1, SLOT(odbierzWiadomosc(QString)));

    o1->ustawNadajnik(n1);
    o2->ustawOdbiornik(odb1);

    o1->show();
    o2->show();

    return a.exec();
}
