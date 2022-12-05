#include "InstructionMemory.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#define max 3
#include <fstream>
#include <iostream>

InstructionMemory* InstructionMemory::uniqueInstance = nullptr;
 
InstructionMemory::InstructionMemory() { };
 
InstructionMemory* InstructionMemory::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new InstructionMemory();
    }
    return uniqueInstance;
}