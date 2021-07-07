#include "ArrayExpr.h"
#include "../value/Value.h"
#include "../value/ArrayValue.h"
#include <iostream>
#include <vector>

ArrayExpr::ArrayExpr(int line, std::list<Expr*> exprs)
				: Expr(line), m_exprs(exprs){


				}
ArrayExpr::~ArrayExpr(){


}

Type* ArrayExpr::expr(){
	std::vector<Type*> res;
	for(Expr* e : m_exprs){
		Type* v = e->expr();
		res.push_back(v);
	}
	ArrayValue* av = new ArrayValue(res);
	return av;
}
