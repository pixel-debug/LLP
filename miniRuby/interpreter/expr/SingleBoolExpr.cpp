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

				std::vector<Type*> v1 = ((ArrayValue*)t2)->value();

				if(std::find(v1.end(), v1.begin(), t1) != v1.end()){
					return true;
				}

				else
					return false;
			}
		else if (t1->type() == Type::StringType && t2->type() == Type::ArrayType){
				std::vector<Type*> v1 = ((ArrayValue*)t2)->value();

				if(std::find(v1.end(), v1.begin(), t1) != v1.end()){
					return true;
				}
				else
					return false;
			}
		else{
			Utils::abort(SingleBoolExpr::getLine());
		}
		break;
	default:
		break;
	}
}
