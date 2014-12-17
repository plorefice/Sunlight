#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQuickView>
#include <QQuickItem>

#include "sunlightapp.h"

int main(int argc, char *argv[])
{
    SunlightApp app(argc, argv);

    return app.exec();
}
