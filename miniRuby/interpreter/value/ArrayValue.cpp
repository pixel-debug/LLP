#include "ArrayValue.h"
#include "string.h"
#include <sstream>
#include <iostream>

ArrayValue::ArrayValue(std::vector<Type*> value)
			: Value(Type::ArrayType), m_value(value){

			}
ArrayValue::~ArrayValue(){

}
std::vector<Type*> ArrayValue::value(){
	return m_value;
}

std::string ArrayValue::str(){
	std::stringstream ss;

	ss << '[';
	for(int i = 0; i < m_value.size(); i++){
		Type* t = m_value[i];
		ss << (i == 0 ? " " : ", ");
		ss << (t == nullptr ? "" : t->str());
	}

	ss << " ]";
	return ss.str();
}
