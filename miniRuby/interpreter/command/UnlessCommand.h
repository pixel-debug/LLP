#ifndef UNLESS_COMMAND_H
#define UNLESS_COMMAND_H

#include "Command.h"
#include "../expr/BoolExpr.h"

class UnlessCommand : public Command{
	public:
		UnlessCommand(int line, BoolExpr* cond, Command* thenCmds, Command* elseCmds = 0);

		virtual ~UnlessCommand();
		virtual void execute();

	private:
		BoolExpr* m_cond;
		Command* m_thenCmds;
		Command* m_elseCmds;
};
#endif
