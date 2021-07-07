#ifndef IF_COMMAND_H
#define IF_COMMAND_H

#include <iostream>
#include "Command.h"
#include "../expr/BoolExpr.h"
#include "../command/Command.h"

class IfCommand: public Command{

			public:

				IfCommand(int line, BoolExpr* cond, Command* thenCommands);

				virtual ~IfCommand();

				virtual void setElseCommands(Command* elseCommands);

				virtual void execute();

			private:
				BoolExpr* m_cond;
				Command* m_thenCommands;
				Command* m_elseCommands;

};

#endif
