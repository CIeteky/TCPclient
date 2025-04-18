QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    clienthandler.cpp \
    messagingclient.cpp

HEADERS += \
    clienthandler.h \
    messagingclient.h

FORMS += \
    messagingclient.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
