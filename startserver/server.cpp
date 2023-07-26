#include "connection.h"
int ort;


Server::Server()
{
  if(this->listen(QHostAddress::Any,2323))
  {
      qDebug()<<"started server syka blyat\n";
  }
  else
  {
      qDebug()<<"error syka blyat";
  }
}

//приемка сокетов

void Server::incomingConnection(qintptr socketDescriptor)
{
  socket= new QTcpSocket;
  socket->setSocketDescriptor(socketDescriptor);
  connect(socket, &QTcpSocket::readyRead,this,&Server::slotReadyRead);
  connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

  Sockets.push_back(socket);
  qDebug()<<"syka blyat client connected"<<socketDescriptor;


}

//подключение к клиенту и проверка

void Server::slotReadyRead()
{

  socket=(QTcpSocket*)sender();
  QDataStream in(socket);
  in.setVersion(QDataStream::Qt_6_3);
  if(in.status()==QDataStream::Ok)
  {
              qDebug()<<"read..";
              QString str;
              in>>str;
              qDebug()<<ort<<" > "<<str;
              //str=str+"<";
             // QString s = QString::number(ort);
             // str=str.append(s);
              SendToClient(str);

  }
  else
  {
      qDebug()<<"DataStream eror";
  }
}

//отправка сокетов клиенту
void Server::SendToClient(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out<<str;

    //socket->write(Data); отправит только одному клиенту
    for (int i=0; i<Sockets.size();i++)
    {
        Sockets[i]->write(Data);
    }
}

void Start_DB(){

}
