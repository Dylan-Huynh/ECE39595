#include "Stmt.h"
#include "SymbolTable.h"
#include "InstructionBuffer.h"
#include "StringBuffer.h"
#include "StmtExtensions.h"
#include <string>

using namespace std;

Stmt::Stmt(string _opCode) : opCode{ _opCode } {};

string Stmt::getOther(int index) {
	return "";
}

void Stmt::setOther() {

}
void Stmt::setOther(string _string)
{
}
void Stmt::setOther(int _int)
{
}
;

ostream& Stmt::print(ostream& ostr)
{
	return ostr << "Wrong inheritance" << endl;
}
