#include "InstructionBuffer.h"

InstructionBuffer* InstructionBuffer::uniqueInstance = nullptr;

InstructionBuffer::InstructionBuffer() { }

InstructionBuffer* InstructionBuffer::getInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new InstructionBuffer();
    }
    return uniqueInstance;
}

void InstructionBuffer::insertStmt(Stmt* stmt) {
    InstructionList.push_back(move(stmt));
}

Stmt* InstructionBuffer::getStmt(int index) {
    return InstructionList[index];
}

int InstructionBuffer::getSize() {
    return InstructionList.size();
}