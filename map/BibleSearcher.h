#pragma once
#include "Bible.h"

class BibleSearcher {
    Bible& bible;
public:
    BibleSearcher(Bible&);
    void searchForVerses() const;
};
