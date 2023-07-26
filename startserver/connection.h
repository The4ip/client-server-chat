#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QTcpServer>//для подключения
#include <QTcpSocket>
#include <QVector>
#include <QTableView>


class Server:public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;


private:
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    void SendToClient(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};



#endif // CONNECTION_H
