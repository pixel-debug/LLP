#ifndef ARRAY_VALUE_H
#define ARRAY_VALUE_H

#include "Value.h"
#include <vector>

class ArrayValue : public Value<std::vector<Type*>>{
	public:

		ArrayValue(std::vector<Type*> value);

		virtual ~ArrayValue();
		virtual std::vector<Type*> value();

	private:
		std::vector<Type*> m_value;
};
#endif
