#ifndef SERVWINDOW_H
#define SERVWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class servWindow; }
QT_END_NAMESPACE

class servWindow : public QMainWindow
{
    Q_OBJECT

public:
    servWindow(QWidget *parent = nullptr);
    ~servWindow();

private:
    Ui::servWindow *ui;
};
#endif // SERVWINDOW_H
