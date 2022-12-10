#include "RuntimeStack.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

RuntimeStack* RuntimeStack::uniqueInstance = nullptr;
 
RuntimeStack::RuntimeStack(){};
 
RuntimeStack* RuntimeStack::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new RuntimeStack();
    }
    return uniqueInstance;
}

void RuntimeStack::dup() {
    int top = runStackList[getSize() - 1];
    runStackList.push_back(top);
}

void RuntimeStack::swap() {
    int tmp = runStackList[getSize() - 1];
    runStackList[getSize() - 1] = runStackList[getSize() - 2];
    runStackList[getSize() - 2] = tmp;
}

void RuntimeStack::add() {
    int top = runStackList[getSize() - 1];
    int second = runStackList[getSize() - 2];
    eraseTop();
    runStackList[getSize() - 1] = top + second;
}

void RuntimeStack::negate() {
    runStackList[getSize() - 1] = 0 - runStackList[getSize() - 1];
}

void RuntimeStack::mul() {
    int top = runStackList[0];
    int second = runStackList[1];
    eraseTop();
    runStackList[getSize() - 1] = top * second;
}

void RuntimeStack::div() {
    int top = runStackList[0];
    int second = runStackList[1];
    eraseTop();
    runStackList[(getSize()) - 1] = top / second;
}

void RuntimeStack::eraseTop() {
    runStackList.pop_back();
}

int RuntimeStack::getTop() {
    return runStackList[getSize() - 1];
}

void RuntimeStack::insertAtTop(int data) {
    runStackList.push_back(data);
}

int RuntimeStack::getSize() {
    return runStackList.size();
}