#include <QApplication>
#include "messagingclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MessagingClient w;
    w.show();
    return a.exec();
}
