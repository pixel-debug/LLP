#include "../value/Value.h"
#include "../value/IntegerValue.h"
#include "../value/StringValue.h"
#include "../value/ArrayValue.h"
#include "SingleBoolExpr.h"
#include "../util/Utils.h"


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

SingleBoolExpr::SingleBoolExpr(int line, Expr* left, enum SingleBoolExpr::RelOp op, Expr* right)
  : BoolExpr(line), m_left(left), m_op(op), m_right(right){}

SingleBoolExpr::~SingleBoolExpr(){
  delete m_left;
  delete m_right;
}

bool SingleBoolExpr::expr(){
	Type* t1 = m_left->expr();
  	Type* t2 = m_right->expr();


	switch (m_op)
	{
	case EqualsOp:
		if(t1->type() == Type::IntegerType && t2->type() == Type::IntegerType){
			int v0 = ((IntegerValue*)t1)->value();
			int v1 = ((IntegerValue*)t2)->value();
			return v0 == v1;
		}
		else if(t1->type() == Type::StringType && t2->type() == Type::StringType){
			std::string v0 = ((StringValue*)t1)->value();
			std::string v1 = ((StringValue*)t2)->value();
			return v0.compare(v1);
		}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	case NotEqualsOp:
		if(t1->type() == Type::IntegerType && t2->type() == Type::IntegerType){
			int v0 = ((IntegerValue*)t1)->value();
			int v1 = ((IntegerValue*)t2)->value();
			return v0 != v1;
		}
		else if(t1->type() == Type::StringType && t2->type() == Type::StringType){
			std::string v0 = ((StringValue*)t1)->value();
			std::string v1 = ((StringValue*)t2)->value();
			return (!v0.compare(v1));
		}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}

		break;
	case LowerThanOp:
		if(t1->type() == Type::IntegerType && t2->type() == Type::IntegerType){
				int v0 = ((IntegerValue*)t1)->value();
				int v1 = ((IntegerValue*)t2)->value();
				return v0 < v1;
			}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	case GreaterThanOp:
		if(t1->type() == Type::IntegerType && t2->type() == Type::IntegerType){
				int v0 = ((IntegerValue*)t1)->value();
				int v1 = ((IntegerValue*)t2)->value();
				return v0 > v1;
			}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	case LowerEqualOp:
		if(t1->type() == Type::IntegerType && t2->type() == Type::IntegerType){
			int v0 = ((IntegerValue*)t1)->value();
			int v1 = ((IntegerValue*)t2)->value();
			return v0 <= v1;
		}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	case GreaterEqualOp:
		if(t1->type() == Type::IntegerType && t2->type() == Type::IntegerType){
				int v0 = ((IntegerValue*)t1)->value();
				int v1 = ((IntegerValue*)t2)->value();
				return v0 >= v1;
			}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	case ContainsOp:

		if(t1->type() == Type::IntegerType && t2->type() == Type::ArrayType){

			IntegerValue* iv = dynamic_cast<IntegerValue*>(t1);
			int i = iv->value();

			ArrayValue* av = dynamic_cast<ArrayValue*>(t2);
			std::vector<Type*>* v = av->value();

			for(int j = 0; j < v->size(); j++){
				Type* t = (*v)[j];
				if(t->type() == Type::IntegerType){
					IntegerValue* iv2 = dynamic_cast<IntegerValue*>(t);
					int itemp = iv2->value();
					if(itemp == i){
						return true;
					}
				}
			}
		}
		else if (t1->type() == Type::StringType && t2->type() == Type::ArrayType){
			StringValue* sv = dynamic_cast<StringValue*>(t1);
			std::string s = sv->value();

			ArrayValue* av = dynamic_cast<ArrayValue*>(t2);
			std::vector<Type*>* v = av->value();

			for(int j = 0; j < v->size(); j++){
				Type* t = (*v)[j];
				if(t->type() == Type::StringType){
					StringValue* iv2 = dynamic_cast<StringValue*>(t);
					std::string stemp = iv2->value();
					if(stemp == s){
						return true;
					}
				}
			}
		}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	}
	return false;
}
