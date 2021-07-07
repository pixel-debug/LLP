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
				ExpOp,
				NoneOp
			};
					BinaryExpr(int line, Expr* left, enum BinaryOp bp, Expr* right);
					virtual ~BinaryExpr();

					virtual Type* expr();

			private:
				Expr* m_left;
				enum BinaryOp m_bp;
				Expr* m_right;

};


#endif
