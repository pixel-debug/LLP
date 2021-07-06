#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#include "Command.h"
#include "../expr/Expr.h"

class OutputCommand : public Command{
	public:
		enum OutputOp{
									PutsOp,
									PrintOp
								};
		OutputCommand(int line, enum OutputOp op, Expr* expr = 0);

		virtual ~OutputCommand();
		virtual void execute();
	private:
		enum OutputOp m_op;
		Expr* m_expr;

};
#endif
