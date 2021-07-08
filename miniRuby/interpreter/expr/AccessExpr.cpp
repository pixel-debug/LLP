#include "AccessExpr.h"
#include "../value/ArrayValue.h"
#include "../value/IntegerValue.h"
#include "../value/StringValue.h"
#include "SetExpr.h"
#include "../util/Utils.h"

#include "iostream"
AccessExpr::AccessExpr(int line, Expr* base, Expr* index)
			:SetExpr(line), m_base(base), m_index(index){

}

AccessExpr::~AccessExpr(){

}
Type* AccessExpr::expr(){
	Type* t0 = m_base->expr();
	Type* t1 = m_index->expr();

	if(t0->type() != Type::ArrayType)
		Utils::abort(AccessExpr::getLine());

	if(t1->type() != Type::IntegerType)
		Utils::abort(AccessExpr::getLine());

	ArrayValue* av = dynamic_cast<ArrayValue*>(t0);
	IntegerValue* iv = dynamic_cast<IntegerValue*>(t1);

	std::vector<Type*>* v = av->value();
	int i = iv->value();

	if(i >= v->size() || i < 0)
		Utils::abort(AccessExpr::getLine());
	return (*v)[i];

}

void AccessExpr::setValue(Type* value){
	Type* t0 = m_base->expr();
	Type* t1 = m_index->expr();

	if(t0->type() != Type::ArrayType)
		Utils::abort(AccessExpr::getLine());

	if(t1->type() != Type::IntegerType)
		Utils::abort(AccessExpr::getLine());

	ArrayValue* av = dynamic_cast<ArrayValue*>(t0);
	IntegerValue* iv = dynamic_cast<IntegerValue*>(t1);

	std::vector<Type*>* v = av->value();
	int i = iv->value();

	if(i >= v->size() || i < 0)
		Utils::abort(AccessExpr::getLine());
	(*v)[i] = value;
}

