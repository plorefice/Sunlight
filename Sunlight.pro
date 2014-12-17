TEMPLATE = app

QT += qml quick widgets winextras

CONFIG += c++11

SOURCES += main.cpp \
    sunlightapp.cpp \
    launcherwidget.cpp \
    suggestionlist.cpp \
    suggestion.cpp \
    suggestionmanager.cpp \
    eventdispatcher.cpp \
    appiconprovider.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    sunlightapp.h \
    launcherwidget.h \
    suggestionlist.h \
    suggestion.h \
    suggestionmanager.h \
    eventdispatcher.h \
    appiconprovider.h
