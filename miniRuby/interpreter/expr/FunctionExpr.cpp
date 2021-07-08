#include "FunctionExpr.h"
#include "../util/Utils.h"
#include "../value/ArrayValue.h"
#include "../value/IntegerValue.h"
#include "../value/StringValue.h"

#include "string.h"
#include "iostream"

#include <vector>

FunctionExpr::FunctionExpr(int line, Expr* expr, enum FunctionOp fp)
		:	Expr(line), m_expr(expr), m_fp(fp) {

}
FunctionExpr::~FunctionExpr(){

}

Type* FunctionExpr::expr(){

	Type* v = m_expr->expr();
	// if (v->type() == Type::IntegerType)
	// 	Utils::abort(Expr::getLine());

	if (m_fp == FunctionOp::LenghtOp) {
		if (!(v->type() == Type::ArrayType))
			Utils::abort(Expr::getLine());
		else{
			std::vector<Type*>* v0 = ((ArrayValue*)v)->value();

			// std::vector<Type*> vec = v0;
			// vec = v0;

			int len = v0->size();

			return new IntegerValue(len);

		}
	}
	if (m_fp == FunctionOp::ToIntOp) {
		if (!(v->type() == Type::StringType))
			Utils::abort(Expr::getLine());

		else{
			std::string sv = ((StringValue*)v)->value();
			int n = std::stoi(sv);

			return new IntegerValue(n);
		}
	}
	if (m_fp == FunctionOp::ToStringOp) {

		int v0 = ((IntegerValue*)v)->value();
		std::string s = std::to_string(v0);
		return new StringValue(s);
	}
}


