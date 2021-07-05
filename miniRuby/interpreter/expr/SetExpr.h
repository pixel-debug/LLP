#ifndef SET_EXPR_H
#define SET_EXPR_H


#include "Expr.h"



class SetExpr: public Expr{
	public:
		virtual ~SetExpr(){}

		virtual Type* expr() = 0;

		void setValue(Type* value);

	protected:
		SetExpr(int line) : Expr(line){}

};



#endif
