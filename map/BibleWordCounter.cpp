#include "stdafx.h"
#include "BibleWordCounter.h"
#include <sstream>
#include <string>

using std::stringstream;
void BibleWordCounter::visit(VerseKey& verseKey, Verse& verse) {
    stringstream ss(verse.getVerseText());

    string word;
    for (int i = 0; ss >> word; i++) {
        if (word == targetWord) {
            count++;
        }
    }
}

int BibleWordCounter::getCount() const {
    return count;
}
