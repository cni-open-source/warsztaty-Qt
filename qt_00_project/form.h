#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void setMain(QMainWindow*);


public slots:
    void radiobtn_clicked();

public:
    Ui::Form *ui;
    QMainWindow *m_mainwindow;
};

#endif // FORM_H
