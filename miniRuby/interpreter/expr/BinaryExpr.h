#ifndef BINARY_EXPR_H
#define BINARY_EXPR_H


#include "Expr.h"
#include "../value/Value.h"



class BinaryExpr: public Expr{
			public:

			enum BinaryOp{
				RangeWithOp,
				RangeWithoutOp,
				AddOp,
				SubOp,
				MulOp,
				DivOp,
				ModOp,
				ExpOp
			};
					BinaryExpr(int line, Expr* left, enum BinaryOp bp, Expr* right);
					virtual ~BinaryExpr();

					virtual Type* expr();

			private:
				Expr* m_left;
				Expr* m_right;
				enum BinaryOp m_bp;
};


#endif
