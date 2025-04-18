/********************************************************************************
** Form generated from reading UI file 'messagingclient.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGINGCLIENT_H
#define UI_MESSAGINGCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagingClient
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *serverInput;
    QLabel *label_2;
    QSpinBox *portSpinBox;
    QLabel *label_3;
    QLineEdit *usernameInput;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QLabel *statusLabel;
    QTextEdit *chatDisplay;
    QHBoxLayout *horizontalLayout;
    QLineEdit *messageInput;
    QPushButton *sendButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MessagingClient)
    {
        if (MessagingClient->objectName().isEmpty())
            MessagingClient->setObjectName("MessagingClient");
        MessagingClient->resize(500, 500);
        centralwidget = new QWidget(MessagingClient);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        serverInput = new QLineEdit(centralwidget);
        serverInput->setObjectName("serverInput");

        gridLayout->addWidget(serverInput, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        portSpinBox = new QSpinBox(centralwidget);
        portSpinBox->setObjectName("portSpinBox");
        portSpinBox->setMinimum(1024);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(8080);

        gridLayout->addWidget(portSpinBox, 0, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        usernameInput = new QLineEdit(centralwidget);
        usernameInput->setObjectName("usernameInput");

        gridLayout->addWidget(usernameInput, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");

        horizontalLayout_2->addWidget(connectButton);

        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName("disconnectButton");

        horizontalLayout_2->addWidget(disconnectButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 2);


        verticalLayout->addLayout(gridLayout);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        chatDisplay = new QTextEdit(centralwidget);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setReadOnly(true);

        verticalLayout->addWidget(chatDisplay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        messageInput = new QLineEdit(centralwidget);
        messageInput->setObjectName("messageInput");
        messageInput->setEnabled(false);

        horizontalLayout->addWidget(messageInput);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setEnabled(false);

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);

        MessagingClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MessagingClient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 22));
        MessagingClient->setMenuBar(menubar);
        statusbar = new QStatusBar(MessagingClient);
        statusbar->setObjectName("statusbar");
        MessagingClient->setStatusBar(statusbar);

        retranslateUi(MessagingClient);

        QMetaObject::connectSlotsByName(MessagingClient);
    } // setupUi

    void retranslateUi(QMainWindow *MessagingClient)
    {
        MessagingClient->setWindowTitle(QCoreApplication::translate("MessagingClient", "Qt Messaging Client", nullptr));
        label->setText(QCoreApplication::translate("MessagingClient", "Server:", nullptr));
        serverInput->setText(QCoreApplication::translate("MessagingClient", "localhost", nullptr));
        label_2->setText(QCoreApplication::translate("MessagingClient", "Port:", nullptr));
        label_3->setText(QCoreApplication::translate("MessagingClient", "Username:", nullptr));
        connectButton->setText(QCoreApplication::translate("MessagingClient", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MessagingClient", "Disconnect", nullptr));
        statusLabel->setText(QCoreApplication::translate("MessagingClient", "Disconnected", nullptr));
        messageInput->setPlaceholderText(QCoreApplication::translate("MessagingClient", "Type a message...", nullptr));
        sendButton->setText(QCoreApplication::translate("MessagingClient", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagingClient: public Ui_MessagingClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGINGCLIENT_H
