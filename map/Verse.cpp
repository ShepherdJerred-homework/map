#include "stdafx.h"
#include "Verse.h"

Verse::Verse(VerseKey verseKey, string verseText) {
    this->verseKey = verseKey;
    this->verseText = verseText;
}

VerseKey Verse::getVerseKey() const {
    return verseKey;
}

string Verse::getVerseText() const {
    return verseText;
}
