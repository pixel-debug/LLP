#include "AssignCommand.h"
#include "../util/Utils.h"

#include <list>
#include "../expr/SetExpr.h"
#include <iostream>
AssignCommand::AssignCommand(int line, std::vector<Expr*> left, std::vector<Expr*> right)
				: Command(line), m_left(left), m_right(right){


				}
AssignCommand::~AssignCommand(){


}
void AssignCommand::execute(){

	if(m_left.size() != m_right.size()){
		Utils::abort(AssignCommand::getLine());
	}

	else{
	 	std::vector<Type*> temp;

		int tamRight = m_right.size();


		for(int i = 0; i < tamRight; i++){
			Type* t = m_right[i]->expr();
	    	temp.push_back(t);

		}

		int tamLeft = m_left.size();
		for(int i = 0; i < tamLeft; i++){
	 		SetExpr* sexpr = dynamic_cast<SetExpr*>(m_left[i]);


			if (sexpr == nullptr) {
				Utils::abort(AssignCommand::getLine());
	 		}
			sexpr->setValue(temp[i]);
		}
	}
}
