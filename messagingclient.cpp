#include "messagingclient.h"
#include "ui_messagingclient.h"
#include <QDateTime>
#include <QMessageBox>

MessagingClient::MessagingClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MessagingClient),
    blockSize(0)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    setupConnections();
    setConnectionStatus(false);
}

MessagingClient::~MessagingClient()
{
    delete ui;
}

void MessagingClient::setupConnections()
{

    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(ui->disconnectButton, SIGNAL(clicked()), this, SLOT(disconnectFromServer()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->messageInput, SIGNAL(returnPressed()), this, SLOT(sendMessage()));


    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(socket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void MessagingClient::connectToServer()
{
    QString hostname = ui->serverInput->text();
    int port = ui->portSpinBox->value();
    socket->connectToHost(hostname, port);
}

void MessagingClient::disconnectFromServer()
{
    socket->disconnectFromHost();
}

void MessagingClient::sendMessage()
{
    QString message = ui->messageInput->text().trimmed();

    if (message.isEmpty()) {
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);


    out << quint32(0);


    out << message;


    out.device()->seek(0);
    out << quint32(block.size() - sizeof(quint32));


    socket->write(block);


    ui->chatDisplay->append(QString("[%1] You: %2")
                                .arg(QDateTime::currentDateTime().toString("hh:mm:ss"))
                                .arg(message));


    ui->messageInput->clear();
}

void MessagingClient::readMessage()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_15);

    if (blockSize == 0) {

        if (socket->bytesAvailable() < static_cast<qint64>(sizeof(quint32))) {
            return;
        }

        in >> blockSize;
    }


    if (socket->bytesAvailable() < blockSize) {
        return;
    }

    QString message;
    in >> message;


    ui->chatDisplay->append(QString("[%1] Server: %2")
                                .arg(QDateTime::currentDateTime().toString("hh:mm:ss"))
                                .arg(message));


    blockSize = 0;
}

void MessagingClient::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Client"),
                                 tr("The host was not found. Please check the host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Client"),
                                 tr("The connection was refused by the peer. Make sure the server is running."));
        break;
    default:
        QMessageBox::information(this, tr("Client"),
                                 tr("The following error occurred: %1.")
                                     .arg(socket->errorString()));
    }

    setConnectionStatus(false);
}

void MessagingClient::connectionEstablished()
{
    ui->chatDisplay->append(tr("Connected to server at %1")
                                .arg(QDateTime::currentDateTime().toString()));
    setConnectionStatus(true);

    QString username = ui->usernameInput->text().trimmed();
    if (!username.isEmpty()) {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_15);
        out << quint32(0);
        out << QString("/name %1").arg(username);
        out.device()->seek(0);
        out << quint32(block.size() - sizeof(quint32));
        socket->write(block);
    }
}

void MessagingClient::connectionClosed()
{
    ui->chatDisplay->append(tr("Disconnected from server at %1")
                                .arg(QDateTime::currentDateTime().toString()));
    setConnectionStatus(false);
}

void MessagingClient::setConnectionStatus(bool connected)
{
    ui->connectButton->setEnabled(!connected);
    ui->disconnectButton->setEnabled(connected);
    ui->serverInput->setEnabled(!connected);
    ui->portSpinBox->setEnabled(!connected);
    ui->usernameInput->setEnabled(!connected);
    ui->sendButton->setEnabled(connected);
    ui->messageInput->setEnabled(connected);

    if (connected) {
        ui->statusLabel->setText(tr("Connected to %1:%2")
                                     .arg(ui->serverInput->text())
                                     .arg(ui->portSpinBox->value()));
    } else {
        ui->statusLabel->setText(tr("Disconnected"));
    }
}
