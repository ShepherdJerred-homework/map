#include "stdafx.h"
#include "BibleVerseSize.h"
#include <sstream>
#include <string>

using std::stringstream;
void BibleVerseSize::visit(VerseKey& verseKey, Verse& verse) {
    stringstream ss(verse.getVerseText());

    string word;
    for (int i = 0; ss >> word; i++) {
        size++;
    }
}

int BibleVerseSize::getSize() const {
    return size;
}
