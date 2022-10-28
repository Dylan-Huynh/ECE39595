#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

#include <string>

class StringBuffer {
public:
	StringBuffer( );
	void insertString(string printed);
private:
	string* stringList[];
};
#endif /* STRINGBUFFER_H_ */