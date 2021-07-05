#ifndef SINGLE_BOOL_EXPR_H
#define SINGLE_BOOL_EXPR_H


#include "BoolExpr.h"
#include "Expr.h"
#include "../value/Value.h"

class SingleBoolExpr : public BoolExpr{
	public:
		enum RelOp
			{
				EqualsOp,
				NotEqualsOp,
				LowerThanOp,
				LowerEqualOp,

				GreaterThanOp,
				GreaterEqualOp,
				ContainsOp
			};
		SingleBoolExpr(int line, Expr* left, enum RelOp op, Expr* right);
		virtual ~SingleBoolExpr();

		virtual bool expr();



	private:
		Expr* m_left;
		Expr* m_right;
		enum RelOp m_op;

};
#endif
