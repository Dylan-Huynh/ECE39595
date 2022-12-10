#include "DataMemory.h"
#include <string>
#include <vector>
#include <stack>
#include "RuntimeStack.h"

DataMemory* DataMemory::uniqueInstance = nullptr;
 
DataMemory::DataMemory() { }
 
DataMemory* DataMemory::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new DataMemory();
    }
    return uniqueInstance;
}

void DataMemory::addMainStack(int scope_size){

    dataMemoryList.resize(scope_size);

}
void DataMemory::addSubStack(int size){
    vector<int> vec;
    vec.resize(size);
    subMemoryList.push(vec);
}

void DataMemory::popScl(int operand, RuntimeStack* runtimeStack){
    setVal(operand, runtimeStack->getTop());
    runtimeStack->eraseTop();
}

void DataMemory::popArr(int operand, RuntimeStack* runtimeStack){
    int val = runtimeStack->getTop();
    int e = operand + val;
    runtimeStack->eraseTop();
    setVal(e, runtimeStack->getTop());
    runtimeStack->eraseTop();
}

void DataMemory::pushScl(int opnd, RuntimeStack* runtimeStack){
    int val = getVal(opnd);

    runtimeStack->insertAtTop(val);
}

void DataMemory::pushArr(int opnd, RuntimeStack* runtimeStack){
    int e = opnd + runtimeStack->getTop();
    runtimeStack->eraseTop();
    int stackVal = getVal(e);
    runtimeStack->insertAtTop(stackVal);

}

void DataMemory::deleteStack(int size){
    subMemoryList.pop();
}

int DataMemory::getVal(int index){
    if(index < mainVars){
        return dataMemoryList[index];
    }
    else{
        vector<int> vec;
        vec = subMemoryList.top();
        return vec[index - mainVars];
    }
}

void DataMemory::setVal(int index, int val){
    if(index < mainVars){
        dataMemoryList[index] = val;
    }
    else{
        subMemoryList.top()[index - mainVars] = val;
    }
}