#pragma once
#include <string>
#include <ostream>

using std::string;

class VerseKey {
    string book;
    int chapter;
    int verse;
public:
    VerseKey();
    VerseKey(string, int, int);
    string getBook() const;
    int getChapter() const;
    int getVerse() const;

    friend bool operator==(const VerseKey& lhs, const VerseKey& rhs) {
        return lhs.book == rhs.book
            && lhs.chapter == rhs.chapter
            && lhs.verse == rhs.verse;
    }

    friend bool operator!=(const VerseKey& lhs, const VerseKey& rhs) {
        return !(lhs == rhs);
    }


    friend std::ostream& operator<<(std::ostream& os, const VerseKey& obj) {
        return os
            << obj.book << " " << obj.chapter << ":" << obj.verse;
    }
};
