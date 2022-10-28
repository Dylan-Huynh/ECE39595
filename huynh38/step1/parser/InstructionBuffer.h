#ifndef INSTRUCTIONBUFFER_H_
#define INSTRUCTIONBUFFER_H_

class InstructionBuffer {
public:
	static InstructionBuffer* getInstance();
private:
	static InstructionBuffer* uniqueInstance;
	InstructionBuffer();

};
#endif /*SYMBOLTABLE_H_*/