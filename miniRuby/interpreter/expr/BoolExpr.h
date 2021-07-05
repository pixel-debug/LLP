#ifndef BOOL_EXPR_H
#define BOOL_EXPR_H



class BoolExpr {
	public:
		virtual ~BoolExpr(){}
		int getLine() const{return m_line;}

		virtual bool expr() = 0;

		BoolExpr(int line)	:	m_line(line){}

	private:
		int m_line;



};
#endif
