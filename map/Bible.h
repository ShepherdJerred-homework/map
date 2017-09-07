#pragma once
#include "VerseKey.h"
#include "Verse.h"
#include "Map.hpp"

class Bible : public Map<VerseKey, Verse> {
public:
    static Bible& getInstance();
private:
    Bible();
    Bible(Bible const&) = delete;
    void operator =(Bible const&) = delete;
};
