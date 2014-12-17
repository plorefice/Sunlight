#include "launcherwidget.h"

#include <QApplication>
#include <QProcess>
#include <QDebug>

#include <windows.h>
#include <winuser.h>

LauncherWidget::LauncherWidget()
    : QWidget(NULL)
{
    m_qmlEngine = new QQmlApplicationEngine(this);
    m_qmlEngine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_topLevel = m_qmlEngine->rootObjects().value(0);

    RegisterHotKey((HWND) winId(), 100, MOD_WIN, VK_F11);
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

void LauncherWidget::setHint(const QString &hint)
{
    findChild("mainText")->setProperty("text", hint);
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
