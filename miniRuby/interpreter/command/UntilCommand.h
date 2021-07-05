#ifndef UNTIL_COMMAND_H
#define UNTIL_COMMAND_H

#include "Command.h"
#include "../expr/BoolExpr.h"

class UntilCommand : public Command{
	public:
		UntilCommand(int line, BoolExpr* cond, Command* cmds = 0);

		virtual ~UntilCommand();
		virtual void execute();

	private:
		BoolExpr* m_cond;
		Command* m_cmds;
};
#endif
