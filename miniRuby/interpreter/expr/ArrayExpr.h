#ifndef ARRAY_EXPR_H
#define ARRAY_EXPR_H

#include<list>
#include "Expr.h"
#include "../value/Value.h"



class ArrayExpr: public Expr{
			public:
					ArrayExpr(int line, std::list<Expr*> exprs);
					virtual ~ArrayExpr();

					virtual Type* expr();

			private:
				std::list<Expr*> m_exprs;
};


#endif
