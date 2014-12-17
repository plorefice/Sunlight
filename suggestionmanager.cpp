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
        m_suggestions << Suggestion(it.fileInfo());
    }
}

void SuggestionManager::getSuggestions(const QString &cmd)
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
        m_currSugg = l.at(0);

        QString hint;
        QString name = m_currSugg.toString();

        hint.append(cmd);
        hint.append(name.right(name.length() - cmd.length()));

        m_launcher->setHint(hint);
    }
    else
    {
        m_launcher->setHint("");
    }
}

void SuggestionManager::execSuggestion()
{
    emit dispatchCommand(m_currSugg.cmd());
    m_launcher->clearSearchBox();
    m_launcher->hide();
}
