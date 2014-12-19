#ifndef SUGGESTION_H
#define SUGGESTION_H

#include <QFileInfo>
#include <QPixmap>

class Suggestion
{
private:
    QFileInfo m_info;
    QPixmap   m_icon;

public:
    Suggestion();
    Suggestion(const QFileInfo &info);
    ~Suggestion();

    bool match(const QString &s) const;

    QString cmd() const;
    QPixmap icon() const;

    QString toString() const;
};

#endif // SUGGESTION_H
