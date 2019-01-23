#include "mainwindow.h"
#include "ui_mainwindow.h"

int i=1;

int countdown(int h, int m)
{

        if (m == 0){
            h--;
            m = 59;
        }
        else{
            m--;
        }



        QThread::sleep(1);

        return(h, m);

//        i = minutes+hours;

}
