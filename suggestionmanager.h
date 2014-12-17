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

public:
    SuggestionManager(LauncherWidget *p);
    ~SuggestionManager();

    void buildSuggestionList();

public slots:
    void getSuggestion(const QString &cmd);
};

#endif // SUGGESTIONMANAGER_H
