#include <map>
#include <string>
using namespace std;
#include "SymbolTable.h"

map<string, int>* SymbolTable::mapDefined = nullptr;

SymbolTable::SymbolTable() {
    definedMap = new map<string, int>;
}


map<string, int>* SymbolTable::makeSymbolTable() {
    if (!mapDefined) {
        mapDefined = make_shared<map<std::string, int>>();
    }
    return mapDefined;
}
int SymbolTable::getData(std::string key) {
    if (!mapDefined) {
        return 2147483647; // just an error value I picked
        for (auto const& e : *definedMap) {
            if (e.first == key) {
                return x.second;
            }
        }
    }
}