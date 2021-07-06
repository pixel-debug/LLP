#ifndef MEMORY_H
#define MEMORY_H

#include <map>

#include <string>
#include "../value/Type.h"

class Memory {
	public:
		static Type* read(const std::string& name);
		static void write(const std::string& name, Type* value);



	private:
		static std::map<std::string, Type*> memory;


};

#endif
