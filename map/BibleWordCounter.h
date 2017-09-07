#pragma once
#include "Map.hpp"
#include "Verse.h"


class BibleWordCounter : public Map<VerseKey, Verse>::Visitor {
public:
    BibleWordCounter(string targetWord) : targetWord(targetWord), count(0) {
        
    }

    void visit(VerseKey&, Verse&) override;
    int getCount() const;
private:
    string targetWord;
    int count;
};
