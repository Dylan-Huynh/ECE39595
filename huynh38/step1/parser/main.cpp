#include <map>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

#include "StringBuffer.h"
#include "InstructionBuffer.h"
#include "SymbolTable.h"
#include "Stmt.h"
#include "StmtExtensions.h"

using namespace std;

string parse(string line);

SymbolTable* symbolTable = SymbolTable::getInstance();
int instBufferReturnIndex = 0;
int varCount = 0;
int localVarCount = 0;
InstructionBuffer* instructionBuffer = InstructionBuffer::getInstance();
StringBuffer* stringBuffer = StringBuffer::getInstance();

int main(int argc, char** argv) {

	if (argc != 2) {
		cerr << "Input is not Correct" << endl;
		return -1;
	}
	string line;
	ifstream f; f.open(argv[1]);
	if (f.is_open()) {
		while (getline(f, line)) {
			// parse each statement line by line
			string op = parse(line);
			if (op == "") {
				cerr << "error in parser" << endl;
				exit(0);
			}
			if (op == "end") {
				if (getline(f, line)) {
					cerr << "nothing should come after end" << endl;
					exit(0);
				}
				for (int i = 0; i < instructionBuffer->getSize(); i++) {
					Stmt* currStmt = instructionBuffer->getStmt(i);
					string jump = currStmt->opCode;
					if (jump == "jump" || jump == "jumpzero" || jump == "jumpnzero") {
						string label = currStmt->getOther(1);
						int lineNum = symbolTable->getEntry(label).first;
						currStmt->setOther(lineNum);
					}
					cout << currStmt << endl;
					cout << currStmt->opCodeInt << endl;
					
				}
			}
		}
		f.close();
	}
	else {
		cerr << "failed to open file " << argv[1] << ", terminating" << std::endl;
		return -1;
	}
	return 0;

}


string parse(string line) {
	string delimiter = " ";
	string opCode = line.substr(0, line.find(delimiter));

	if (opCode == "declscal") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<double, double> entry (SymbolTable::getSize(), 1);
		SymbolTable::getInstance()->insertEntry(var, entry);
		return opCode;
	}
	if (opCode == "declarr") {
		string var = line.substr(line.find(" ") + 1, line.length());
		string length = line.substr(line.find(" ", line.find(" ") + 1) + 1, line.length());
		pair<double, double> entry(SymbolTable::getSize(), stoi(length));
		SymbolTable::getInstance()->insertEntry(var, entry);
		return opCode;
	}
	if (opCode == "label") {
		string label = line.substr(line.find(" ") + 1, line.length());
		int instructionLine = InstructionBuffer::getInstance()->getSize();
		pair<double, double> entry(instructionLine, 0);
		SymbolTable::getInstance()->insertEntry(label, entry);
		return opCode;
	}
	if (opCode == "gosublabel") {
		string label = line.substr(line.find(" ") + 1, line.length());
		int lineNum = InstructionBuffer::getInstance()->getSize();
		SymbolTable::getInstance()->setScope(1);
		pair<double, double> entry(lineNum, 0);
		SymbolTable::getInstance()->insertEntry(label, entry);
		Stmt* enter = new Enter("gosublabel", label);
		return opCode;
	}
	if (opCode == "start") {
		Stmt* start = new Start("start");
		instructionBuffer->insertStmt(start);
		return opCode;
	}
	if (opCode == "end") {
		return opCode;
	}
	if (opCode == "exit") {
		Stmt* exitProgram = new ExitProgram("exit");
		instructionBuffer->insertStmt(exitProgram);
		return opCode;
	}
	if (opCode == "return") {
		SymbolTable::getInstance()->setScope(0);
		Stmt* ret = new Return("return");
		instructionBuffer->insertStmt(ret);
		return opCode;
	}
	if (opCode == "jump") {
		string label = line.substr(line.find(" ") + 1, line.length());
		Stmt* jump = new Jump("jump", label);
		instructionBuffer->insertStmt(jump);
		return opCode;
	}
	if (opCode == "jumpzero") {
		string label = line.substr(line.find(" ") + 1, line.length());
		Stmt* jumpzero = new JumpZero("jumpzero", label);
		instructionBuffer->insertStmt(jumpzero);
		return opCode;
	}
	if (opCode == "jumpnzero") {
		string label = line.substr(line.find(" ") + 1, line.length());
		Stmt* jumpnzero = new JumpNZero("jumpnzero", label);
		instructionBuffer->insertStmt(jumpnzero);
		return opCode;
	}
	if (opCode == "gosub") {
		string label = line.substr(line.find(" ") + 1, line.length());
		Stmt* gosub = new GoSub("gosub", label);
		instructionBuffer->insertStmt(gosub);
		return opCode;
	}
	if (opCode == "pushscal") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<double, double> entry = SymbolTable::getInstance()->getEntry(var);
		Stmt* pushscal = new PushScalar("pushscal", to_string(entry.first));
		instructionBuffer->insertStmt(pushscal);
		return opCode;
	}
	if (opCode == "pusharr") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<double, double> entry = SymbolTable::getInstance()->getEntry(var);
		Stmt* pusharr = new PushArray("pusharr", to_string(entry.first));
		instructionBuffer->insertStmt(pusharr);
		return opCode;
	}
	if (opCode == "pushi") {
		string immediate = line.substr(line.find(" ") + 1, line.length());
		Stmt* pushi = new PushI("pushi", stoi(immediate));
		instructionBuffer->insertStmt(pushi);
		return opCode;
	}
	if (opCode == "pop") {
		Stmt* pop = new Pop("pop");
		instructionBuffer->insertStmt(pop);
		return opCode;
	}
	if (opCode == "popscal") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<double, double> entry = SymbolTable::getInstance()->getEntry(var);
		Stmt* popscal = new PopScalar("popscal", to_string(entry.first));
		instructionBuffer->insertStmt(popscal);
		return opCode;
	}
	if (opCode == "poparr") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<double, double> entry = SymbolTable::getInstance()->getEntry(var);
		Stmt* poparr = new PopArray("poparr", to_string(entry.first));
		instructionBuffer->insertStmt(poparr);
		return opCode;
	}
	if (opCode == "dup") {
		Stmt* dup = new Dup("dup");
		instructionBuffer->insertStmt(dup);
		return opCode;
	}
	if (opCode == "swap") {
		Stmt* swap = new Swap("swap");
		instructionBuffer->insertStmt(swap);
		return opCode;
	}
	if (opCode == "add") {
		Stmt* add = new Add("add");
		instructionBuffer->insertStmt(add);
		return opCode;
	}
	if (opCode == "negate") {
		Stmt* negate = new Negate("negate");
		instructionBuffer->insertStmt(negate);
		return opCode;
	}
	if (opCode == "mul") {
		Stmt* mul = new Mul("mul");
		instructionBuffer->insertStmt(mul);
		return opCode;
	}
	if (opCode == "div") {
		Stmt* div = new Div("div");
		instructionBuffer->insertStmt(div);
		return opCode;
	}
	if (opCode == "printtos") {
		Stmt* printtos = new PrintTOS("printtos");
		instructionBuffer->insertStmt(printtos);
		return opCode;
	}
	if (opCode == "prints") {
		string printStatement = line.substr(line.find(" ") + 1, line.length());
		StringBuffer::getInstance()->insertString(printStatement);
		string location = to_string(StringBuffer::getInstance()->getSize());
		Stmt* prints = new Prints("prints", location, stringBuffer->getSize() - 1);
		instructionBuffer->insertStmt(prints);
	}
	return "";

}