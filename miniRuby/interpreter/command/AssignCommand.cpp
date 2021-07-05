#include "AssignCommand.h"
#include "../util/Utils.h"

#include <list>
#include "../expr/SetExpr.h"
#include <iostream>
AssignCommand::AssignCommand(int line, std::list<Expr*> left, std::list<Expr*> right)
				: Command(line), m_left(left), m_right(right){


				}
AssignCommand::~AssignCommand(){


}
void AssignCommand::execute(){
	if(m_left.size() != m_right.size()){
		Utils::abort(AssignCommand::getLine());
	}

	else{
		std::list<Type*> temp;

		int tamRight = m_right.size();
	//	std::cout << tamRight;

		for(int i = 0; i < tamRight; i++){
			temp.push_back((m_right.front()+i)->expr());
		}

		int tamLeft = m_left.size();
		for(int i = 0; i < tamLeft; i++){
			if(!(dynamic_cast<SetExpr*>(m_left.front() + i)->expr())){
				Utils::abort(AssignCommand::getLine());
	 		}
			 else{
				SetExpr* set = (SetExpr*)((m_left.front()+i)->expr());
				set->setValue((temp.front()+i));
			}
		}

	}
}
