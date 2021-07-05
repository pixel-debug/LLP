#ifndef FUNCTION_EXPR_H
#define FUNCTION_EXPR_H


#include "Expr.h"
#include "../value/Value.h"

class FunctionExpr : public Expr{
	public:
		enum FunctionOp
			{
				LenghtOp,
				ToIntOp,
				ToStringOp
			};
		FunctionExpr(int line, Expr* expr, enum FunctionOp fp);
		virtual ~FunctionExpr();

		virtual Type* expr();



	private:
		Expr* m_expr;
		enum FunctionOp m_fp;

};
#endif
