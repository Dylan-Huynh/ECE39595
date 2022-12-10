#ifndef RunStack_h
#define RunStack_h
#include <string>
#include <vector>
using namespace std;

class RuntimeStack {
public:
    static RuntimeStack* getInstance();
    
    void dup();
    void swap();
    void add();
    void negate();
    void mul();
    void div();
    void PrintTOS();
    void eraseTop();
    int getTop();
    void insertAtTop(int data);
    int getSize();
private:
    static RuntimeStack* uniqueInstance;
    vector<int> runStackList;
    RuntimeStack();

};

#endif /* RUNTIMESTACK_H_ */