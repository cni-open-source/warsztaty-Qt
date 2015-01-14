#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList sl;
    sl << "Jeden" << "Dwa" << "Trzy"
          << "Cztery" << "Pięć" << "Sześć";

    QObject *obj;
    for (int i=0; i < 6; ++i) {
        QPushButton *btn = new QPushButton(this);
        btn->setGeometry(i*100, 20, 75, 40);
        btn->setText(sl[i]);

        connect(btn, SIGNAL(clicked()),
                this, SLOT(universal_slot()));

        btn->setObjectName(sl[i]);
        obj = btn;
        sm.setMapping(btn, sl[i]);
    }

    sm.map();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::universal_slot() {
    QString str = sender()->objectName();
    QObject *obj = sm.mapping(str);
    QPushButton *btn =
        dynamic_cast<QPushButton*>(obj);

    btn->setText(btn->text() + "!");
}
