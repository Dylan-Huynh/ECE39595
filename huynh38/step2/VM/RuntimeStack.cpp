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

void RuntimeStack::dup(){
    int top = run_stack[0];
    run_stack.insert(run_stack.begin(), top);
}

void RuntimeStack::swap(){
    int top = run_stack[0];
    int second = run_stack[1];
    run_stack[0] = second;
    run_stack[1] = top;
}

void RuntimeStack::add(){
    int top = run_stack[0];
    int second = run_stack[1];
    run_stack.erase(run_stack.begin());
    run_stack[0] = top + second;
}

void RuntimeStack::negate(){
    run_stack[0] = 0 - run_stack[0];
}

void RuntimeStack::mul(){
    int top = run_stack[0];
    int second = run_stack[1];
    run_stack.erase(run_stack.begin());
    run_stack[0] = top * second;
}

void RuntimeStack::div(){
    int top = run_stack[0];
    int second = run_stack[1];
    run_stack.erase(run_stack.begin());
    run_stack[0] = top / second;
}