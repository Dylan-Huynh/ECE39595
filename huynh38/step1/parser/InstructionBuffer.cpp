#include "InstructionBuffer.h"

InstructionBuffer* InstructionBuffer::uniqueInstance = nullptr;

InstructionBuffer::InstructionBuffer() { }

InstructionBuffer* InstructionBuffer::getInstance() {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new InstructionBuffer();
    }
    return uniqueInstance;
}