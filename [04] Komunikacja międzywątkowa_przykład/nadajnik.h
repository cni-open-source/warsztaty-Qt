#ifndef NADAJNIK_H
#define NADAJNIK_H

#include <QObject>


class Nadajnik : public QObject
{
    Q_OBJECT
public:
    explicit Nadajnik(QObject *parent = 0);
    ~Nadajnik();

signals:
    void dajSygnal();
    void wyslijWiadomosc(QString);
};

#endif // NADAJNIK_H
