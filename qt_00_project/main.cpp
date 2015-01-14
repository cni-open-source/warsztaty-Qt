#include "mainwindow.h"
#include "form.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    Form* okno = new Form();
    okno->setMain(&w);
    okno->show();

    return a.exec();
}

