#include "WhileCommand.h"



WhileCommand::WhileCommand(int line, BoolExpr* cond, Command* cmd)
				: Command(line), m_cond(cond), m_cmds(cmd){

				}

WhileCommand::~WhileCommand(){
	delete m_cond;
	delete m_cmds;
}
void WhileCommand::execute(){
	while(m_cond -> expr())
		m_cmds->execute();
}

