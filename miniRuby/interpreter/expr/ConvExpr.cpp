#include "ConvExpr.h"
#include "../value/IntegerValue.h"
#include "../util/Utils.h"
#include <iostream>

ConvExpr::ConvExpr(int line, enum ConvOp cp, Expr* expr)
		:	Expr(line), m_cp(cp), m_expr(expr) {

}
ConvExpr::~ConvExpr(){

}

Type* ConvExpr::expr(){
	std::cout << "oi" << std::endl;
	Type* v = m_expr->expr();


	if (!v->type() == Type::IntegerType)
		Utils::abort(Expr::getLine());

	if (m_cp == ConvOp::MinusOp) {

		IntegerValue* iv = (IntegerValue*) v;
		int n = iv->value();
		IntegerValue* neg = new IntegerValue(-n);
		v = neg;
	}

	return v;
}


