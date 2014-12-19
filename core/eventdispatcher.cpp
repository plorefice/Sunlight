#include "eventdispatcher.h"

#include <QProcess>
#include <QDebug>
#include <QDir>

EventDispatcher::EventDispatcher(QObject *parent) : QObject(parent)
{

}

EventDispatcher::~EventDispatcher()
{

}

void EventDispatcher::executeCmd(const QString &cmd)
{
    QProcess proc;
    proc.startDetached("\"" + QDir::toNativeSeparators(cmd) + "\"");
}
