#ifndef OKNO1_H
#define OKNO1_H

#include <QMainWindow>
#include <nadajnik.h>


namespace Ui {
class okno1;
}

class okno1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit okno1(QWidget *parent = 0);
    ~okno1();
    void ustawNadajnik(Nadajnik* n1);

private slots:
    void on_pushButton_clicked();
    void on_textEdit_textChanged();

private:
    Ui::okno1 *ui;
    Nadajnik* m_nadajnik;
};

#endif // OKNO1_H
