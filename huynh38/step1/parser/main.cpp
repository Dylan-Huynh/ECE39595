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

	if (argc != 3) {
		cerr << "Input is not Correct" << endl;
		return -1;
	}
	string line;
	ifstream inFile;
	inFile.open(argv[1]);
	ofstream outFile;
	outFile.open(argv[2]);
	if (outFile.fail()) {
		cerr << "failed to open file " << argv[2] << ", terminating" << endl;
		return -1;
	}
	if (inFile.is_open()) {
		getline(inFile, line);
		string op = parse(line);
		if (op != "start") {
			cerr << "nothing should come before" << endl;
			exit(0);
		}
		while (getline(inFile, line)) {
			// parse each statement line by line
			op = parse(line);
			if (op == "") {
				cerr << "error in parser" << endl;
				exit(0);
			}
			if (op == "end") {
				if (getline(inFile, line)) {
					cerr << "nothing should come after end" << endl;
					exit(0);
				}
				for (int i = 0; i < stringBuffer->getSize(); i++) {
					cout << stringBuffer->getString(i) << endl;
					outFile << stringBuffer->getString(i) << endl;
				}
				int inScope = 1;
				for (int i = 0; i < instructionBuffer->getSize(); i++) {
					Stmt* currStmt = instructionBuffer->getStmt(i);
					string jump = currStmt->opCode;
					
					if (jump == "gosublabel") {
						inScope = 0;
					}
					if (jump == "return") {
						inScope = 1;
					}
					if (inScope && (jump == "jump" || jump == "jumpzero" || jump == "jumpnzero" || jump == "gosub")) {
						string label = currStmt->getOther(1);
						int lineNum = symbolTable->getEntry(label).first;;
						currStmt->setOther(lineNum);
					}
					if (jump == "start") {
						currStmt->setOther(varCount);
					}
					currStmt->print(outFile);
					currStmt->print(cout);
					
				}
			}
		}
		inFile.close();
		outFile.close();
	}
	else {
		cerr << "failed to open file " << argv[1] << ", terminating" << endl;
		return -1;
	}
	return 0;

}


string parse(string line) {
	string delimiter = " ";
	string opCode = line.substr(0, line.find(delimiter));
	//cout << "OpCode: " << opCode << endl;

	if (opCode == "declscal") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<int, int> entry (symbolTable->getSize(), 1);
		symbolTable->insertEntry(var, entry);
		if (symbolTable->getScope() > 0) {
			localVarCount++;
		}
		else {
			varCount++;
		}
		return opCode;
	}
	if (opCode == "declarr") {
		//cout << line.find(" ", line.find(" ") + 1) - line.find(" ") - 1 << endl;
		string var = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1) - line.find(" ") - 1);
		string length = line.substr(line.find(" ", line.find(" ") + 1) + 1, line.length());
		//cout << var << endl;
		pair<int, int> entry(symbolTable->getSize(), stoi(length));
		symbolTable->insertEntry(var, entry);
		if (symbolTable->getScope() > 0) {
			localVarCount += stoi(length);
		}
		else {
			varCount += stoi(length);
		}
		return opCode;
	}
	if (opCode == "label") {
		string label = line.substr(line.find(" ") + 1, line.length());
		int instructionLine = instructionBuffer->getSize();
		pair<int, int> entry(instructionLine, 0);
		symbolTable->getInstance()->insertEntry(label, entry);
		return opCode;
	}
	if (opCode == "gosublabel") {
		string label = line.substr(line.find(" ") + 1, line.length());
		int lineNum = instructionBuffer->getSize();
		pair<int, int> entry(lineNum, 0);
		symbolTable->insertEntry(label, entry);
		symbolTable->setScope(1);
		Stmt* enter = new Enter("gosublabel", label);
		instructionBuffer->insertStmt(enter);
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
		
		Stmt* ret = new Return("return");
		instructionBuffer->insertStmt(ret);
		int inScope = 0;
		for (int i = 0; i < instructionBuffer->getSize(); i++) {
			Stmt* currStmt = instructionBuffer->getStmt(i);
			string jump = currStmt->opCode;
			if (jump == "gosublabel") {
				currStmt->setOther(localVarCount);
				inScope = 1;
			}
			
			if (inScope && (jump == "jump" || jump == "jumpzero" || jump == "jumpnzero")) {
				string label = currStmt->getOther(1);
				int lineNum = symbolTable->getEntry(label).first;
				currStmt->setOther(lineNum);
			}
			if (inScope && jump == "gosub") {
				string label = currStmt->getOther(1);
				int lineNum = 0;
				currStmt->setOther(lineNum);
			}

		}
		symbolTable->getInstance()->setScope(0);
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
		pair<int, int> entry = symbolTable->getEntry(var);
		Stmt* pushscal = new PushScalar("pushscal", to_string(entry.first));
		instructionBuffer->insertStmt(pushscal);
		return opCode;
	}
	if (opCode == "pusharr") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<int, int> entry = symbolTable->getEntry(var);
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
		pair<int, int> entry = symbolTable->getInstance()->getEntry(var);
		Stmt* popscal = new PopScalar("popscal", to_string(entry.first));
		instructionBuffer->insertStmt(popscal);
		return opCode;
	}
	if (opCode == "poparr") {
		string var = line.substr(line.find(" ") + 1, line.length());
		pair<int, int> entry = symbolTable->getInstance()->getEntry(var);
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
		stringBuffer->insertString(printStatement);
		string location = to_string(stringBuffer->getSize());
		Stmt* prints = new Prints("prints", location, stringBuffer->getSize() - 1);
		instructionBuffer->insertStmt(prints);
		return opCode;
	}
	
	return "";

}