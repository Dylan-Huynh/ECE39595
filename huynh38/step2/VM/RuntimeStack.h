#ifndef RunStack_h
#define RunStack_h
#include <string>
#include <vector>
using namespace std;

class RuntimeStack {
    public:
        static RuntimeStack* getInstance();
        vector<int> run_stack;
        int getStackValue();
        void dup();
        void swap();
        void add();
        void negate();
        void mul();
        void div();
    private:
        static RuntimeStack* uniqueInstance;
        RuntimeStack();

};





#endif