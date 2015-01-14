#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPlainTextEdit;
class QPushButton;
class QSpinBox;

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
    void timerEvent(QTimerEvent *);

protected:
    QString dajChoinke(unsigned wyso);

private:
    Ui::MainWindow *ui;
    QPlainTextEdit *m_wysObie; // wyswietlajacy obiekt
    QPushButton *m_zatw; // zatwierdzacz
    QSpinBox *m_wybWyso; // wybieracz wysokosci
};

#endif // MAINWINDOW_H
