#ifndef LAUNCHERWIDGET_H
#define LAUNCHERWIDGET_H

#include <QWidget>
#include <QQmlApplicationEngine>

class LauncherWidget : public QWidget
{
    Q_OBJECT
private:
    QQmlApplicationEngine *m_qmlEngine;
    QObject *m_topLevel;

protected:
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public:
    LauncherWidget();
    ~LauncherWidget();

    QObject *findChild(const QString &name) const;
    void setHint(const QString &hint);

public slots:
    void show();
    void hide();
    void toggle();
};

#endif // LAUNCHERWIDGET_H
