#include <stdio.h>
#include <iostream>
#include "string.h"

#include "OutputCommand.h"
#include "../value/StringValue.h"
#include "../value/IntegerValue.h"
#include "../value/Value.h"
OutputCommand::OutputCommand(int line, enum OutputCommand::OutputOp op, Expr* expr)
			: Command(line), m_op(op), m_expr(expr){

}
OutputCommand::~OutputCommand(){

}
void OutputCommand::execute(){
	if(m_op == OutputCommand::PutsOp){
		std::cout << std::endl;
	}
	if(m_expr != NULL){
		Type* v = m_expr->expr();
		int v0 = ((IntegerValue*)v)->value();
		std::string sv = std::to_string(v0);
		std::cout << sv ;
		// deveria ser print

	}
}
// 2:41:51
