#ifndef SUGGESTIONMANAGER_H
#define SUGGESTIONMANAGER_H

#include <QObject>

#include "suggestionlist.h"
#include "launcherwidget.h"

class SuggestionManager : public QObject
{
    Q_OBJECT
private:
    LauncherWidget *m_launcher;
    SuggestionList m_suggestions;

    Suggestion m_currSugg;

public:
    SuggestionManager(LauncherWidget *p);
    ~SuggestionManager();

    void buildSuggestionList();

signals:
    void dispatchCommand(const QString &cmd);

public slots:
    void getSuggestions(const QString &cmd);
    void execSuggestion();
};

#endif // SUGGESTIONMANAGER_H
