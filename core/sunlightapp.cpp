#include "sunlightapp.h"
#include "appiconprovider.h"

#include <QMenu>

SunlightApp::SunlightApp(int argc, char *argv[])
    : QApplication(argc, argv)
{
    m_dispatcher = new EventDispatcher(this);

    m_launcherWidget = new LauncherWidget;
    m_launcherWidget->hide();

    m_suggestionMgr = new SuggestionManager(m_launcherWidget);

    QObject *launcher = m_launcherWidget->findChild("SearchBox");

    connect(launcher, SIGNAL(inputChanged(QString)),
            m_suggestionMgr, SLOT(getSuggestions(QString)));
    connect(launcher, SIGNAL(returnPressed()),
            m_suggestionMgr, SLOT(execSuggestion()));

    connect(m_suggestionMgr, SIGNAL(dispatchCommand(QString)),
            m_dispatcher, SLOT(executeCmd(QString)));

    createTrayIcon();

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
