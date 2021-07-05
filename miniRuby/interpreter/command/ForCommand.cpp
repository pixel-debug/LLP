#include "ForCommand.h"
#include "../value/IntegerValue.h"
#include "../value/ArrayValue.h"
#include "../util/Utils.h"

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

		int j = ((IntegerValue*)m_expr->expr())->value();
		int i = ((IntegerValue*)m_var->expr())->value();
		while(i < j){
			m_cmds->execute();
			i++;
			m_var->setValue(new IntegerValue(i));
		}
	}else if(t0->type() == Type::ArrayType){
		std::vector<Type*> v0 = ((ArrayValue*)m_expr->expr())->value();
		int j = ((IntegerValue*)v0.front())->value();
		int i = ((IntegerValue*)v0.back())->value();

		while(i < j){
			m_cmds->execute();
			i++;
			m_var->setValue(new IntegerValue(i));
		}
	}
	else
		Utils::abort(ForCommand::getLine());
}
