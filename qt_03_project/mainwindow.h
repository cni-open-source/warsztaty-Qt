#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPlainTextEdit;
class QPushButton;
class QSpinBox;
class QTimer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void rysuj();
    void animujGwiazde();
    void timerEvent();

protected:
    QString dajChoinke(unsigned wyso);

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QPlainTextEdit *m_wysObie; // wyswietlajacy obiekt
    QPushButton *m_zatw; // zatwierdzacz
    QSpinBox *m_wybWyso; // wybieracz wysokosci
    QTimer *m_timr;
};

#endif // MAINWINDOW_H
