#include "stdafx.h"
#include "BibleSearcher.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

BibleSearcher::BibleSearcher(Bible& bible) : bible(bible) {
}

void BibleSearcher::searchForVerses() const {

    while (true) {
        string book;
        int chapter;
        int verse;

        cout << "Enter a book to search, or type quit" << endl;
        cin >> book;

        if (book == "quit") {
            return;
        }

        cout << "Enter a chapter of " << book << " to search" << endl;
        cin >> chapter;
        cout << "Enter a verse in " << book << " " << chapter << " to view" << endl;
        cin >> verse;

        VerseKey verseKey(book, chapter, verse);

        if (bible[verseKey].exists()) {
            Verse verseInBible = bible[verseKey];
            cout << endl << endl;
            cout << verseInBible;
            cout << endl << endl;
        } else {
            cout << "That verse doesn't exist" << endl;
        }

    }

}
