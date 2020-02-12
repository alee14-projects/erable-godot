QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    about.cpp \
    library.cpp \
    main.cpp \
    player.cpp

HEADERS += \
    about.h \
    library.h \
    player.h

FORMS += \
    about.ui \
    player.ui

TRANSLATIONS += \
    translations/en_CA.ts \
    translations/fr_CA.ts \
    translations/vi_VN.ts


unix:!macx:!android {

    TARGET = AleePlayer

    target.path = /usr/bin

    desktop.path = /usr/share/applications
    desktop.files = AleePlayer.desktop

    icon.path = /usr/share/icons/hicolor/scalable/apps/
    icon.files = ALP.svg


    INSTALLS += target desktop icon
}


# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
