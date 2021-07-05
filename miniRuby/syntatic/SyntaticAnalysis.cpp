#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "SyntaticAnalysis.h"
#include <list>

#include "../interpreter/command/AssignCommand.h"
#include "../interpreter/command/BlocksCommand.h"
#include "../interpreter/command/Command.h"
#include "../interpreter/command/ForCommand.h"
#include "../interpreter/command/IfCommand.h"
#include "../interpreter/command/OutputCommand.h"
#include "../interpreter/command/UnlessCommand.h"
#include "../interpreter/command/UntilCommand.h"
#include "../interpreter/command/WhileCommand.h"

#include "../interpreter/expr/AccessExpr.h"
#include "../interpreter/expr/ArrayExpr.h"
#include "../interpreter/expr/BinaryExpr.h"
#include "../interpreter/expr/BoolExpr.h"
#include "../interpreter/expr/CompositeBoolExpr.h"
#include "../interpreter/expr/ConstExpr.h"
#include "../interpreter/expr/ConvExpr.h"
#include "../interpreter/expr/Expr.h"
#include "../interpreter/expr/FunctionExpr.h"
#include "../interpreter/expr/InputExpr.h"
#include "../interpreter/expr/NotBoolExpr.h"
#include "../interpreter/expr/SingleBoolExpr.h"
#include "../interpreter/expr/Variable.h"

#include "../interpreter/value/ArrayValue.h"
#include "../interpreter/value/IntegerValue.h"
#include "../interpreter/value/StringValue.h"
#include "../interpreter/value/Type.h"

SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex):
	m_lex(lex), m_current(lex.nextToken()){

	}


SyntaticAnalysis::~SyntaticAnalysis(){


}

Command* SyntaticAnalysis::start(){
	Command* cmd = procCode();
    eat(TT_END_OF_FILE);

	return cmd;
}

void SyntaticAnalysis::advance() {
		 m_current = m_lex.nextToken();
}

void SyntaticAnalysis::eat(TokenType type) {
	// std::cout << "Expected (..., " << tt2str(type)
	// 		  << "), found (\"" + m_current.token << "\", "
	// 		  << tt2str(m_current.type) << ")" << std::endl;
    if (type == m_current.type) {
        advance();

    } else {
    	showError();
        }
}

void SyntaticAnalysis::showError() {
    std::cout << std::setw(2) << std::setfill('0') << m_lex.line() << ": ";

    switch (m_current.type) {
        case TT_INVALID_TOKEN:
            std::cout << "Lexema inválido [" << m_current.token << "]" << std::endl;
        	break;

        case TT_UNEXPECTED_EOF:

    	case TT_END_OF_FILE:
            std::cout << "Fim de arquivo inesperado " << std::endl;
        	break;

        default:
            std::cout << "Lexema não esperado [" << m_current.token << "]" << std::endl;
            break;
    }

		exit(1);
}
    // <code>     ::= { <cmd> }
	BlocksCommand* SyntaticAnalysis::procCode() {
		int line = m_lex.line();

		std::list<Command*> cmds;
		std::list<Command*>::iterator it = cmds.begin();

		while (m_current.type == TT_IF ||
				m_current.type == TT_UNLESS ||
				m_current.type == TT_WHILE ||
				m_current.type == TT_UNTIL ||
				m_current.type == TT_FOR ||
				m_current.type == TT_PUTS ||
				m_current.type == TT_PRINT ||
				m_current.type == TT_ID ||
				m_current.type == TT_OPEN_PAR) {
			Command* cmd = procCmd();
			cmds.insert(it, cmd);
		}
			BlocksCommand* bcmd = new BlocksCommand(line, cmds);
			return bcmd;
	}

    // <cmd>      ::= <if> | <unless> | <while> | <until> | <for> | <output> | <assign>
	Command* SyntaticAnalysis::procCmd() {
		Command* cmd = NULL;
        if (m_current.type == TT_IF)
            return procIf();

        else if (m_current.type == TT_UNLESS)
            return procUnless();

        else if (m_current.type == TT_WHILE)
            return procWhile();

        else if (m_current.type == TT_UNTIL)
            return procUntil();

        else if (m_current.type == TT_FOR)
            return procFor();

        else if (m_current.type == TT_PUTS || m_current.type == TT_PRINT)
            return procOutput();
        else if (m_current.type == TT_ID || m_current.type == TT_OPEN_PAR)
            return procAssign();
        else
            showError();
		return cmd;
    }

    // <if>       ::= if <boolexpr> [ then ] <code> { elsif <boolexpr> [ then ] <code> } [ else <code> ] end
    IfCommand* SyntaticAnalysis::procIf() {
        int line = m_lex.line();
		eat(TT_IF);

		BoolExpr* bexr = procBoolExpr();

        if (m_current.type == TT_THEN)
            advance();
		Command* thenCommands = procCode();
        IfCommand* ifcmd = new IfCommand(line, bexr, thenCommands);
		std::vector<IfCommand*> ifvec;
		int aux = 0;
        while(m_current.type == TT_ELSIF)
        {
            advance();
            BoolExpr* bx = procBoolExpr();
            if(m_current.type == TT_THEN)
                advance();
            Command* thencmd = procCode();
			ifvec.push_back(new IfCommand(line, bx, thencmd));
			if(ifvec.size() > 1){
				ifvec[aux - 1]->setElseCommands(ifvec[aux]);
			}
			aux++;
        }
		Command* elsecmd = NULL;
        if(m_current.type == TT_ELSE)
        {
            advance();
            elsecmd = procCode();
        }
		if(!(ifvec.empty())){
			ifvec.back()->setElseCommands(elsecmd);
			ifcmd->setElseCommands(ifvec.front());
		}else
			ifcmd->setElseCommands(elsecmd);

        eat(TT_END);
		return ifcmd;
    }

    // <unless>   ::= unless <boolexpr> [ then ] <code> [ else <code> ] end
    UnlessCommand* SyntaticAnalysis::procUnless() {
		int line = m_lex.line();
        eat(TT_UNLESS);
        BoolExpr* bx = procBoolExpr();

        if (m_current.type == TT_THEN)
            advance();

        Command* thencmd = procCode();
		Command* elsecmd = NULL;
        if(m_current.type == TT_ELSE)
        {
            advance();
            elsecmd = procCode();
        }

        eat(TT_END);
		return  new UnlessCommand(line, bx, thencmd, elsecmd);
    }

    // <while>    ::= while <boolexpr> [ do ] <code> end
    WhileCommand* SyntaticAnalysis::procWhile() {
        int line = m_lex.line();
		eat(TT_WHILE);
        BoolExpr* bx = procBoolExpr();

        if (m_current.type == TT_DO)
            advance();

        Command* cmd = procCode();
        eat(TT_END);
		return new WhileCommand(line, bx, cmd);
    }


// <until>    ::= until <boolexpr> [ do ] <code> end
    UntilCommand* SyntaticAnalysis::procUntil() {
        int line = m_lex.line();
		eat(TT_UNTIL);
        BoolExpr* bx = procBoolExpr();

        if (m_current.type == TT_DO)
            advance();

        Command* cmd = procCode();
        eat(TT_END);
		return new UntilCommand(line, bx, cmd);
    }

    // <for>      ::= for <id> in <expr> [ do ] <code> end
    ForCommand* SyntaticAnalysis::procFor() {
		int line = m_lex.line();
        eat(TT_FOR);
        Variable* var = procId();
        eat(TT_IN);
        Expr* ex = procExpr();

        if (m_current.type == TT_DO)
            advance();

        Command* cmd = procCode();
        eat(TT_END);
		return new ForCommand(line, var, ex, cmd);
    }

    // <output>   ::= ( puts | print ) [ <expr> ] [ <post> ] ';'
    Command* SyntaticAnalysis::procOutput() {
        enum OutputCommand::OutputOp op;
		if (m_current.type == TT_PUTS){
            op = OutputCommand::PutsOp;
			advance();
		}
        else if (m_current.type == TT_PRINT){
			op = OutputCommand::PrintOp;
            advance();
		}
        else{
            showError();
		}

		int line = m_lex.line();

		Expr* expr = NULL;

        if (m_current.type == TT_ADD ||
                m_current.type == TT_SUB ||
                m_current.type == TT_INTEGER ||
                m_current.type == TT_STRING ||
                m_current.type == TT_OPEN_BRA ||
                m_current.type == TT_GETS ||
                m_current.type == TT_RAND ||
                m_current.type == TT_ID ||
                m_current.type == TT_OPEN_PAR) {
            expr = procExpr();
        }
		Command* cmd = NULL;
		OutputCommand* ocmd = new OutputCommand(line, op, expr);
        if (m_current.type == TT_IF || m_current.type == TT_UNLESS) {
            cmd = procPost(ocmd);
        }
		else{
			cmd = ocmd;
		}

        eat(TT_SEMICOLON);


		return cmd;
    }

    // <assign>   ::= <access> { ',' <access> } '=' <expr> { ',' <expr> } [ <post> ] ';'
    Command* SyntaticAnalysis::procAssign() {
        int line = m_lex.line();

		std::list<Expr*> left;
		std::list<Expr*> right;

		left.push_back(procAccess());

        while (m_current.type == TT_COMMA) {
            advance();
            left.push_back(procAccess());
        }

        eat(TT_ASSIGN);
		right.push_back(procExpr());


        while (m_current.type == TT_COMMA) {
            advance();
            right.push_back(procExpr());
        }
		Command* cmd = NULL;
		AssignCommand* ascmd = new AssignCommand(line, left, right);

	    if (m_current.type == TT_IF || m_current.type == TT_UNLESS) {
            cmd = procPost(ascmd);
        }else{
			cmd = ascmd;
		}

        eat(TT_SEMICOLON);
		return cmd;
    }

    // <post>     ::= ( if | unless ) <boolexpr>
    Command* SyntaticAnalysis::procPost(Command* cmd) {
		int line = m_lex.line();
		int aux = 0;
        if (m_current.type == TT_IF){
			advance();
			aux = 1;
		}

        else if (m_current.type == TT_UNLESS){
			advance();
			aux = 2;
		}

        else
            showError();

        BoolExpr* bx = procBoolExpr();
		Command* cmds = NULL;
		switch (aux)
		{
		case 1:
			cmds = new IfCommand(line, bx, cmd);
			break;
		case 2:
			cmds = new UnlessCommand(line, bx, cmd);
			break;
		default:
			break;
		}
		return cmds;
    }

    // <boolexpr> ::= [ not ] <cmpexpr> [ (and | or) <boolexpr> ]
    BoolExpr* SyntaticAnalysis::procBoolExpr() {
        int line = m_lex.line();
		bool notBoolExpr = false;

		if (m_current.type == TT_NOT){
			notBoolExpr = true;
            advance();
		}

        BoolExpr* left = procCmpExpr();
        if(m_current.type == TT_AND || m_current.type == TT_OR)
        {
			enum CompositeBoolExpr::BoolOp bp;

            switch(m_current.type){
				case TT_AND:
					bp = CompositeBoolExpr::And;
					advance();
					break;

				case TT_OR:
					bp = CompositeBoolExpr::Or;
					advance();
					break;

				default:
                	showError();
					break;
			}
            BoolExpr* right = procBoolExpr();
			left = new CompositeBoolExpr(line, left, bp, right);
        }
		if(notBoolExpr){
        	return new NotBoolExpr(line, left);
    	}
		else{
			return left;
		}
    }

    // <cmpexpr>  ::= <expr> ( '==' | '!=' | '<' | '<=' | '>' | '>=' | '===' ) <expr>
    SingleBoolExpr* SyntaticAnalysis::procCmpExpr() {
		int line = m_lex.line();
        Expr* left = procExpr();

		enum SingleBoolExpr::RelOp rp;
        switch(m_current.type){
			case TT_EQUAL:
				rp = SingleBoolExpr::EqualsOp;
				advance();
				break;
			case TT_NOT_EQUAL:
				rp = SingleBoolExpr::NotEqualsOp;
				advance();
				break;
			case TT_LOWER:
				rp = SingleBoolExpr::LowerThanOp;
				advance();
				break;
			case TT_LOWER_EQUAL:
				rp = SingleBoolExpr::LowerEqualOp;
				advance();
				break;
			case TT_GREATER:
				rp = SingleBoolExpr::GreaterThanOp;
				advance();
				break;
			case TT_GREATER_EQUAL:
				rp = SingleBoolExpr::GreaterEqualOp;
				advance();
				break;
			case TT_CONTAINS:
				rp = SingleBoolExpr::ContainsOp;
	            advance();
				break;
			default:
			    showError();
				break;
		}
        Expr* right = procExpr();
		return new SingleBoolExpr(line, left, rp, right);
    }

    // <expr>     ::= <arith> [ ( '..' | '...' ) <arith> ]
    Expr* SyntaticAnalysis::procExpr() {
		int line = m_lex.line();
        Expr* left = procArith();
		enum BinaryExpr::BinaryOp bp;
        if(m_current.type == TT_INCLUSIVE_RANGE || m_current.type == TT_EXCLUSIVE_RANGE)
        {
            switch(m_current.type){
				case TT_INCLUSIVE_RANGE:
					bp = BinaryExpr::RangeWithOp;
					advance();
					break;
				case TT_EXCLUSIVE_RANGE:
					bp = BinaryExpr::RangeWithoutOp;
					advance();
					break;
				default:
					showError();
					break;
			}
            Expr* right = procArith();
			left = new BinaryExpr(line, left, bp, right);
        }
		return left;
    }

    // <arith>    ::= <term> { ('+' | '-') <term> }
    Expr* SyntaticAnalysis::procArith() {
		int line = m_lex.line();
        Expr* left = procTerm();
		enum BinaryExpr::BinaryOp bp;
		while (m_current.type == TT_ADD || m_current.type == TT_SUB) {
			switch(m_current.type){
				case TT_ADD:
					bp = BinaryExpr::AddOp;
					advance();
					break;
				case TT_SUB:
					bp = BinaryExpr::SubOp;
					advance();
					break;
				default:
					showError();
					break;
			}
            Expr* right = procTerm();
			left = new BinaryExpr(line, left, bp, right);
        }
		return left;
    }

    // <term>     ::= <power> { ('*' | '/' | '%') <power> }
    Expr* SyntaticAnalysis::procTerm() {
        int line = m_lex.line();
		Expr* left = procPower();
		enum BinaryExpr::BinaryOp bp;
        while (m_current.type == TT_MUL || m_current.type == TT_DIV || m_current.type == TT_MOD) {
            switch(m_current.type){
				case TT_MUL:
					bp = BinaryExpr::MulOp;
					advance();
					break;
				case TT_DIV:
					bp = BinaryExpr::DivOp;
					advance();
					break;
				case TT_MOD:
					bp = BinaryExpr::ModOp;
					advance();
					break;
				default:
					showError();
					break;
			}
			advance();
            Expr* right = procPower();
			left = new BinaryExpr(line, left, bp, right);
        }
		return left;
    }

    // <power>    ::= <factor> { '**' <factor> }
    Expr* SyntaticAnalysis::procPower() {
        int line = m_lex.line();
		Expr* left = procFactor();
		enum BinaryExpr::BinaryOp bp;
        while (m_current.type == TT_EXP) {
            bp = BinaryExpr::ExpOp;

			advance();
            Expr* right = procFactor();
			left = new BinaryExpr(line, left, bp, right);
        }
		return left;
    }

    // <factor>   ::= [ '+' | '-' ] ( <const> | <input> | <access> ) [ <function> ]
    Expr* SyntaticAnalysis::procFactor() {
		//int line = m_lex.line();
		Expr* expr = NULL;
		enum ConvExpr::ConvOp cp;
		if (m_current.type == TT_ADD ){
			cp = ConvExpr::PlusOp;
			advance();
		}
		if(m_current.type == TT_SUB){
			cp = ConvExpr::MinusOp;
			advance();
		}

		int line = m_lex.line();



        if(m_current.type == TT_INTEGER || m_current.type == TT_STRING || m_current.type == TT_OPEN_BRA){
            expr = procConst();
		}
        else if(m_current.type == TT_GETS || m_current.type == TT_RAND)
            expr = procInput();
        else if(m_current.type == TT_ID || m_current.type == TT_OPEN_PAR)
            expr = procAccess();
        else
            showError();

        if(m_current.type == TT_DOT){
            expr = procFunction(expr);
		}
		if(cp != NULL)
			expr = new ConvExpr(line, cp, expr);

		return expr;
    }

    // <const>    ::= <integer> | <string> | <array>
    Expr* SyntaticAnalysis::procConst() {
		Expr* expr = NULL;
		if(m_current.type == TT_INTEGER){
            expr = procInteger();
		}
        else if(m_current.type == TT_STRING){
            expr = procString();
		}
        else{
            expr = procArray();
		}
		return expr;
    }

    // <input>    ::= gets | rand
    InputExpr* SyntaticAnalysis::procInput() {
		int line = m_lex.line();
		enum InputExpr::InputOp ip;
        if(m_current.type == TT_GETS){
			eat(TT_GETS);
			ip = InputExpr::GetsOp;
		}
        else if(m_current.type == TT_RAND){
			eat(TT_RAND);
			ip = InputExpr::RandOp;
		}else{
			showError();
		}
		return new InputExpr(line, ip);

    }

    // <array>    ::= '[' [ <expr> { ',' <expr> } ] ']'
    ArrayExpr* SyntaticAnalysis::procArray() {
		int line = m_lex.line();
        eat(TT_OPEN_BRA);
		std::list<Expr*> exprs;

        if (m_current.type == TT_ADD ||
            m_current.type == TT_SUB ||
            m_current.type == TT_INTEGER ||
            m_current.type == TT_STRING ||
            m_current.type == TT_OPEN_BRA ||
            m_current.type == TT_GETS ||
            m_current.type == TT_RAND ||
            m_current.type == TT_ID ||
            m_current.type == TT_OPEN_PAR)
        {
            exprs.push_back(procExpr());

            while (m_current.type == TT_COMMA)
            {
                advance();
                exprs.push_back(procExpr());
            }
        }
        eat(TT_CLOSE_BRA);
		return new ArrayExpr(line, exprs);
    }


    // <access>   ::= ( <id> | '(' <expr> ')' ) [ '[' <expr> ']' ]
    Expr* SyntaticAnalysis::procAccess() {
        int line = m_lex.line();

		Expr* base = NULL;

		if(m_current.type == TT_ID)
            base = procId();
        else if(m_current.type == TT_OPEN_PAR)
        {
            eat(TT_OPEN_PAR);
            if (m_current.type == TT_ADD ||
                m_current.type == TT_SUB ||
                m_current.type == TT_INTEGER ||
                m_current.type == TT_STRING ||
                m_current.type == TT_OPEN_BRA ||
                m_current.type == TT_GETS ||
                m_current.type == TT_RAND ||
                m_current.type == TT_ID ||
                m_current.type == TT_OPEN_PAR)
            base = procExpr();
            else
                showError();
            eat(TT_CLOSE_PAR);
        }
        else
            showError();

		Expr* index = NULL;

        if(m_current.type==TT_OPEN_BRA)
        {
            eat(TT_OPEN_BRA);
            if (m_current.type == TT_ADD ||
                m_current.type == TT_SUB ||
                m_current.type == TT_INTEGER ||
                m_current.type == TT_STRING ||
                m_current.type == TT_OPEN_BRA ||
                m_current.type == TT_GETS ||
                m_current.type == TT_RAND ||
                m_current.type == TT_ID ||
                m_current.type == TT_OPEN_PAR)
            index = procExpr();
            eat(TT_CLOSE_BRA);
        }
		AccessExpr* ac = new AccessExpr(line, base, index);
		Expr* expr = ac;
		return expr;
    }

// <function> ::= '.' ( length | to_i | to_s )
    FunctionExpr* SyntaticAnalysis::procFunction(Expr* expr) {
		int line = m_lex.line();
        eat(TT_DOT);
		enum FunctionExpr::FunctionOp fp;

        if(m_current.type == TT_LENGHT || m_current.type == TT_TO_INT || m_current.type == TT_TO_STR)
           switch(m_current.type){
			    case TT_LENGHT:
					fp = FunctionExpr::LenghtOp;
					advance();
					break;
			    case TT_TO_INT:
					fp = FunctionExpr::ToIntOp;
					advance();
					break;
			   	case TT_TO_STR:
				    fp = FunctionExpr::ToStringOp;
		   			advance();
					break;
				default:
            		showError();
					break;
		   }
		   return new FunctionExpr(line, expr, fp);
    }

    ConstExpr* SyntaticAnalysis::procInteger() {
		std::string tmp = m_current.token;

        eat(TT_INTEGER);
		int line = m_lex.line();
		int value = atoi(tmp.c_str());

		IntegerValue* iv = new IntegerValue(value);

		return new ConstExpr(line, iv);
    }

    ConstExpr* SyntaticAnalysis::procString() {
		std::string tmp = m_current.token;
	//	tmp = tmp.substr(1, tmp.length()-2); // aspas simples
        eat(TT_STRING);
        int line = m_lex.line();
		StringValue* sv = new StringValue(tmp);

		return new ConstExpr(line, sv);
    }

    Variable* SyntaticAnalysis::procId() {
		std::string tmp = m_current.token;
        eat(TT_ID);
		int line = m_lex.line();
		return new Variable(line, tmp);
    }
