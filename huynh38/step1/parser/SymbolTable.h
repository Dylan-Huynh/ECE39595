#include <string>
#include <map>
using namespace std;

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

class SymbolTable {
public:
	static map<string, int>* makeSymbolTable();

	static int getData(string key);
private:
	SymbolTable();
	static map<string, int>* mapDefined;

};
#endif /*SYMBOLTABLE_H_*/