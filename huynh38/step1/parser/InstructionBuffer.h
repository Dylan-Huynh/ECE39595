#include <vector>
#include <memory>
using namespace std;
#include "Stmt.h"


#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_

class InstructionBuffer {
public:
	static InstructionBuffer* getInstance();
	void insertStmt(Stmt* statement);
	Stmt* getStmt(int index);
	int getSize();
private:
	static InstructionBuffer* uniqueInstance;
	InstructionBuffer();
	vector<Stmt*> InstructionList;

};
#endif /*SYMBOLTABLE_H_*/