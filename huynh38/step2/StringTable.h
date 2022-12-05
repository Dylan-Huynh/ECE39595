#include <vector>
#include <string>
using namespace std;

#ifndef STRINGTABLE_H_
#define STRINGTABLE_H_

class StringTable {
public:
	static StringTable* getInstance();
	void insertString(string str);
	string getString(int index);
	int getSize();

private:
	static StringTable* uniqueInstance;
	vector<string> stringList;
	StringTable();

};
#endif /* STRINGTABLE_H_ */