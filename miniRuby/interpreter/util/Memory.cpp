#include "../value/StringValue.h"
#include "Memory.h"
#include <iostream>
std::map<std::string, Type*> Memory::memory;


Type* Memory::read(const std::string& name) {
	Type* t = memory[name];

	if( t == nullptr)
		t = new StringValue("");
	return t;
}

void Memory::write(const std::string& name, Type* value) {
		memory[name] = value;

}
