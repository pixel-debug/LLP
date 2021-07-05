#include "CompositeBoolExpr.h"
#include <iostream>

CompositeBoolExpr::CompositeBoolExpr(int line, BoolExpr* left, enum CompositeBoolExpr::BoolOp op, BoolExpr* right)
					: BoolExpr(line), m_left(left), m_op(op), m_right(right){

					}
CompositeBoolExpr::~CompositeBoolExpr(){
	delete m_left;
	delete m_right;
}

bool CompositeBoolExpr::expr(){
	switch (m_op )
	{
	case And:
		return (m_left->expr() and m_right->expr());
		break;
	case Or:
		return (m_left->expr() or m_right->expr());
		break;

	default:
		return NULL;
		break;
	}

}

