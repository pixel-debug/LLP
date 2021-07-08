#include "ForCommand.h"
#include "../value/IntegerValue.h"
#include "../value/ArrayValue.h"
#include "../util/Utils.h"
#include <iostream>

ForCommand::ForCommand(int line, Variable* var, Expr* expr, Command* cmd)
			:Command(line), m_var(var), m_expr(expr), m_cmds(cmd){

			}

ForCommand::~ForCommand(){
	delete m_var;
	delete m_expr;
	delete m_cmds;

}
void ForCommand::execute(){
	Type* t0 = m_expr->expr();

	if(t0->type() == Type::IntegerType){
		m_var->setValue(new IntegerValue(0));
		int i = stoi(m_var->expr()->str());
		int j = stoi(t0->str());

		while(i <= j){
			m_cmds->execute();
			i++;
			m_var->setValue(new IntegerValue(i));
		}
	}
	else if(t0->type() == Type::ArrayType){
		ArrayValue* av = dynamic_cast<ArrayValue*>(t0);
		std::vector<Type*>* v = av->value();

		int i = stoi((v->front()->str()));

		m_var->setValue(new IntegerValue(i));

		int j = stoi((v->back()->str()));

		while(i <= j){
			m_cmds->execute();
			i++;
			m_var->setValue(new IntegerValue(i));
		}
	}
	else
		Utils::abort(ForCommand::getLine());
}
