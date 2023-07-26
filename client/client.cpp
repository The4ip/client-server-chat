#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    socket= new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

Client::~Client()
{
    delete ui;
}


void Client::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
}

void Client::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out<<str;
    socket->write(Data);
}

void Client::slotReadyRead()
{
    socket=(QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_3);
    if(in.status()==QDataStream::Ok)
    {
                qDebug()<<"read..";
                QString str;
                in>>str;
                ui->textBrowser->append(str);

    }
    else
    {
        qDebug()<<"DataStream eror";
    }
}


void Client::on_pushButton_2_clicked()
{
    SendToServer(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void Client::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
      ui->lineEdit->clear();
}

