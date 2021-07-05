#include "BlocksCommand.h"


BlocksCommand::BlocksCommand(int line, std::list<Command*> cmds)
				: Command(line), m_cmds(cmds){

				}

BlocksCommand::~BlocksCommand(){

}

void BlocksCommand::execute(){
	// for(std::list<Command*>::iterator it = m_cmds.begin(),
	// 		end = m_cmds.end();
	// 		it!= end;
	// 		it++){
	// 	Command* aux = *it;
	// 	aux->execute();
	// }
	for(Command* cmds : m_cmds){
		cmds->execute();
	}
}




