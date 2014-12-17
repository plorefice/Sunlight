#ifndef SUNLIGHTAPP_H
#define SUNLIGHTAPP_H

#include <QApplication>
#include <QSystemTrayIcon>

#include "launcherwidget.h"

class SunlightApp : public QApplication
{
    Q_OBJECT
private:
    LauncherWidget *m_launcherWidget;
    QSystemTrayIcon *m_trayIcon;

    void createTrayIcon();

public:
    SunlightApp(int argc, char *argv[]);
    ~SunlightApp();

signals:

public slots:

};

#endif // SUNLIGHTAPP_H
