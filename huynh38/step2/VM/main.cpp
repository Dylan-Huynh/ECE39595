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
            stackSize.insert(stackSize.begin(), data); // hold the size of the stack so you can pop off the correct amt at return
            pc++;
        }
        else if (opCode == "Start") {
            //cout << "Start happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->addMainStack(data);
            dataMemory->mainsize = data;
            pc++;
        }
        else if (opCode == "Exit") {
            //cout << "Exit happened" << endl;
            instMemDone = true;   
        }
        else if (opCode == "JumpZero") {
            //cout << "JumpZero happened" << endl;
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
            //cout << "JumpNZero happened" << endl;
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
            //cout << "GoSub happened" << endl;
            returnAddress.insert(returnAddress.begin(), (pc+1));
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            pc = data;
        }
        else if (opCode == "Return") {
            //cout << "Return happened" << endl;
            pc = returnAddress[0];
            returnAddress.erase(returnAddress.begin());
            dataMemory->deleteStack(stackSize[0]);
            stackSize.erase(stackSize.begin());
        }
        else if (opCode == "PushScalar") {
            //cout << "PushScalar happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->pushScl(data, runtimeStack);
            pc++;
        }
        else if (opCode == "PushArray") {
            //cout << "PushArray happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->pushArr(data, runtimeStack);
            pc++;
        }
        else if (opCode == "PushI") {
            //cout << "PushI happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            runtimeStack->run_stack.insert(runtimeStack->run_stack.begin(), data);
            pc++;
        }
        else if (opCode == "PopScalar") {
            //cout << "PopScalar happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->popScl(data, runtimeStack);
            pc++;
        }
        else if (opCode == "PopArray") {
            //cout << "PopArray happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            dataMemory->popArr(data, runtimeStack);
            pc++;
        }
        else if (opCode == "Jump") {
            //cout << "Jump happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            pc = data;
        }
        else if (opCode == "Pop") {
            //cout << "Pop happened" << endl;
            runtimeStack->run_stack.erase(runtimeStack->run_stack.begin());
            pc++;
        }
        else if (opCode == "Dup") {
            //cout << "Dup happened" << endl;
            runtimeStack->dup();
            pc++;
        }
        else if (opCode == "Swap") {
            //cout << "Swap happened" << endl;
            runtimeStack->swap();
            pc++;
        }
        else if (opCode == "Add") {
            //cout << "Add happened" << endl;
            runtimeStack->add();
            pc++;
        }
        else if (opCode == "Negate") {
            //cout << "Negate happened" << endl;
            runtimeStack->negate();
            pc++;
        }
        else if (opCode == "Mul") {
            //cout << "Mul happened" << endl;
            runtimeStack->mul();
            pc++;
        }
        else if (opCode == "Div") {
            //cout << "Div happened" << endl;
            runtimeStack->div();
            pc++;
        }
        else if (opCode == "PrintTOS") {
            //cout << "PrintTOS happened" << endl;
            cout << runtimeStack->run_stack[0] << endl;
            runtimeStack->run_stack.erase(runtimeStack->run_stack.begin());
            pc++;
        }
        else if (opCode == "Prints") { 
            //cout << "Prints happened" << endl;
            int data = stoi(line.substr(line.find(" ") + 1, line.length()));
            cout << stringTable->getString(data) << endl;
            pc++;
        }
        else {
            //cout << "Something didn't count" << endl;
        }

        // Set at the end of the vector
    }
    

    return 0;
} 