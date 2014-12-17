#ifndef LAUNCHERWIDGET_H
#define LAUNCHERWIDGET_H

#include <QWidget>
#include <QQmlApplicationEngine>
#include "appiconprovider.h"

class LauncherWidget : public QWidget
{
    Q_OBJECT
private:
    QQmlApplicationEngine *m_qmlEngine;
    AppIconProvider *m_iconProvider;
    QObject *m_topLevel;

protected:
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public:
    LauncherWidget();
    ~LauncherWidget();

    QObject *findChild(const QString &name) const;

    void clearSearchBox();

    void setHint(const QString &hint);
    void setAppIcon(const QPixmap &p, const QString &name);

public slots:
    void show();
    void hide();
    void toggle();
};

#endif // LAUNCHERWIDGET_H
