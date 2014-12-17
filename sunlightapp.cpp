#include "sunlightapp.h"

#include <windows.h>
#include <winuser.h>

#include <QDesktopWidget>
#include <QMenu>


SunlightApp::SunlightApp(int argc, char *argv[])
    : QApplication(argc, argv)
{
    m_launcherWidget = new LauncherWidget(this->desktop());
    m_launcherWidget->hide();

    RegisterHotKey((HWND) m_launcherWidget->winId(), 100, MOD_WIN, VK_F11);

    createTrayIcon();
}

SunlightApp::~SunlightApp()
{
    delete m_launcherWidget;
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
