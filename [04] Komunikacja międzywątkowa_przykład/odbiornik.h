#ifndef ODBIORNIK_H
#define ODBIORNIK_H

#include <QObject>


class Odbiornik : public QObject
{
    Q_OBJECT
public:
    explicit Odbiornik(QObject *parent = 0);
    ~Odbiornik();

signals:
    void dostalemWiadomosc(QString);

public slots:
    void odbierzSygnal();
    void odbierzWiadomosc();
    void odbierzWiadomosc(QString);
};

#endif // ODBIORNIK_H
