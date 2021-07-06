#include "StringValue.h"

#include <string>

StringValue::StringValue (std::string value)
			: Value(Type::StringType), m_value(value){

			}


StringValue::~StringValue(){

}

 std::string StringValue::str(){
	return m_value;
}
std::string StringValue::value(){
	return m_value;
}
