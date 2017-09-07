#pragma once
#include "Verse.h"
#include "Map.hpp"

class BibleVerseSize : public Map<VerseKey, Verse>::Visitor {
public:
    BibleVerseSize() : size(0) {

    }

    void visit(VerseKey&, Verse&) override;
    int getSize() const;
private:
    int size;
};
