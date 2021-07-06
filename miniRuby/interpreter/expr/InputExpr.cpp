#include "InputExpr.h"
#include "../value/IntegerValue.h"
#include "../value/StringValue.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>


InputExpr::InputExpr(int line,  enum InputExpr::InputOp op)
			: Expr(line), m_op(op){

}
 InputExpr::~InputExpr(){

}

Type* InputExpr::expr(){

	if(m_op == InputExpr::GetsOp){
		std::string user;

		//std::cin >> user;

		getline(std::cin, user);
		//user.erase(user.find_last_not_of( " \f\n\r\t\v" ) + 1 ).erase( 0, user.erase( user.find_last_not_of( " \f\n\r\t\v" ) + 1 ).find_first_not_of( " \f\n\r\t\v" ));
		//user.erase( 0, user.find_first_not_of(  " \f\n\r\t\v" ) );
		return new StringValue(user);

	}

	if(m_op == InputExpr::RandOp){
		srand(time(NULL));
		int random = rand();

		return new IntegerValue(random);
	}

}

