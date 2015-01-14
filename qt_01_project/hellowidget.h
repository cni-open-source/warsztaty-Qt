#ifndef HELLOWIDGET_H
#define HELLOWIDGET_H

#include <QWidget>
#include "oknoglowne.h"

namespace Ui {
class HelloWidget;
}

class HelloWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HelloWidget(QWidget *parent,
                         OknoGlowne* oknoglowne);
    ~HelloWidget();

private slots:
    void on_dial_sliderMoved(int position);

private:
    Ui::HelloWidget *ui;
    OknoGlowne* main;
};

#endif // HELLOWIDGET_H
