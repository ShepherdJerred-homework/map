// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.hpp"
#include <iostream>
#include "Bible.h"
#include "BibleReader.h"
#include "BibleSearcher.h"
#include "BibleWordCounter.h"
#include "BibleVerseSize.h"

using std::string;
using std::cout;
using std::endl;

void runSearcher(Bible& bible) {
    BibleSearcher bibleSearcher(bible);
    bibleSearcher.searchForVerses();
}

void runIterator(Bible& bible) {
    Bible::Iterator i = bible.getIterator();

    while (i.hasNext()) {
        cout << *i << endl;
        ++i;
    }
}

void runVisitor(Bible& bible) {
    BibleWordCounter bwc("firmament");
    bible.visit(bwc);
    cout << bwc.getCount();
}

void runSecondVisitor(Bible& bible) {
    BibleVerseSize bvs;
    bible.visit(bvs);
    cout << bvs.getSize();
}

int main() {

    Bible& bible = Bible::getInstance();
    BibleReader::readFileIntoBible("genesis.txt", bible);

    //    runSearcher(bible);
    //    runIterator(bible);
    //    runVisitor(bible);
    //    runSecondVisitor(bible);

    return 0;
}
