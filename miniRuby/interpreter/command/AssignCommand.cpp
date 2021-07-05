#include "AssignCommand.h"
#include "../util/Utils.h"

#include <list>
#include "../expr/SetExpr.h"
#include <iostream>
AssignCommand::AssignCommand(int line, std::list<Expr*> left, std::list<Expr*> right)
				: Command(line), m_left(left), m_right(right){


				}
AssignCommand::~AssignCommand(){
	for (std::list<Expr*>::iterator it = m_left.begin(),
	     ed = m_left.end(); it != ed; it++) {
		Expr* cmd = *it;
		delete cmd;
	}
	for (std::list<Expr*>::iterator it = m_right.begin(),
	     ed = m_right.end(); it != ed; it++) {
		Expr* cmd = *it;
		delete cmd;
	}
}
void AssignCommand::execute(){
	if(m_left.size() != m_right.size()){
		Utils::abort(AssignCommand::getLine());
	}
	else{
		std::list<Type*> temp;
		std::list<int>::iterator it;
		for(int i = 0; i < m_right.size(); i++){
			temp.push_back((m_right.front()+i)->expr());
		}

		for(int i = 0; i < m_left.size(); i++){
			if(!(dynamic_cast<SetExpr*>(m_left.front() + i)->expr())){
				Utils::abort(AssignCommand::getLine());
			}else{
				SetExpr* set = (SetExpr*)((m_left.front()+i)->expr());

				set->setValue((temp.front()+i));
			}


		}

	}
}
