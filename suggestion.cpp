#include "suggestion.h"

Suggestion::Suggestion()
{

}

Suggestion::Suggestion(const QFileInfo &info)
{
    m_info = info;
}

Suggestion::~Suggestion()
{

}

bool Suggestion::match(const QString &s) const
{
    if (m_info.baseName().startsWith(s, Qt::CaseInsensitive))
        return true;

    return false;
}

QString Suggestion::cmd() const
{
    return m_info.canonicalFilePath();
}

QString Suggestion::toString() const
{
    return m_info.baseName();
}
