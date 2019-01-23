#include "mainwindow.h"
#include "ui_mainwindow.h"


int running = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myTimer = new QTimer();
    myTimer->setInterval(1000);
    myTimer->setSingleShot(false);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(timerslot()));

    connect(ui->comboBoxH, SIGNAL(currentTextChanged(QString)), this, SLOT(sliderslot()));
    connect(ui->comboBoxM, SIGNAL(currentTextChanged(QString)), this, SLOT(sliderslot()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sliderslot()
{
    QString hours = ui->comboBoxH->currentText();
    QString minutes = ui->comboBoxM->currentText();

    int sliderminutes = hours.toInt()*60 + minutes.toInt();
    ui->horizontalSlider->setValue(sliderminutes);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString hours = QString::number(value/60, 'f', 0);
    int minutes = value-60*hours.toInt();

    ui->lcdnumberH->display(hours);
    ui->lcdnumberM->display(minutes);
}


void MainWindow::on_pushButton_clicked()
{
    if(myTimer->isActive() == false)
    {
        myTimer->start();
        MainWindow::ui->pushButton->setText("Stop");
    }

    else
    {
        myTimer->stop();
        MainWindow::ui->pushButton->setText("Los");
    }

}


void MainWindow::timerslot()
{
    int hours = MainWindow::ui->lcdnumberH->intValue();
    int minutes = MainWindow::ui->lcdnumberM->intValue();
    int seconds = MainWindow::ui->lcdnumberS->intValue();
    int strigger = hours+minutes+seconds;

    if (strigger == 0)
    {
        if(MainWindow::ui->comboBox->currentIndex()==0)
        {
            system("shutdown -P now");
        }

        if(MainWindow::ui->comboBox->currentIndex()==1)
        {
            system("reboot");
        }

        if(MainWindow::ui->comboBox->currentIndex()==2)
        {
            myTimer->stop();
            system("systemctl suspend");
        }
    }

    if (seconds == 0){
        if (minutes == 0){
            hours--;
            minutes = 59;
        }
        else{
            minutes--;
        }
        seconds = 59;
    }
    else
    {
        seconds--;
    }

    MainWindow::ui->lcdnumberH->display(hours);
    MainWindow::ui->lcdnumberM->display(minutes);
    MainWindow::ui->lcdnumberS->display(seconds);

    int sliderminutes = minutes + hours*60;
    ui->horizontalSlider->setValue(sliderminutes);

}


