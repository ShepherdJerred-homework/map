#pragma once
#include<string>
#include "VerseKey.h"
#include <ostream>

using std::string;
class Verse {
    VerseKey verseKey;
    string verseText;
public:
    Verse();
    Verse(VerseKey, string);
    VerseKey getVerseKey() const;
    string getVerseText() const;

    friend std::ostream& operator<<(std::ostream& os, const Verse& obj) {
        return os
            << obj.verseKey << std::endl << obj.verseText;
    }
};
