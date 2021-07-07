#include "BlocksCommand.h"


BlocksCommand::BlocksCommand(int line, std::list<Command*> cmds)
				: Command(line), m_cmds(cmds){

				}

BlocksCommand::~BlocksCommand(){

}

void BlocksCommand::execute(){
	for(Command* cmds : m_cmds){
		cmds->execute();
	}
}




