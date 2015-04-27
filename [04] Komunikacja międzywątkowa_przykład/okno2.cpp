#include "okno2.h"
#include "ui_okno2.h"


okno2::okno2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::okno2)
{
    ui->setupUi(this);
}


okno2::~okno2()
{
    delete ui;
}


void okno2::ustawOdbiornik(Odbiornik *odb1)
{
    m_odbiornik = odb1;
    QObject::connect(m_odbiornik, SIGNAL(dostalemWiadomosc(QString)),
                     this, SLOT(wyswietlWiadomosc(QString)));
}


void okno2::wyswietlWiadomosc(QString text)
{
    ui->textEdit->setPlainText(text);
}
