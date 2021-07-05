#ifndef SYNTATIC_ANALYSIS_H
#define SYNTATIC_ANALYSIS_H

#include "../lexical/LexicalAnalysis.h"

class IntegerValue;
class StringValue;
class ArayValue;
class Type;

class AccessExpr;
class ArrayExpr;
class BinaryExpr;
class BoolExpr;
class CompositeBoolExpr;
class ConstExpr;
class ConvExpr;
class Expr;
class FunctionExpr;
class InputExpr;
class NotBoolExpr;
class SetExpr;
class SingleBoolExpr;
class Variable;


class Command;
class AssignCommand;
class BlocksCommand;
class ForCommand;
class IfCommand;
class OutputCommand;
class UnlessCommand;
class UntilCommand;
class WhileCommand;

class SyntaticAnalysis{
	public:
		SyntaticAnalysis(LexicalAnalysis& lex);
		virtual ~SyntaticAnalysis();

		Command* start();

	private:
		LexicalAnalysis& m_lex;
		Lexeme m_current;

		void advance();
		void eat(enum TokenType type);
		void showError();

		BlocksCommand* procCode();
		Command* procCmd();
		IfCommand* procIf();
		//void procUnles();
		UnlessCommand* procUnless();
		WhileCommand* procWhile();
		UntilCommand* procUntil();
		ForCommand* procFor();
		Command* procOutput();
		Command* procAssign();
		Command* procPost(Command* cmd);
		BoolExpr* procBoolExpr();
		SingleBoolExpr* procCmpExpr();
		Expr* procExpr();
		Expr* procArith();
		Expr* procTerm();
		Expr* procPower();
		Expr* procFactor();
		Expr* procConst();
		InputExpr* procInput();
		ArrayExpr* procArray();
		Expr* procAccess();
		FunctionExpr* procFunction(Expr* expr);
		ConstExpr* procInteger();
		ConstExpr* procString();
		Variable* procId();


};

#endif
