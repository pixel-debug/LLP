#include "UnlessCommand.h"
#include "iostream"

UnlessCommand::UnlessCommand(int line, BoolExpr* cond, Command* thenCmds, Command* elseCmds)
			:Command(line), m_cond(cond), m_thenCmds(thenCmds), m_elseCmds(elseCmds){
}

UnlessCommand::~UnlessCommand(){

	delete(m_cond);
	delete(m_thenCmds);
	delete(m_elseCmds);

}
void UnlessCommand::execute(){
	if(!(m_cond->expr())){
		m_thenCmds->execute();
	}
	else{
		if(m_elseCmds != NULL)
			m_elseCmds->execute();
	}
}
