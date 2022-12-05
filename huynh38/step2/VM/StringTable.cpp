#include "StringTable.h"
#include <string>
using namespace std;

StringTable* StringTable::uniqueInstance = nullptr;

StringTable::StringTable() { }

StringTable* StringTable::getInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new StringTable();
    }
    return uniqueInstance;
}

void StringTable::insertString(std::string str) {
    stringList.push_back(str);
}

string StringTable::getString(int index) {
    return stringList[index];
}

int StringTable::getSize() {
    return stringList.size();
}