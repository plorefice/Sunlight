#ifndef SUGGESTIONLIST_H
#define SUGGESTIONLIST_H

#include <QList>
#include "suggestion.h"

class SuggestionList : public QList<Suggestion>
{
public:
    SuggestionList();
    ~SuggestionList();
};

#endif // SUGGESTIONLIST_H
