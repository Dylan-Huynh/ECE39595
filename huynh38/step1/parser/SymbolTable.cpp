#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "SymbolTable.h"

SymbolTable* SymbolTable::uniqueInstance = nullptr;
int SymbolTable::mem = 0;
vector<int> SymbolTable::len{ 0, 0 };
int SymbolTable::scope = 0;

SymbolTable::SymbolTable() { 
    SymbolTableList.push_back(map<string, pair<int, int>>());
}

SymbolTable* SymbolTable::getInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new SymbolTable();
    }
    return uniqueInstance;
}


void SymbolTable::insertEntry(string key, pair<int, int> entry) {
    // if table[scope] does not exist, create it
    if (SymbolTableList.size() <= scope) {
        SymbolTableList.push_back(map<string, pair<int, int>>());
    }
    SymbolTableList[scope][key] = entry;
    mem += entry.second;
    len[scope]++;
}

int SymbolTable::getSize() {
    return mem;
}

int SymbolTable::getLen() {
    return len[scope];
}


void SymbolTable::setScope(int _scope) {
    scope = _scope;

    // if setting scope to global, reset memsize[1], numVar[1], and table[1]
    if (scope == 0) {
        len[1] = 0;

        if (SymbolTableList.size() <= scope) {
            SymbolTableList[1].clear();
        }
        
    }
}

int SymbolTable::getScope() {
    return scope;
}

pair<int, int> SymbolTable::getEntry(string key) {
    return SymbolTableList[scope][key];
}

bool SymbolTable::isIn(string key) {
    if (SymbolTableList[scope].find(key) == SymbolTableList[scope].end()) {
        return false;
    }
    else {
        return true;
    }
}