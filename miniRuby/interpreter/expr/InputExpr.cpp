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
	Type* v = NULL;

	switch (m_op )
	{
	case GetsOp:
		if(v->type() == Type::IntegerType){
			int user;
			std::cin >> user;
			// trim ?
			// nextLine ?
			IntegerValue* iv = new IntegerValue(user);
			v = iv;
		}
		else if(v->type() == Type::StringType){
			std::string user;
			//std::cin >> user;

			getline(std::cin, user);
			user.erase(user.find_last_not_of( " \f\n\r\t\v" ) + 1 ).erase( 0, user.erase( user.find_last_not_of( " \f\n\r\t\v" ) + 1 ).find_first_not_of( " \f\n\r\t\v" ));
			StringValue* sv = new StringValue(user);
			v = sv;
		}


		break;
	case RandOp:
		srand(time(NULL));
		int random = rand();

		IntegerValue* iv = new IntegerValue(random);
		v = iv;
		break;

	// default:
	// 	break;
	}
	return v;
}

