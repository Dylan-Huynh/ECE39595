#ifndef DataMemory_h
#define DataMemory_h
#include <string>
#include <vector>
#include "RuntimeStack.h"
#include <stack>

class DataMemory {
    public:
        static DataMemory* getInstance();
        void addMainStack(int arr_size);
        void addSubStack(int size);
        void deleteStack(int arr_size);
        int getVal(int index);
        void setVal(int index, int val);
        //std::vector<int> scope_indexes; //hold index of start of new stack
        //int scope = 0;
        void popScl(int opnd, RuntimeStack* rs);
        void popArr(int opnd, RuntimeStack* rs);
        void pushScl(int opnd, RuntimeStack* rs);
        void pushArr(int opnd, RuntimeStack* rs);
        int mainsize = 0;

    private:
        static DataMemory* uniqueInstance;
        DataMemory();
        std::vector<int> data_mem;
        //std::vector<int> sub_mem;
        std::stack<std::vector<int>> sub_mem;

};





#endif