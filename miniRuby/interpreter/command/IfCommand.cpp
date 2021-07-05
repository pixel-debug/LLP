#include "IfCommand.h"

IfCommand::IfCommand(int line, BoolExpr *cond, Command *thenCommands)
    : Command(line), cond(cond), thenCommands(thenCommands), m_elseCommands(NULL){
    };

IfCommand::~IfCommand(){
  delete cond;
  delete thenCommands;
  delete m_elseCommands;
}

void IfCommand::setElseCommands(Command* elseCommands){
  m_elseCommands = elseCommands;
};

void IfCommand::execute(){
	if(cond->expr()){
		thenCommands->execute();
	}
	else if(m_elseCommands!=NULL){
		m_elseCommands->execute();
	}
}
