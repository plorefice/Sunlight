#include "sunlightapp.h"

#include <windows.h>
#include <winuser.h>

#include <QDesktopWidget>
#include <QMenu>
#include <QDir>
#include <QDirIterator>
#include <QDebug>


SunlightApp::SunlightApp(int argc, char *argv[])
    : QApplication(argc, argv)
{
    m_launcherWidget = new LauncherWidget;
    m_suggestionMgr = new SuggestionManager(m_launcherWidget);
    m_dispatcher = new EventDispatcher(this);

    createTrayIcon();

    QObject *launcher = m_launcherWidget->findChild("SearchBox");

    connect(launcher, SIGNAL(inputChanged(QString)),
            m_suggestionMgr, SLOT(getSuggestions(QString)));
    connect(launcher, SIGNAL(returnPressed()),
            m_suggestionMgr, SLOT(execSuggestion()));

    connect(m_suggestionMgr, SIGNAL(dispatchCommand(QString)),
            m_dispatcher, SLOT(executeCmd(QString)));

    m_launcherWidget->hide();
    m_suggestionMgr->buildSuggestionList();
}

SunlightApp::~SunlightApp()
{
    delete m_launcherWidget;
    delete m_trayIcon;
    delete m_suggestionMgr;
    delete m_dispatcher;
}

void SunlightApp::createTrayIcon()
{
    QMenu *trayMenu = new QMenu(m_launcherWidget);

    trayMenu->addAction("Show/Hide", m_launcherWidget, SLOT(toggle()));
    trayMenu->addAction("Quit", this, SLOT(quit()));

    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setIcon(QIcon(":/res/icons/sl_tray.svg"));
    m_trayIcon->setContextMenu(trayMenu);
    m_trayIcon->show();
}
