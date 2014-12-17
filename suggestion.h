#ifndef SUGGESTION_H
#define SUGGESTION_H

#include <QFileInfo>

class Suggestion
{
private:
    QFileInfo m_info;

public:
    Suggestion(const QFileInfo &info);
    ~Suggestion();

    bool match(const QString &s) const;

    QString toString() const;
};

#endif // SUGGESTION_H
