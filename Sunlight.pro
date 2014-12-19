TEMPLATE = app

QT       += qml quick widgets winextras
QTPLUGIN += qsvg

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

QMAKE_CXXFLAGS += -Wall

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

# Include sub-directories
include(core/core.pri)
include(gui/gui.pri)
