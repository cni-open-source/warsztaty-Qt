#include "hellowidget.h"
#include "ui_hellowidget.h"

HelloWidget::HelloWidget(QWidget *parent,
                         OknoGlowne *oknoglowne) :
    QWidget(parent),
    main(oknoglowne),
    ui(new Ui::HelloWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Hello");
}

HelloWidget::~HelloWidget()
{
    delete ui;
}

void HelloWidget::on_dial_sliderMoved(int position)
{
    ui->horizontalSlider->setValue(position);
    main->przesunSlider(position);
}
