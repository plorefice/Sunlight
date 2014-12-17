#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <QObject>
#include <QProcess>

class EventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit EventDispatcher(QObject *parent = 0);
    ~EventDispatcher();

signals:

public slots:
    void executeCmd(const QString &cmd);
};

#endif // EVENTDISPATCHER_H
