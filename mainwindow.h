#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTimer>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void timerslot();
    void sliderslot();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QTimer *myTimer;
};

#endif // MAINWINDOW_H
