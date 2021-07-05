
#include "Memory.h"

std::map<std::string, Type*> Memory::memory;
std::set<std::string> Memory::consts;

Type* Memory::read(const std::string& name) {
	return memory[name];
}

void Memory::write(const std::string& name, Type* value) {
	if(consts.find(name)==Memory::consts.end())
		memory[name] = value;
	else{
		printf("Nao dá para sobescrever constantes!\n");
		exit(1);
	}
}
