#include "stdafx.h"
#include "BibleReader.h"
#include "Bible.h"
#include <fstream>
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::ifstream;
using std::endl;
using std::stoi;

void BibleReader::readFileIntoBible(string fileName, Bible &bible) {
    ifstream file(fileName);

    if (!file) {
        cout << "Error reading file";
        exit(1);
    }

    string currentBookName;

    for (string line; getline(file, line);) {
        if (line.substr(0, 4) == "Book") {
            currentBookName = line.substr(8, line.length());
        } else {
            int chapter = stoi(line.substr(0, 3));
            int verseNumber = stoi(line.substr(4, 3));

            string text = line.substr(8, line.length());

            VerseKey verseKey(currentBookName, chapter, verseNumber);
            Verse verse(verseKey, text);

            bible[verseKey] = verse;
        }
    }

}
