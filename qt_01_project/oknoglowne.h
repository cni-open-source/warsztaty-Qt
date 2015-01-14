#ifndef OKNOGLOWNE_H
#define OKNOGLOWNE_H

#include <QMainWindow>

namespace Ui {
class OknoGlowne;
}
class QPushButton;


class OknoGlowne : public QMainWindow
{
    Q_OBJECT

public:
    explicit OknoGlowne(QWidget *parent = 0);
    ~OknoGlowne();

    void setButton(QPushButton* but);
    void przesunSlider(int);


public slots:
    void zmienTekst();
    void przywrocTekst();
    void hello();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::OknoGlowne *ui;
    QPushButton* baton_;
};

#endif // OKNOGLOWNE_H
