#ifndef ASSIGN_COMMAND_H
#define ASSIGN_COMMAND_H

#include<vector>
#include "Command.h"
#include "../expr/Expr.h"

class AssignCommand : public Command{
	public:
		AssignCommand(int line, std::vector<Expr*> left, std::vector<Expr*> right);

		virtual ~AssignCommand();
		virtual void execute();

	private:
		std::vector<Expr*> m_left;
		std::vector<Expr*> m_right;
};
#endif
