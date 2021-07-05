#include "UntilCommand.h"

UntilCommand::UntilCommand(int line, BoolExpr* cond, Command* cmds)
			:Command(line), m_cond(cond), m_cmds(cmds){
}

UntilCommand::~UntilCommand(){
	delete m_cond;
	delete m_cmds;
}
void UntilCommand::execute(){
	while(!(m_cond->expr())){
		m_cmds->execute();
	}
}
