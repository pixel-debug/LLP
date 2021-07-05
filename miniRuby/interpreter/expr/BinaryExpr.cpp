#include "BinaryExpr.h"
#include "../value/IntegerValue.h"
#include "../value/StringValue.h"
#include "../value/ArrayValue.h"

#include <string.h>
#include <iostream>
#include <vector>

BinaryExpr::BinaryExpr(int line, Expr* left, enum BinaryExpr::BinaryOp bp, Expr* right)
			:Expr(line), m_left(left), m_bp(bp), m_right(right){
}
BinaryExpr::~BinaryExpr(){
	delete m_left;
    delete m_right;
}

Type* BinaryExpr::expr(){
	Type* t0 = m_left->expr();
	Type* t1 = m_right->expr();


	int v0 = ((IntegerValue*) t0)->value();
	int v1 = ((IntegerValue*) t1)->value();




	switch (m_bp){
		case RangeWithOp:
			for( int i = v0; i <= v1; i++)
				return new IntegerValue(i);
			break;
		case RangeWithoutOp:
			for( int i = v0; i < v1; i++)
				return new IntegerValue(i);
			break;
		case AddOp:
			if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType)
				return new IntegerValue(v0 + v1);
			else if (t1->type() == Type::StringType && t1->type() == Type::StringType){
				std::string v0 = ((StringValue*)t0)->value();
				std::string v1 = ((StringValue*)t1)->value();

				std::string va = v0 + v1;
				va.replace(va.begin(), va.end(), "\'", " ");
				va = va +"\'";

				return new StringValue(va);
			}
			else if (t1->type() == Type::ArrayType && t1->type() == Type::ArrayType){
				std::vector<Type*> v0 = ((ArrayValue*)t0)->value();
				std::vector<Type*> v1 = ((ArrayValue*)t1)->value();

				std::vector<Type*> uniao;
				uniao.insert(v0.end(), v1.begin(), v1.end());

				return new ArrayValue(uniao);

			}

			break;
		case SubOp:
			return new IntegerValue(v0 - v1);
			break;
		case MulOp:
			return new IntegerValue(v0 * v1);
			break;
		case DivOp:
			return new IntegerValue(v0 / v1);
			break;
		case ModOp:
			return new IntegerValue(v0%v1);
			break;
		case ExpOp:
			return new IntegerValue(v0 * v1);
			break;
		default:
			break;
		}

}
