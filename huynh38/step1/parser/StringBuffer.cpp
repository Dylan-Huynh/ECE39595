#include "StringBuffer.h"
#include <string>
using namespace std;

StringBuffer* StringBuffer::uniqueInstance = nullptr;

StringBuffer::StringBuffer() { }

StringBuffer* StringBuffer::getInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new StringBuffer();
    }
    return uniqueInstance;
}

void StringBuffer::insertString(std::string str) {
    stringList.push_back(str);
}

string StringBuffer::getString(int index) {
    return stringList[index];
}

int StringBuffer::getSize() {
    return stringList.size();
}