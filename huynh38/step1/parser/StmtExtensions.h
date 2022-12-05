#pragma once
#include <map>
#include <string>
#include <vector>
#include "Stmt.h"
using namespace std;


class End : public Stmt {
public:

    End(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Jump : public Stmt{
public:

    string label;
    int location;
    Jump(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    virtual ostream& print(ostream& ostr);

};

class JumpZero : public Stmt {
public:

    string label;
    int location;
    JumpZero(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    virtual ostream& print(ostream& ostr);

};

class JumpNZero : public Stmt {
public:

    string label;
    int location;
    JumpNZero(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    virtual ostream& print(ostream& ostr);

};

class GoSub : public Stmt {
public:

    string label;
    int location;
    GoSub(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    virtual ostream& print(ostream& ostr);

};

class Return : public Stmt {
public:

    Return(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Enter : public Stmt {
public:

    string label;
    int numVars;
    Enter(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    virtual ostream& print(ostream& ostr);

};

/*
class ExitSubroutine : public Stmt {
public:

    ExitSubroutine(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};
*/

class Start : public Stmt {
public:
    int numVars = -1;
    Start(std::string _opCode);
    string getOther(int index);
    void setOther(int _numVars);
    virtual ostream& print(ostream& ostr);

};

class ExitProgram : public Stmt {
public:

    ExitProgram(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class PushScalar : public Stmt {
public:
    int location = -1;
    string var;
    PushScalar(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    virtual ostream& print(ostream& ostr);

};

class PushArray : public Stmt {
public:
    int location = -1;
    string var;
    PushArray(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    virtual ostream& print(ostream& ostr);

};

class PushI : public Stmt {
public:
    int arg;
    PushI(std::string _opCode, int _arg);
    string getOther(int index);
    void setOther(int _arg);
    virtual ostream& print(ostream& ostr);

};

class PopScalar : public Stmt {
public:
    int location = -1;
    string var;
    PopScalar(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    virtual ostream& print(ostream& ostr);

};

class PopArray : public Stmt {
public:
    int location = -1;
    string var;
    PopArray(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    virtual ostream& print(ostream& ostr);

};


class Pop : public Stmt {
public:

    Pop(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Dup : public Stmt {
public:

    Dup(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostrvirtual);

};

class Swap : public Stmt {
public:

    Swap(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Add : public Stmt {
public:

    Add(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Negate : public Stmt {
public:

    Negate(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);


};

class Mul : public Stmt {
public:

    Mul(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Div : public Stmt {
public:

    Div(std::string _o_opCodep);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};

class Prints : public Stmt {
public:
    int strIndex;
    string str;
    Prints(std::string _opCode, string _str, int _strIndex);
    string getOther(int index);
    void setOther(string _str);
    void setOther(int _strIndex);
    virtual ostream& print(ostream& ostr);

};

class PrintTOS : public Stmt {
public:

    PrintTOS(std::string _opCode);
    string getOther(int index);
    virtual ostream& print(ostream& ostr);

};