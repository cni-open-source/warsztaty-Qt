#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_timr = new QTimer();
    m_timr->setInterval(200);
    m_timr->start();

    connect(m_timr, SIGNAL(timeout()),
            this, SLOT(timerEvent()));

    ui->setupUi(this);

    m_wysObie = new QPlainTextEdit(this);
    m_zatw = new QPushButton(this);
    m_wybWyso = new QSpinBox(this);

    m_wybWyso->setGeometry(10, 10, 50, 30);
    m_wybWyso->setToolTip("Wysokość");
    m_wybWyso->setMinimum(3);
    m_wybWyso->setMaximum(12);

    m_zatw->setGeometry(10, 50, 50, 50);
    m_zatw->setText("Pokaż");

    m_wysObie->setGeometry(70, 10, 200, 300);
    m_wysObie->setFont(QFont("Courier"));
    m_wysObie->setReadOnly(true);

    connect(m_zatw, SIGNAL(clicked()),
            this, SLOT(rysuj()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rysuj() {
    unsigned wyso   = m_wybWyso->value();
    QString choinka = dajChoinke(wyso);

    m_wysObie->setPlainText(choinka);
}

QString MainWindow::dajChoinke(unsigned wyso) {
    QString drzewo;
    unsigned szer = (wyso-2)*2;
    unsigned srod = szer/2;
    for (unsigned i=0; i < wyso; ++i) {
        QString galaz(szer, ' ');
        if (0 == i) {
            galaz[srod] = '*';
        } else if (wyso - 1 == i) {
            galaz[srod] = 'W';
        } else {
            galaz[srod] = '|';
            for (unsigned j=1; j <= i; ++j) {
                galaz[srod - j] = 'x';
                galaz[srod + j] = 'x';
            }
        }
        drzewo += galaz + '\n';
    }
    return drzewo;
}


void MainWindow::timerEvent() {
    animujGwiazde();
}


void MainWindow::animujGwiazde() {
    static bool runda;
    QString text = m_wysObie->toPlainText();

    if (runda) {
        text.replace('o', '*');
        runda = 0;
    } else {
        text.replace('*', 'o');
        runda = 1;
    }

    m_wysObie->setPlainText(text);
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    m_timr->setInterval(arg1);
}
