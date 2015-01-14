#include "oknoglowne.h"
#include "ui_oknoglowne.h"


#include "hellowidget.h"
#include <QPushButton>


OknoGlowne::OknoGlowne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OknoGlowne)
{
    ui->setupUi(this);
    baton_ = new QPushButton(this);
    baton_->setGeometry(50, 50, 100, 25);
    baton_->setVisible(true);
    baton_->setText("Text");

    connect(baton_, SIGNAL(pressed()),
            this, SLOT(zmienTekst()));
    connect(baton_, SIGNAL(released()),
            this, SLOT(przywrocTekst()));

    connect(baton_, SIGNAL(clicked()),
            this, SLOT(hello()));
}


OknoGlowne::~OknoGlowne()
{
    delete ui;
}

void OknoGlowne::zmienTekst() {
    baton_->setText("KLIK");
}

void OknoGlowne::przywrocTekst() {
    baton_->setText("NIEKLIK");
}

void OknoGlowne::hello() {
    HelloWidget* okno = new HelloWidget(0, this);
    okno->show();
}

void OknoGlowne::przesunSlider(int wartosc) {
    ui->verticalSlider->setValue(wartosc);
}

void OknoGlowne::on_lineEdit_textChanged(const QString &arg1)
{
    this->setWindowTitle(arg1);
}
