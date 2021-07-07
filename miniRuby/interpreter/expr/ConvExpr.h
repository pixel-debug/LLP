#ifndef CONV_EXPR_H
#define CONV_EXPR_H


#include "Expr.h"
#include "../value/Value.h"

class ConvExpr : public Expr{
	public:
		enum ConvOp
			{
				PlusOp,
				MinusOp,
				NoneOp
			};
		ConvExpr(int line, enum ConvOp cp, Expr* expr);
		virtual ~ConvExpr();

		virtual Type* expr();



	private:
		enum ConvOp m_cp;
		Expr* m_expr;


};
#endif
