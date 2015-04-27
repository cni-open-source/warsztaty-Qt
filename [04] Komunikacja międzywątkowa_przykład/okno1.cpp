#include "okno1.h"
#include "ui_okno1.h"


okno1::okno1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::okno1)
{
    ui->setupUi(this);
}


okno1::~okno1()
{
    delete ui;
}


void okno1::ustawNadajnik(Nadajnik *n1)
{
    m_nadajnik = n1;
}


void okno1::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    m_nadajnik->wyslijWiadomosc(text);
}


void okno1::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    m_nadajnik->wyslijWiadomosc(text);
}
