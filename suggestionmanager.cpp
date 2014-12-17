#include "suggestionmanager.h"

#include <QDirIterator>
#include <QStringBuilder>
#include <QDebug>
#include <QtGui>
#include <QtWinExtras/QtWinExtras>

#ifdef Q_OS_WIN
#include <qt_windows.h>
#endif

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
    if (cmd.isEmpty())
    {
        QPixmap p(32,32);
        p.fill(Qt::transparent);

        m_launcher->setHint("");
        m_launcher->setAppIcon(p, "null");
        return;
    }

    SuggestionList l;
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
        m_launcher->setAppIcon(m_currSugg.icon(), hint.toHtmlEscaped());

        qDebug() << hint.toHtmlEscaped();
    }
    else
    {
        QPixmap p(32,32);
        p.fill(Qt::transparent);

        m_launcher->setHint("");
        m_launcher->setAppIcon(p, "null");
        return;
    }
}

void SuggestionManager::execSuggestion()
{
    QString cmd = m_currSugg.cmd();

    emit dispatchCommand(cmd);

    m_launcher->clearSearchBox();
    m_launcher->hide();
}
