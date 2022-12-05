#include <string>
#include <map>
#include <vector>
using namespace std;

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

class SymbolTable {
public:
	static SymbolTable* getInstance();
	void insertEntry(string key, pair<int, int>);
	pair<double, double> getEntry(std::string key);
	static int getSize();
	static int getLen();
	vector<map<string, pair<int, int>>> SymbolTableList;
	void setScope(int _scope);
	int getScope();
	//static int getData(string key);
private:
	SymbolTable();
	static vector<int> mem;
	static vector<int> len;
	static int scope;
	static SymbolTable* uniqueInstance;

	

};

#endif /*SYMBOLTABLE_H_*/