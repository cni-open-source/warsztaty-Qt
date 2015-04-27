#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QStringList>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList lista;

    lista << "0" << "1" << "2" << "3"
          << "4" << "5" << "6" << "7"
          << "8" << "9" << "10" << "11";

    int j, k, l, m;
    j = k = l = m = 1;

    for (int i = 0; i < 12; i++) {
        QPushButton *btn = new QPushButton(this);
        if (j < 4) {
            btn->setGeometry(100*j,20,75,40);
        } else if (j < 7) {
            btn->setGeometry(300,75*k,75,40);
            k++;
        } else if (j < 10) {
            btn->setGeometry(100*(4-l),300,75,40);
            l++;
        } else if (j < 13) {
            btn->setGeometry(100,75*(4-m),75,40);
            m++;
        }
        connect(btn, SIGNAL(clicked()),
                this, SLOT(universal_slot()));
        btn->setText(lista[i]);
        btn->setObjectName(lista[i]);
        sm.setMapping(btn,lista[i]);
        j += 1;
    }
    sm.map();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dial_valueChanged(int value)
{
    for (int i = 0; i < 12; i++) {
        QString show = QString::number(i);
        QObject *obj = sm.mapping(show);
        QPushButton *btn = dynamic_cast<QPushButton*>(obj);

        btn->setVisible(true);
    }

    QString str = QString::number(value);
    QObject *obj = sm.mapping(str);
    QPushButton *btn = dynamic_cast<QPushButton*>(obj);

    btn->setVisible(false);
    ui->lcdNumber->display(ui->dial->value());
}


void MainWindow::universal_slot()
{
    QString str = sender()->objectName();
    QObject *obj = sm.mapping(str);
    QPushButton *btn = dynamic_cast<QPushButton*>(obj);

    btn->setVisible(false);
}

