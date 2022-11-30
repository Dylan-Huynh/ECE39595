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
    friend ostream& operator<<(ostream& ostr, End stmt);

};

class Jump : public Stmt{
public:

    string label;
    int location;
    Jump(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    friend ostream& operator<<(ostream& ostr, Jump stmt);

};

class JumpZero : public Stmt {
public:

    string label;
    int location;
    JumpZero(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    friend ostream& operator<<(ostream& ostr, JumpZero stmt);

};

class JumpNZero : public Stmt {
public:

    string label;
    int location;
    JumpNZero(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    friend ostream& operator<<(ostream& ostr, JumpNZero stmt);

};

class GoSub : public Stmt {
public:

    string label;
    int location;
    GoSub(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    friend ostream& operator<<(ostream& ostr, GoSub stmt);

};

class Return : public Stmt {
public:

    Return(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Return stmt);

};

class Enter : public Stmt {
public:

    string label;
    int location;
    Enter(std::string _opCode, string _label);
    string getOther(int index);
    void setOther(string _label);
    void setOther(int _location);
    friend ostream& operator<<(ostream& ostr, Enter stmt);

};

class ExitSubroutine : public Stmt {
public:

    ExitSubroutine(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, ExitSubroutine stmt);

};

class Start : public Stmt {
public:
    int numVars = -1;
    Start(std::string _opCode);
    string getOther(int index);
    void setOther(int _numVars);
    friend ostream& operator<<(ostream& ostr, Start stmt);

};

class ExitProgram : public Stmt {
public:

    ExitProgram(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, ExitProgram stmt);

};

class PushScalar : public Stmt {
public:
    int location = -1;
    string var;
    PushScalar(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    friend ostream& operator<<(ostream& ostr, PushScalar stmt);

};

class PushArray : public Stmt {
public:
    int location = -1;
    string var;
    PushArray(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    friend ostream& operator<<(ostream& ostr, PushArray stmt);

};

class PushI : public Stmt {
public:
    int arg;
    PushI(std::string _opCode, int _arg);
    string getOther(int index);
    void setOther(int _arg);
    friend ostream& operator<<(ostream& ostr, PushI stmt);

};

class PopScalar : public Stmt {
public:
    int location = -1;
    string var;
    PopScalar(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    friend ostream& operator<<(ostream& ostr, PopScalar stmt);

};

class PopArray : public Stmt {
public:
    int location = -1;
    string var;
    PopArray(std::string _opCode, string _var);
    string getOther(int index);
    void setOther(string _var);
    friend ostream& operator<<(ostream& ostr, PopArray stmt);

};


class Pop : public Stmt {
public:

    Pop(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Pop stmt);

};

class Dup : public Stmt {
public:

    Dup(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Dup stmt);

};

class Swap : public Stmt {
public:

    Swap(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Swap stmt);

};

class Add : public Stmt {
public:

    Add(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Add stmt);

};

class Negate : public Stmt {
public:

    Negate(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Negate stmt);


};

class Mul : public Stmt {
public:

    Mul(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Mul stmt);

};

class Div : public Stmt {
public:

    Div(std::string _o_opCodep);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, Div stmt);

};

class Prints : public Stmt {
public:
    int strIndex;
    string str;
    Prints(std::string _opCode, string _str, int _strIndex);
    string getOther(int index);
    void setOther(string _str);
    void setOther(int _strIndex);
    friend ostream& operator<<(ostream& ostr, Prints stmt);

};

class PrintTOS : public Stmt {
public:

    PrintTOS(std::string _opCode);
    string getOther(int index);
    friend ostream& operator<<(ostream& ostr, PrintTOS stmt);

};