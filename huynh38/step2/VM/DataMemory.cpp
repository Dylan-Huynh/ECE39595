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

    data_mem.resize(scope_size);

}
void DataMemory::addSubStack(int size){
    vector<int> vec;
    vec.resize(size);
    sub_mem.push(vec);
}

void DataMemory::popScl(int opnd, RuntimeStack* rs){
    //data_mem[opnd] = rs->run_stack[0];
    setVal(opnd, rs->run_stack[0]);
    rs->run_stack.erase(rs->run_stack.begin());
}

void DataMemory::popArr(int opnd, RuntimeStack* rs){
    int stackValue = rs->run_stack[0];
    int e = opnd + stackValue;
    rs->run_stack.erase(rs->run_stack.begin());
   
    //data_mem[e] = rs->run_stack[0];
    setVal(e, rs->run_stack[0]);
    rs->run_stack.erase(rs->run_stack.begin());
}

void DataMemory::pushScl(int opnd, RuntimeStack* rs){
    int stackVal = getVal(opnd);

    rs->run_stack.insert(rs->run_stack.begin(), stackVal);
}

void DataMemory::pushArr(int opnd, RuntimeStack* rs){
    int e = opnd + rs->run_stack[0];
    rs->run_stack.erase(rs->run_stack.begin());
    int StackVal = getVal(e);
    rs->run_stack.insert(rs->run_stack.begin(), StackVal);

}

void DataMemory::deleteStack(int size){
    sub_mem.pop();
}

int DataMemory::getVal(int index){
    if(index < mainsize){
        return data_mem[index];
    }
    else{
        //return sub_mem[index - mainsize];
        vector<int> vec;
        vec = sub_mem.top();
        return vec[index - mainsize];
    }
}

void DataMemory::setVal(int index, int val){
    if(index < mainsize){
        data_mem[index] = val;
    }
    else{
        //sub_mem[index - mainsize] = val;
        sub_mem.top()[index - mainsize] = val;
    }
}