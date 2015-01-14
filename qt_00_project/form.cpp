#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


}

Form::~Form()
{
    delete ui;
}


void Form::setMain(QMainWindow *mwptr) {
    m_mainwindow = mwptr;
    connect(this->ui->toolButton, SIGNAL(clicked()),
            m_mainwindow, SLOT(close()));
}


void Form::radiobtn_clicked() {
    this->close();
}
