#ifndef MESSAGINGCLIENT_H
#define MESSAGINGCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MessagingClient;
}

class MessagingClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MessagingClient(QWidget *parent = nullptr);
    ~MessagingClient();

private slots:
    void connectToServer();
    void disconnectFromServer();
    void sendMessage();
    void readMessage();
    void displayError(QAbstractSocket::SocketError socketError);
    void connectionEstablished();
    void connectionClosed();

private:
    Ui::MessagingClient *ui;
    QTcpSocket *socket;
    quint32 blockSize;

    void setupConnections();
    void setConnectionStatus(bool connected);
};

#endif
