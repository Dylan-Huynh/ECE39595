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

ostream& End::print(ostream& ostr)
{
	return ostr;
}

Jump::Jump(string _opCode, string _label) : Stmt(_opCode) {
	Instruction = "Jump";
	label = _label;
}
string Jump::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	else {
		return to_string(location);
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
ostream& Jump::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(2) << endl;
}
;

JumpZero::JumpZero(string _opCode, string _label) : Stmt(_opCode) {
	Instruction = "JumpZero";
	label = _label;
}
string JumpZero::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	else {
		return to_string(location);
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
ostream& JumpZero::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(2) << endl;
}
;

JumpNZero::JumpNZero(string _opCode, string _label) : Stmt(_opCode) {
	Instruction = "JumpNZero";
	label = _label;
}
string JumpNZero::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	else {
		return to_string(location);
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
ostream& JumpNZero::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(2) << endl;
}
;

GoSub::GoSub(string _opCode, string _label) : Stmt(_opCode) {
	Instruction = "GoSub";
	label = _label;
}
string GoSub::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	else {
		return to_string(location);
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
ostream& GoSub::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(2) << endl;
}
;

Return::Return(string _opCode) : Stmt(_opCode) {
	Instruction = "Return";
}
string Return::getOther(int index)
{
	return "";
}
ostream& Return::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;


Enter::Enter(string _opCode, string _label) : Stmt(_opCode) {
	Instruction = "GoSubLabel";
	label = _label;
}
string Enter::getOther(int index)
{
	if (index == 1) {
		return label;
	}
	else {
		return to_string(numVars);
	}
	return "";
}
void Enter::setOther(string _label)
{
	label = _label;
}
void Enter::setOther(int _numVars)
{
	numVars = _numVars;
}
ostream& Enter::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(2) << endl;
}
;

/*
ExitSubroutine::ExitSubroutine(string _opCode) : Stmt(_opCode) {
	Instruction = OP_EXIT_SUBROUTINE;
}
string ExitSubroutine::getOther(int index)
{
	return "";
}
; */

Start::Start(string _opCode) : Stmt(_opCode) {
	Instruction = "Start";
	numVars = 0;
}
string Start::getOther(int index)
{
	return to_string(numVars);
}
void Start::setOther(int _numVars)
{
	numVars = _numVars;
}
ostream& Start::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(1) << endl;
}
;

ExitProgram::ExitProgram(string _opCode) : Stmt(_opCode) {
	Instruction = "Exit";
}
string ExitProgram::getOther(int index)
{
	return "";
}
ostream& ExitProgram::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

PushScalar::PushScalar(string _opCode, string _var) : Stmt(_opCode) {
	Instruction = "PushScalar";
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
ostream& PushScalar::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(1) << endl;
}
;

PushArray::PushArray(string _opCode, string _var) : Stmt(_opCode) {
	Instruction = "PushArray";
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
ostream& PushArray::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(1) << endl;
}
;

PushI::PushI(string _opCode, int _arg) : Stmt(_opCode) {
	Instruction = "PushI";
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
ostream& PushI::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(1) << endl;
}
;

PopScalar::PopScalar(string _opCode, string _var) : Stmt(_opCode) {
	Instruction = "PopScalar";
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
ostream& PopScalar::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(1) << endl;
}
;

PopArray::PopArray(string _opCode, string _var) : Stmt(_opCode) {
	Instruction = "PopArray";
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
ostream& PopArray::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(1) << endl;
}
;

Pop::Pop(string _opCode) : Stmt(_opCode) {
	Instruction = "Pop";
}
string Pop::getOther(int index)
{
	return "";
}
ostream& Pop::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Dup::Dup(string _opCode) : Stmt(_opCode) {
	Instruction = "Dup";
}
string Dup::getOther(int index)
{
	return "";
}
ostream& Dup::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Swap::Swap(string _opCode) : Stmt(_opCode) {
	Instruction = "Swap";
}
string Swap::getOther(int index)
{
	return "";
}
ostream& Swap::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Add::Add(string _opCode) : Stmt(_opCode) {
	Instruction = "Add";
}
string Add::getOther(int index)
{
	return "";
}
ostream& Add::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Negate::Negate(string _opCode) : Stmt(_opCode) {
	Instruction = "Negate";
}
string Negate::getOther(int index)
{
	return "";
}
ostream& Negate::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Mul::Mul(string _opCode) : Stmt(_opCode) {
	Instruction = "Mul";
}
string Mul::getOther(int index)
{
	return "";
}
ostream& Mul::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Div::Div(string _opCode) : Stmt(_opCode) {
	Instruction = "Mul";
}
string Div::getOther(int index)
{
	return "";
}
ostream& Div::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

Prints::Prints(string _opCode, string _str, int _strIndex) : Stmt(_opCode) {
	Instruction = "Prints";
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
ostream& Prints::print(ostream& ostr)
{
	return ostr << Instruction << " " << getOther(2) << endl;
}
;

PrintTOS::PrintTOS(string _opCode) : Stmt(_opCode) {
	Instruction = "PrintTOS";
}
string PrintTOS::getOther(int index)
{
	return "";
}
ostream& PrintTOS::print(ostream& ostr)
{
	return ostr << Instruction << endl;
}
;

