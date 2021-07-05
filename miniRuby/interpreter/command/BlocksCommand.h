#ifndef BLOCKS_COMMAND_H
#define BLOCKS_COMMAND_H

#include "Command.h"
#include <list>

class BlocksCommand : public Command{
	public:
		BlocksCommand(int line, std::list<Command*> cmds);

		virtual ~BlocksCommand();

		virtual void execute();


	private:
		std::list<Command*> m_cmds;
};
#endif
