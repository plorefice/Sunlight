#include "launcherwidget.h"
#include "appiconprovider.h"

#include <QDebug>

#ifdef Q_OS_WIN
#include <windows.h>
#include <winuser.h>
#endif

LauncherWidget::LauncherWidget()
    : QWidget(NULL)
{
    m_qmlEngine = new QQmlApplicationEngine(this);
    m_iconProvider = new AppIconProvider;

    m_qmlEngine->addImageProvider("appicon", m_iconProvider);
    m_qmlEngine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_topLevel = m_qmlEngine->rootObjects().value(0);

#ifdef Q_OS_WIN
    RegisterHotKey((HWND) winId(), 100, MOD_WIN | MOD_SHIFT, VK_RETURN);
#endif
}

LauncherWidget::~LauncherWidget()
{
    delete m_qmlEngine;
}

bool LauncherWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType);
    Q_UNUSED(result);

    MSG *msg = reinterpret_cast<MSG *>(message);

    if (msg->message == WM_HOTKEY)
    {
        this->toggle();
        return true;
    }

    return false;
}

QObject *LauncherWidget::findChild(const QString &name) const
{
    return m_topLevel->findChild<QObject *>(name, Qt::FindChildrenRecursively);
}

void LauncherWidget::clearSearchBox()
{
    setHint("");
    findChild("SearchBox")->children()[1]->setProperty("text", "");
}

void LauncherWidget::setHint(const QString &hint)
{
    findChild("SearchBox")->children()[0]->setProperty("text", hint);
}

void LauncherWidget::setAppIcon(const QPixmap &p, const QString &name)
{
    m_iconProvider->setIcon(p);
    findChild("AppIcon")->setProperty("source", "image://appicon/" + name);
}

void LauncherWidget::show()
{
    m_topLevel->setProperty("visible", true);
}

void LauncherWidget::hide()
{
    m_topLevel->setProperty("visible", false);
}

void LauncherWidget::toggle()
{
    bool isVisible = m_topLevel->property("visible").toBool();
    m_topLevel->setProperty("visible", !isVisible);
}
