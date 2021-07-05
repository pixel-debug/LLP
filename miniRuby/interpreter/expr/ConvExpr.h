#ifndef CONV_EXPR_H
#define CONV_EXPR_H


#include "Expr.h"
#include "../value/Value.h"

class ConvExpr : public Expr{
	public:
		enum ConvOp
			{
				PlusOp,
				MinusOp
			};
		ConvExpr(int line, enum ConvOp cp, Expr* expr);
		virtual ~ConvExpr();

		virtual Type* expr();



	private:
		Expr* m_expr;
		enum ConvOp m_cp;

};
#endif