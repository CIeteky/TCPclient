#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QTcpSocket>

class ClientHandler : public QObject
{
    Q_OBJECT

public:
    explicit ClientHandler(int id, QTcpSocket *socket, QObject *parent = nullptr);
    ~ClientHandler();

    void sendMessage(const QString &message);
    void disconnectClient();

signals:
    void messageReceived(const QString &sender, const QString &message);
    void clientDisconnected(int clientId);

private slots:
    void readMessage();
    void handleDisconnection();

private:
    int clientId;
    QTcpSocket *clientSocket;
    QString clientName;
    QByteArray buffer;
};

#endif
