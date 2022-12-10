#ifndef DataMemory_h
#define DataMemory_h
#include <string>
#include <vector>
#include "RuntimeStack.h"
#include <stack>
using namespace std;

class DataMemory {
public:
    static DataMemory* getInstance();
    void addMainStack(int arr_size);
    void addSubStack(int size);
    void deleteStack(int arr_size);
    int getVal(int index);
    void setVal(int index, int val);
    void popScl(int opnd, RuntimeStack* runtimeStack);
    void popArr(int opnd, RuntimeStack* runtimeStack);
    void pushScl(int opnd, RuntimeStack* runtimeStack);
    void pushArr(int opnd, RuntimeStack* runtimeStack);
    int mainVars = 0;

    private:
    static DataMemory* uniqueInstance;
    vector<int> dataMemoryList;
    stack<vector<int>> subMemoryList;
    DataMemory();

};

#endif /* DATAMEMORY_H_ */