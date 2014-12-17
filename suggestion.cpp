#include "suggestion.h"

#include <QtWinExtras/QtWinExtras>

Suggestion::Suggestion()
{
}

Suggestion::Suggestion(const QFileInfo &info)
{
    m_info = info;

#ifdef Q_OS_WIN
    QString fname(QDir::toNativeSeparators(info.canonicalFilePath()));
    wchar_t *conv_name = new wchar_t[fname.length() + 1];
    fname.toWCharArray(conv_name);
    conv_name[fname.length()] = '\0';
    HICON hIcon = ::ExtractIconW(NULL, conv_name, 0);
    if (hIcon)
        m_icon = QtWin::fromHICON(hIcon);
    else
    {
        m_icon = QPixmap(32, 32);
        m_icon.fill(Qt::transparent);
    }
#endif
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

QPixmap Suggestion::icon() const
{
    return m_icon;
}

QString Suggestion::toString() const
{
    return m_info.baseName();
}
