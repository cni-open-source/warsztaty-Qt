#ifndef OKNO2_H
#define OKNO2_H

#include <QMainWindow>
#include <odbiornik.h>


namespace Ui {
class okno2;
}

class okno2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit okno2(QWidget *parent = 0);
    ~okno2();
    void ustawOdbiornik(Odbiornik* odb1);

private slots:
    void wyswietlWiadomosc(QString text);

private:
    Ui::okno2 *ui;
    Odbiornik* m_odbiornik;
};

#endif // OKNO2_H
