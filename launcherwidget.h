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

    QStringList m_cmdList;
    QString     m_cmd;

protected:
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public:
    LauncherWidget(QWidget *p = 0);
    ~LauncherWidget();

public slots:
    void handleInputChanged(const QString &txt);
    void execCommand(const QString &txt);

    void show();
    void hide();
    void toggle();
};

#endif // LAUNCHERWIDGET_H
