#include "odbiornik.h"
#include <iostream>


Odbiornik::Odbiornik(QObject *parent) : QObject(parent)
{
}


Odbiornik::~Odbiornik()
{
}


void Odbiornik::odbierzSygnal()
{
}


void Odbiornik::odbierzWiadomosc()
{
}


void Odbiornik::odbierzWiadomosc(QString text)
{
    emit dostalemWiadomosc(text);
    std::cout << text.toStdString();
}
