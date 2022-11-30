#include "StmtExtensions.h"
#include "Stmt.h"

#include <string>
using namespace std;

End::End(string _opCode) : Stmt(_opCode) {
	opCode = -1;
};

string End::getOther(int index) {
	return "";
}

Jump::Jump(string _opCode, string _label) : Stmt(_opCode) {
	opCodeInt = OP_JUMP;
	label = _label;
}
string Jump::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	return "";
}
void Jump::setOther(string _label)
{
	label = _label;
}
void Jump::setOther(int _location)
{
	location = _location;
}
;

JumpZero::JumpZero(string _opCode, string _label) : Stmt(_opCode) {
	opCodeInt = OP_JUMPZERO;
	label = _label;
}
string JumpZero::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	return "";
}
void JumpZero::setOther(string _label)
{
	label = _label;
}
void JumpZero::setOther(int _location)
{
	location = _location;
}
;

JumpNZero::JumpNZero(string _opCode, string _label) : Stmt(_opCode) {
	opCodeInt = OP_JUMPNZERO;
	label = _label;
}
string JumpNZero::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	return "";
}
void JumpNZero::setOther(string _label)
{
	label = _label;
}
void JumpNZero::setOther(int _location)
{
	location = _location;
}
;

GoSub::GoSub(string _opCode, string _label) : Stmt(_opCode) {
	opCodeInt = OP_GOSUB;
	label = _label;
}
string GoSub::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	return "";
}
void GoSub::setOther(string _label)
{
	label = _label;
}
void GoSub::setOther(int _location)
{
	location = _location;
}
;

Return::Return(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_RETURN;
}
string Return::getOther(int index)
{
	return "";
}
;

Enter::Enter(string _opCode, string _label) : Stmt(_opCode) {
	opCodeInt = OP_ENTER_SUBROUTINE;
	label = _label;
}
string Enter::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	return "";
}
void Enter::setOther(string _label)
{
	label = _label;
}
void Enter::setOther(int _location)
{
	location = _location;
}
;

ExitSubroutine::ExitSubroutine(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_EXIT_SUBROUTINE;
}
string ExitSubroutine::getOther(int index)
{
	return "";
}
;

Start::Start(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_START_PROGRAM;
}
string Start::getOther(int index)
{

	return "";
}
void Start::setOther(int _numVars)
{
	numVars = _numVars;
}
;

ExitProgram::ExitProgram(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_EXIT_PROGRAM;
}
string ExitProgram::getOther(int index)
{
	return "";
}
;

PushScalar::PushScalar(string _opCode, string _var) : Stmt(_opCode) {
	opCodeInt = OP_PUSHSCALAR;
	var = _var;
}
string PushScalar::getOther(int index)
{
	if (index == 1) {
		return var;
	}
	return "";
}
void PushScalar::setOther(string _var)
{
	var = _var;
}
;

PushArray::PushArray(string _opCode, string _var) : Stmt(_opCode) {
	opCodeInt = OP_PUSHARRAY;
	var = _var;
}
string PushArray::getOther(int index)
{
	if (index == 1) {
		return var;
	}
	return "";
}
void PushArray::setOther(string _var)
{
	var = _var;
}
;

PushI::PushI(string _opCode, int _arg) : Stmt(_opCode) {
	opCodeInt = OP_PUSHI;
	arg = _arg;
}
string PushI::getOther(int index)
{
	if (index == 1) {
		return to_string(arg);
	}
	return "";
}
void PushI::setOther(int _arg)
{
	arg = _arg;
}
;

PopScalar::PopScalar(string _opCode, string _var) : Stmt(_opCode) {
	opCodeInt = OP_POPSCALAR;
	var = _var;
}
string PopScalar::getOther(int index)
{
	if (index == 1) {
		return var;
	}
	return "";
}
void PopScalar::setOther(string _var)
{
	var = _var;
}
;

PopArray::PopArray(string _opCode, string _var) : Stmt(_opCode) {
	opCodeInt = OP_POPARRAY;
	var = _var;
}
string PopArray::getOther(int index)
{
	if (index == 1) {
		return var;
	}
	return "";
}
void PopArray::setOther(string _var)
{
	var = _var;
}
;

Pop::Pop(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_POP;
}
string Pop::getOther(int index)
{
	return "";
}
;

Dup::Dup(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_DUP;
}
string Dup::getOther(int index)
{
	return "";
}
;

Swap::Swap(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_SWAP;
}
string Swap::getOther(int index)
{
	return "";
}
;

Add::Add(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_ADD;
}
string Add::getOther(int index)
{
	return "";
}
;

Negate::Negate(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_NEGATE;
}
string Negate::getOther(int index)
{
	return "";
}
;

Mul::Mul(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_MUL;
}
string Mul::getOther(int index)
{
	return "";
}
;

Div::Div(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_DIV;
}
string Div::getOther(int index)
{
	return "";
}
;

Prints::Prints(string _opCode, string _str, int _strIndex) : Stmt(_opCode) {
	opCodeInt = OP_PRINTS;
	str = _str; 
	strIndex = _strIndex;
}
string Prints::getOther(int index)
{
	if (index == 1) {
		return str;
	}
	else {
		return to_string(strIndex);
	}
	return "";
	
}
void Prints::setOther(string _str)
{
	str = _str;
}
void Prints::setOther(int _strIndex)
{
	strIndex = _strIndex;
}
;

PrintTOS::PrintTOS(string _opCode) : Stmt(_opCode) {
	opCodeInt = OP_PRINTTOS;
}
string PrintTOS::getOther(int index)
{
	return "";
}
;

ostream& operator<<(ostream& ostr, End stmt)
{
	return ostr << "" << endl;
}

ostream& operator<<(ostream& ostr, Jump stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, JumpZero stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, JumpNZero stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, GoSub stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, Return stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Enter stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, ExitSubroutine stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Start stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, ExitProgram stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, PushScalar stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, PushArray stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, PushI stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, PopScalar stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, PopArray stmt)
{
	return ostr << stmt.opCode << stmt.getOther(1) << endl;
}

ostream& operator<<(ostream& ostr, Pop stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Dup stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Swap stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Add stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Negate stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Mul stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Div stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, Prints stmt)
{
	return ostr << stmt.opCode << endl;
}

ostream& operator<<(ostream& ostr, PrintTOS stmt)
{
	return ostr << stmt.opCode << endl;
}
