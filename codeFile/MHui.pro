QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    difficultychoosewindow.cpp \
    gowindow.cpp \
    helpwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton.cpp \
    normalwindow.cpp \
    normalwindow.cpp \
    rankdialog.cpp \
    isgoing.cpp \
    isback.cpp \
    playwindow2.cpp \
    resultwindow.cpp


HEADERS += \
    difficultychoosewindow.h \
    gowindow.h \
    helpwindow.h \
    mainwindow.h \
    mypushbutton.h \
    normalwindow.h \
    normalwindow.h \
    rankdialog.h \
    isgoing.h \
    isback.h \
    playwindow2.h \
    resultwindow.h

FORMS += \
    mainwindow.ui \
    normalwindow.ui \
    isgoing.ui \
    isback.ui \
    playwindow2.ui \
    rankdialog.ui \
    resultwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
