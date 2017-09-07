#include "stdafx.h"
#include "VerseKey.h"

using std::string;

VerseKey::VerseKey() {
    this->book = "Genesis";
    this->chapter = 1;
    this->verse = 1;
}

VerseKey::VerseKey(string book, int chapter, int verse) : book(""), chapter(0), verse(0) {
    this->book = book;
    this->chapter = chapter;
    this->verse = verse;
}

string VerseKey::getBook() const {
    return book;
}

int VerseKey::getChapter() const {
    return chapter;
}

int VerseKey::getVerse() const {
    return verse;
}
