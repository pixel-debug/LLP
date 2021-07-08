#include "Variable.h"
#include <iostream>
#include <sstream>

Variable::Variable(int line, const std::string& name)
	: SetExpr(line), name(name) {
}

Variable::~Variable() {
}

Type* Variable::expr() {
	return Memory::read(name);
}

void Variable::setValue(Type* value) {
	Memory::write(name, value);
}


