#ifndef INPUT_EXPR_H
#define INPUT_EXPR_H


#include "Expr.h"
#include "../value/Value.h"

class InputExpr : public Expr{
	public:
		enum InputOp
			{
				GetsOp,
				RandOp
			};
		InputExpr(int line, enum InputOp op);
		virtual ~InputExpr();

		virtual Type* expr();



	private:
		enum InputOp m_op;

};
#endif
