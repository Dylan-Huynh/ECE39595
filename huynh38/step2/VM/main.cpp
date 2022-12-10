#include <string>
#include <vector>
#include <ostream>
#include "RuntimeStack.h"
#include "InstructionMemory.h"
#include "DataMemory.h"
#include "StringTable.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#define max 3
using namespace std;


string strings[max];


int main(int argc, char** argv)
{
    ifstream inFile (argv[1]);
    ofstream outFile;
	outFile.open(argv[2]);
    int arrayIndex = 0;
    StringTable *stringTable = StringTable::getInstance();
    InstructionMemory *instructionMemory = InstructionMemory::getInstance();
    RuntimeStack *runtimeStack = RuntimeStack::getInstance();
    DataMemory *dataMemory = DataMemory::getInstance();
    vector<int> ra; 
    vector<int> stackSize;

    int endCount =0;
    string line;
    int instructionLine = 0;
    if (!inFile.is_open( )) {
          cout << "failed to open file " << argv[1] << ", terminating" << endl;
          exit(0);
    }
    else {
        while (getline(inFile, line)) {
            if (line.find("Start") != string::npos) {
                instructionLine = 1;
            }

            if (instructionLine) {
                //cout << line << endl;
                instructionMemory->InstructionList.push_back(line);
            }
            else {
                stringTable->insertString(line);
            }

        
        }    
    }
    inFile.close();
    
    
    

    bool instMemDone = false;
    int pc = 0;
    while (!instMemDone and instructionLine) {   
        
        line = instructionMemory->InstructionList[pc];
        string delimiter = " ";
	    string opCode = line.substr(0, line.find(delimiter));
        //cout << opCode << endl;
    
        if (opCode == "GoSubLabel") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->addSubStack(data);
            stackSize.push_back(data);
            pc++;
        }
        else if (opCode == "Start") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->addMainStack(data);
            dataMemory->mainVars = data;
            pc++;
        }
        else if (opCode == "Exit") {
            instMemDone = true;   
        }
        else if (opCode == "Return") {
            pc = ra[0];
            ra.pop_back();
            dataMemory->deleteStack(stackSize[stackSize.size() - 1]);
            stackSize.pop_back();
        }
        else if (opCode == "Jump") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            pc = data;
        }
        else if (opCode == "JumpZero") {
            int topG = runtimeStack->getTop();
            runtimeStack->eraseTop();
            if(topG == 0) {
                int data = stoi(line.substr(line.find(" ") + 1, line.length()));
                pc = data;
            }
            else {
                pc++;
            }
            
        }
        else if (opCode == "JumpNZero") {
            int topG = runtimeStack->getTop();
            runtimeStack->eraseTop();
            if(topG){
                int data = stoi(line.substr(line.find(" ") + 1, line.length()));
                pc = data;
            }
            else {
                pc++;
            }
        }
        else if (opCode == "GoSub") {
            ra.push_back((pc + 1));
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            pc = data;
        }
        
        else if (opCode == "PushScalar") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->pushScl(data, runtimeStack);
            pc++;
        }
        else if (opCode == "PushArray") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->pushArr(data, runtimeStack);
            pc++;
        }
        else if (opCode == "PushI") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            runtimeStack->insertAtTop(data);
            pc++;
        }
        else if (opCode == "Pop") {
            runtimeStack->eraseTop();
            pc++;
        }
        else if (opCode == "PopScalar") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->popScl(data, runtimeStack);
            pc++;
        }
        else if (opCode == "PopArray") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->popArr(data, runtimeStack);
            pc++;
        }
        else if (opCode == "Dup") {
            runtimeStack->dup();
            pc++;
        }
        else if (opCode == "Swap") {
            runtimeStack->swap();
            pc++;
        }
        else if (opCode == "Add") {
            runtimeStack->add();
            pc++;
        }
        else if (opCode == "Negate") {
            runtimeStack->negate();
            pc++;
        }
        else if (opCode == "Mul") {
            runtimeStack->mul();
            pc++;
        }
        else if (opCode == "Div") {
            cout << runtimeStack->getTop() << endl;
            runtimeStack->eraseTop();
        }
        else if (opCode == "PrintTOS") {
            cout << runtimeStack->getTop() << endl;
            outFile << runtimeStack->getTop() << endl;
            runtimeStack->eraseTop();
            pc++;
        }
        else if (opCode == "Prints") { 
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            outFile << stringTable->getString(data) << endl;
            cout << stringTable->getString(data) << endl;
            pc++;
        }
        else {
            cout << "Something didn't count" << endl;
        }

        // Set at the end of the vector
    }
    outFile.close();
    

    return 0;
} 