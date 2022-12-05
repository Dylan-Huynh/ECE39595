#ifndef InstructionMemory_h
#define InstructionMemory_h
#include <string>
#include <vector>
using namespace std;

class InstructionMemory {
    public:
        static InstructionMemory* getInstance();
        vector<string> InstructionList;
    private:
        static InstructionMemory* uniqueInstance;
        InstructionMemory();
        
};











#endif