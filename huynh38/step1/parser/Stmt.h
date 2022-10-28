#include <string>
using namespace std;

class Stmt {
public:
	string desclscal();
	string declarr();
	string label();
	string gosublabel();
	string start();
	string end();
	string exit();
	string jumpzero();
	string jumpnzero();
	string gosub();
	string ret();
	string pushscal();
	string pusharr();
	string pushi();
	string pop();
	string popscal();
	string poparr();
	string dup();
	string swap();
	string add();
	string negate();
	string mul();
	string div();
	string printtos();
	string prints();

};