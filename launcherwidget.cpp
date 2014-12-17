#include "launcherwidget.h"

#include <QApplication>
#include <QProcess>
#include <QDebug>

#include <windows.h>
#include <winuser.h>

LauncherWidget::LauncherWidget(QWidget *p)
    : QWidget(p)
{
    m_qmlEngine = new QQmlApplicationEngine(this);
    m_qmlEngine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    m_topLevel = m_qmlEngine->rootObjects().value(0);

    QObject *item  = m_topLevel->findChild<QObject *>("launcherWindow");

    connect(item, SIGNAL(inputChanged(QString)), this, SLOT(handleInputChanged(QString)));
    connect(item, SIGNAL(returnPressed(QString)), this, SLOT(execCommand(QString)));

    /* DEBUG */
    m_cmdList << "cmd.exe" << "matlab.exe" << "notepad.exe" << "game.lnk";
}

LauncherWidget::~LauncherWidget()
{

}

bool LauncherWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType);
    Q_UNUSED(result);

    MSG *msg = reinterpret_cast<MSG *>(message);

    if (msg->message == WM_HOTKEY)
    {
        qDebug() << "hotkey";
        this->toggle();

        return true;
    }

    return false;
}

void LauncherWidget::handleInputChanged(const QString &txt)
{
    QObject *subbox = m_topLevel->findChild<QObject *>("mainText");

    if (txt.isEmpty())
    {
        subbox->setProperty("text", "");
        return;
    }

    QStringList results;
    for (const QString &s : m_cmdList)
        if (s.startsWith(txt, Qt::CaseInsensitive))
            results << s;

    if (!results.isEmpty())
    {
        m_cmd = results.at(0);
        subbox->setProperty("text", m_cmd);
    }
    else
    {
        m_cmd.clear();
    }

    qDebug() << results;
}

void LauncherWidget::execCommand(const QString &txt)
{
    QProcess proc;

    if (!m_cmd.isEmpty())
        proc.startDetached(m_cmd);
    else
        proc.startDetached(txt);

    hide();
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
