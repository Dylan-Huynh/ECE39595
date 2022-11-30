#include <vector>
#include <string>
using namespace std;

#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

class StringBuffer {
public:
	static StringBuffer* getInstance();
	void insertString(string str);
	string getString(int index);
	int getSize();

private:
	static StringBuffer* uniqueInstance;
	vector<string> stringList;
	StringBuffer();

};
#endif /* STRINGBUFFER_H_ */