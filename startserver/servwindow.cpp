#include "servwindow.h"
#include "ui_servwindow.h"
#include "connection.h"




servWindow::servWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::servWindow)
{ 
    ui->setupUi(this);
    Server s;

}





servWindow::~servWindow()
{
    delete ui;
}

