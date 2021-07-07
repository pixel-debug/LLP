#ifndef COMPOSITE_BOOL_EXPR_H
#define COMPOSITE_BOOL_EXPR_H

#include "BoolExpr.h"
#include "../value/Value.h"

class CompositeBoolExpr : public BoolExpr{
	public:
		enum BoolOp{
			And,
			Or,
			NoneOp
		};

		CompositeBoolExpr(int line, BoolExpr* left, enum BoolOp op, BoolExpr* right);
		virtual ~CompositeBoolExpr();

		virtual bool expr();



	private:

		BoolExpr* m_left;
		enum BoolOp m_op;
		BoolExpr* m_right;

};
#endif
