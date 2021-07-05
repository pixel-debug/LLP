#ifndef FOR_COMMAND_H
#define FOR_COMMAND_H

#include "Command.h"
#include "../expr/Variable.h"

class ForCommand : public Command{
	public:
		ForCommand(int line, Variable* var, Expr* expr, Command* cmd);

		virtual ~ForCommand();
		virtual void execute();

	private:
		Variable* m_var;
		Expr* m_expr;
		Command* m_cmds;
};
#endif
