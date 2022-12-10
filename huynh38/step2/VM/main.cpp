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
    vector<int> returnAddress; 
    vector<int> stackSize;

    int endCount =0;
    //ifstream inFile("test.txt");
    string line;
    int instructionLine = 0;
    //ifstream inFile("/Users/jenniferniemeyer/Downloads/ECE 39595/ProjectAssigned/OutputAndTestCases/TestCases10_08_22/26Recurse");
    if (!inFile.is_open( )) {
          cout << "failed to open file " << argv[1] << ", terminating" << endl;
          return -1;
    }
    else {
        while (getline(inFile, line)) {
            if (line.find("Start") != string::npos) {
                instructionLine = 1;
            }

            if (instructionLine) {
            // Add to Instruciton memory
                //cout << line << endl;
                instructionMemory->InstructionList.push_back(line);
            }
            else {
            //add to string memory
                stringTable->insertString(line);
            }
        
        // SAVE FOR GOING THROUGH INST MEM
        
        }    
    }
    inFile.close();
    
    
    

    bool instMemDone = false;
    int pc = 0; // index of instruction memory vector location
    while (!instMemDone and instructionLine) {   
        
        line = instructionMemory->InstructionList[pc];
        string delimiter = " ";
	    string opCode = line.substr(0, line.find(delimiter));
        //cout << opCode << endl;
    
        if (opCode == "GoSubLabel") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->addSubStack(data);
            stackSize.insert(stackSize.begin(), data); 
            pc++;
        }
        else if (opCode == "Start") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->addMainStack(data);
            dataMemory->mainsize = data;
            pc++;
        }
        else if (opCode == "Exit") {
            instMemDone = true;   
        }
        else if (opCode == "JumpZero") {
            if(runtimeStack->run_stack[0] == 0){
                int data = stoi(line.substr(line.find(" ") + 1, line.length()));
                pc = data;
            }
            else {
                pc++;
            }
            runtimeStack->run_stack.erase(runtimeStack->run_stack.begin());
        }
        else if (opCode == "JumpNZero") {
            if(runtimeStack->run_stack[0]){
                int data = stoi(line.substr(line.find(" ") + 1, line.length()));
                pc = data;
            }
            else {
                pc++;
            }
            runtimeStack->run_stack.erase(runtimeStack->run_stack.begin());
        }
        else if (opCode == "GoSub") {
            returnAddress.insert(returnAddress.begin(), (pc+1));
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            pc = data;
        }
        else if (opCode == "Return") {
            pc = returnAddress[0];
            returnAddress.erase(returnAddress.begin());
            dataMemory->deleteStack(stackSize[0]);
            stackSize.erase(stackSize.begin());
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
            runtimeStack->run_stack.insert(runtimeStack->run_stack.begin(), data);
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
        else if (opCode == "Jump") {
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            pc = data;
        }
        else if (opCode == "Pop") {
            runtimeStack->run_stack.erase(runtimeStack->run_stack.begin());
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
            runtimeStack->div();
            pc++;
        }
        else if (opCode == "PrintTOS") {
            outFile << runtimeStack->run_stack[0] << endl;
            cout << runtimeStack->run_stack[0] << endl;
            runtimeStack->run_stack.erase(runtimeStack->run_stack.begin());
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

    }
    outFile.close();
    

    return 0;
} 