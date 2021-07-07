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


	switch(m_bp){
		case RangeWithOp:
			if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());

				std::vector<Type*> vec1;
			//	std::cout << v0 << ' ' << v1 << ' ';
				if(v0 < v1){
					for( int i = v0; i <= v1; i++){
						IntegerValue* iv = new IntegerValue(i);
					//	std::cout << iv->str() << std::endl;
						vec1.push_back(iv);
					}
				}
				else if(v0 > v1){
					for( int i = v0; i >= v1; i--){
						IntegerValue* iv = new IntegerValue(i);
					//	std::cout << iv->str() << std::endl;
						vec1.push_back(iv);
					}
				}
				else{
					int i = v0;
					IntegerValue* iv = new IntegerValue(i);
					//	std::cout << iv->str() << std::endl;
					vec1.push_back(iv);
				}
				ArrayValue* av = new ArrayValue(vec1);
				//std::cout << av << std::endl;
				return av;
			}
			break;
		case RangeWithoutOp:
			if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());

				std::vector<Type*> vec1;
				//std::cout << (v0 > v1) << std::endl;
				if(v0 < v1){
					for( int i = v0; i < v1; i++){
						IntegerValue* iv = new IntegerValue(i);
					//	std::cout << iv->str() << std::endl;
						vec1.push_back(iv);
					}
				}
				else if(v0 > v1){
					for( int i = v0; i > v1; i--){
						IntegerValue* iv = new IntegerValue(i);
					//	std::cout << iv << std::endl;
						vec1.push_back(iv);
					}
				}
				else{
					int i = v0;
					IntegerValue* iv = new IntegerValue(i);
				//	std::cout << iv->str() << std::endl;
					vec1.push_back(iv);
				}
				ArrayValue* av = new ArrayValue(vec1);
				//std::cout << av << std::endl;
				return av;
			}
			break;

		case AddOp:
			if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());
				return new IntegerValue(v0 + v1);
			}

			else if (t0->type() == Type::StringType && t1->type() == Type::StringType){
			//	std::cout << "cheguei aqui na string";
				std::string v0 = t0->str();
				std::string v1 = t1->str();

				return new StringValue(v0+v1);
			}

			else if (t0->type() == Type::ArrayType && t1->type() == Type::ArrayType){
				std::cout << "cheguei aqui no array";
				std::vector<Type*> v0 = ((ArrayValue*)t0)->value();
				std::vector<Type*> v1 = ((ArrayValue*)t1)->value();

				std::vector<Type*> uniao;
				uniao.insert(v0.end(), v1.begin(), v1.end());

				std::cout << uniao[0] << ' ';
				return new ArrayValue(uniao);

			}

			break;

		case SubOp:
			if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());

				return new IntegerValue(v0 - v1);
			}
			break;
	 	case MulOp:
		 	if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());

				std::cout << v0/v1;

				return new IntegerValue(v0 * v1);
			 }
	 		break;
	 	case DivOp:
		 	if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){

				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());


				return new IntegerValue(v0 / v1);
			 }
	 		break;
	 	case ModOp:
		 	if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());

				return new IntegerValue(v0 % v1);
			 }
	 		break;
	 	case ExpOp:
		 	if(t0->type() == Type::IntegerType && t1->type() == Type::IntegerType){
				int v0 = std::stoi(t0->str());
				int v1 = std::stoi(t1->str());

				return new IntegerValue(v0 * v1);
			 }
	 		break;
	 	default:
	 		break;
	 	}

}
