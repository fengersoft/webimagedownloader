QT       += core gui network core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/api/http/htmlinfo.cpp \
    src/api/http/synchttp.cpp \
    src/api/http/synchttpobject.cpp \
    src/api/http/webimage.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/api/http/htmlinfo.h \
    src/api/http/synchttp.h \
    src/api/http/synchttpobject.h \
    src/api/http/webimage.h \
    src/mainwindow.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
DESTDIR=$$PWD/bin/
RC_ICONS=app.ico
