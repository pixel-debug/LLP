#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "SetExpr.h"
#include "../util/Memory.h"

class Variable : public SetExpr{
	public:
		Variable(int line, const std::string& name);
		virtual ~Variable();

		virtual Type *expr();
		void setValue(Type* value);
		const std::string& getName() const {return name;}

	private:
		std::string name;
		Type* value;
};

#endif
