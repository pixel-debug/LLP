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

	std::cout << ";-;";
	//ss << m_value;
	return ss.str();
}
