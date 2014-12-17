#ifndef SUNLIGHTAPP_H
#define SUNLIGHTAPP_H

#include <QApplication>
#include <QSystemTrayIcon>

#include "launcherwidget.h"
#include "suggestionmanager.h"
#include "eventdispatcher.h"

class SunlightApp : public QApplication
{
    Q_OBJECT
private:
    LauncherWidget *m_launcherWidget;
    SuggestionManager *m_suggestionMgr;
    EventDispatcher *m_dispatcher;

    QSystemTrayIcon *m_trayIcon;

    void createTrayIcon();

public:
    SunlightApp(int argc, char *argv[]);
    ~SunlightApp();

signals:

public slots:

};

#endif // SUNLIGHTAPP_H
