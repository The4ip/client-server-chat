#include "connection.h"
#include "servwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    servWindow w;
    Server s;


     w.show();

    return a.exec();
}


