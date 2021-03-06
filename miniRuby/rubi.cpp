#include <iostream>
#include <cstdlib>
#include <string>

#include "interpreter/command/Command.h"
#include "lexical/LexicalAnalysis.h"
#include "syntatic/SyntaticAnalysis.h"

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cout << "Usage: "<< argv[0] << " [Ruby program]" << std::endl;
		exit(1);
	}
	try{
		Lexeme lex;
		LexicalAnalysis l(argv[1]);

		SyntaticAnalysis s(l);
		Command* cmd = s.start();
		cmd->execute();
		delete cmd;
		// while((lex = l.nextToken()).type > 0){
		// 	std::cout << lex.str() << std::endl;
		// }
		// std::cout << lex.str() << std::endl;

	}catch(const std::string& error){
		std::cerr << error << std::endl;

	}
	return 0;
}


