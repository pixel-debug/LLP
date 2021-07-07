#include "AccessExpr.h"
#include "../value/ArrayValue.h"
#include "../value/IntegerValue.h"
#include "../value/StringValue.h"
#include "SetExpr.h"
#include "../util/Utils.h"

#include "iostream"
AccessExpr::AccessExpr(int line, Expr* base, Expr* index)
			:SetExpr(line), m_base(base), m_index(index){

}

AccessExpr::~AccessExpr(){

}
Type* AccessExpr::expr(){
	Type* t0 = m_base->expr();
	Type* t1 = m_index->expr();

	if(m_index == NULL)
		Utils::ioob(AccessExpr::getLine());
	else{
		int indice = 0;
		if(!(t0->type() == Type::ArrayType))
			Utils::abort(AccessExpr::getLine());
		else{
			std::vector<Type*> av = ((ArrayValue*)t0)->value();
			std::vector<Type*> vec = av;

			if(t1->type() == Type::IntegerType){
				indice = ((IntegerValue*) t1)->value();
			}
			else if(t1->type() == Type::StringType){
				std::string sv = ((StringValue*)t1)->value();
				indice = std::stoi(sv);
			}
			else{
				Utils::abort(AccessExpr::getLine());
			}
			return vec[indice];
		}
	}
	return t0;
}

void AccessExpr::setValue(Type* value){
	Type* t0 = m_base->expr();
	Type* t1 = m_index->expr();


	SetExpr* set = (SetExpr*)t0;



	if(m_index == NULL){
		if(value->type() == Type::IntegerType){
			int t3 = ((IntegerValue*) value)->value();
			IntegerValue* indice = new IntegerValue(t3);
			set->setValue(indice);
		}
		if(value->type() == Type::StringType){
			std::string t3 = ((StringValue*) value)->value();
			StringValue* indice = new StringValue(t3);
			set->setValue(indice);
		}
		else{
			set->setValue(value);
		}
	}
	else{
		int indice = 0;
		if(!(t0->type() == Type::ArrayType))
			Utils::abort(AccessExpr::getLine());
		else{
			std::vector<Type*> vec = ((ArrayValue*)t0)->value();

			if(t1->type() == Type::IntegerType){
				indice = ((IntegerValue*) t1)->value();
			}
			else if(t1->type() == Type::StringType){
				std::string sv = ((StringValue*)t1)->value();
				indice = std::stoi(sv);
			}
			else{
				Utils::abort(AccessExpr::getLine());
			}
			vec[indice] = value;
			ArrayValue* av = new ArrayValue(vec);

			set->setValue(vec[indice]);
			std::cout << vec[indice]->str() << ' ' << std::endl;
		}
	}
}

