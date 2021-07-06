#ifndef ACCESS_EXPR_H
#define ACCESS_EXPR_H


#include "SetExpr.h"



class AccessExpr: public SetExpr{
		private:
			 Expr* m_base;
			 Expr* m_index;

		public:
			AccessExpr(int line, Expr* base, Expr* index);
			virtual ~AccessExpr();
			virtual Type* expr();
			void setValue(Type* value);
};



#endif
