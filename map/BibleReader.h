#pragma once
#include <string>

class Bible;
using std::string;
class BibleReader {
public:
    static void readFileIntoBible(string, Bible&);
};

