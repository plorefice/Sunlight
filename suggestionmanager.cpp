#include "suggestionmanager.h"

#include <QDirIterator>
#include <QStringBuilder>
#include <QDebug>

SuggestionManager::SuggestionManager(LauncherWidget *p)
{
    m_launcher = p;
}

SuggestionManager::~SuggestionManager()
{

}

void SuggestionManager::buildSuggestionList()
{
    QString dir("C:/ProgramData/Microsoft/Windows/Start Menu");
    QDirIterator it(dir, QStringList() << "*.lnk", QDir::NoFilter, QDirIterator::Subdirectories);

    while (it.hasNext())
    {
        it.next();
        qDebug() << it.fileInfo().baseName();
        m_suggestions << Suggestion(it.fileInfo());
    }
}

void SuggestionManager::getSuggestion(const QString &cmd)
{
    SuggestionList l;

    if (cmd.isEmpty())
    {
        m_launcher->setHint("");
        return;
    }

    for (const Suggestion &s : m_suggestions)
        if (s.match(cmd))
            l << s;

    if (!l.isEmpty())
    {
        QString hint;
        QString name = l.at(0).toString();

        hint.append(cmd);
        hint.append(name.right(name.length() - cmd.length()));

        m_launcher->setHint(hint);
    }
    else
    {
        m_launcher->setHint("");
    }
}
