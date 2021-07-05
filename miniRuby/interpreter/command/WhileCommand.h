#ifndef WHILE_COMMAND_H
#define WHILE_COMMAND_H

#include "Command.h"
#include "../expr/BoolExpr.h"

class WhileCommand : public Command{
	public:

		WhileCommand(int line, BoolExpr* cond, Command* cmd = 0);

		virtual ~WhileCommand();
		virtual void execute();

	private:
		BoolExpr* m_cond;
		Command* m_cmds;
};
#endif
