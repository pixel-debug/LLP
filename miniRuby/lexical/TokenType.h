#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>

enum TokenType{
	// Specials
	TT_UNEXPECTED_EOF		= -2,
	TT_INVALID_TOKEN		= -1,
	TT_END_OF_FILE			=  0,

	// Symbols
	TT_SEMICOLON,     		// ;
	TT_DOT,        			// .
	TT_COMMA,        		// ,
	TT_COLON,        		// :
	TT_OPEN_PAR,        	// (
	TT_CLOSE_PAR,        	// )
	TT_OPEN_BRA,        	// [
	TT_CLOSE_BRA,        	// ]

	// Logic operators
	TT_ASSIGN,        		// =
	TT_EQUAL,         		// ==
	TT_NOT_EQUAL,     		// !=
	TT_LOWER,         		// <
	TT_LOWER_EQUAL,   		// <=
	TT_GREATER,       		// >
	TT_GREATER_EQUAL, 		// >=
	TT_CONTAINS,	   		// ===
	TT_NOT, 		   		// not

	// Conector operators
	TT_OR, 		   			// or
	TT_AND, 		   		// and

	// Arithmetic operators
	TT_ADD,          		// +
	TT_SUB,           		// -
	TT_MUL,           		// *
	TT_DIV,           		// /
	TT_MOD,           		// %
	TT_EXP, 		   		// **

	// Commands Keywords
	TT_PUTS,       			// puts
	TT_IF,            		// if
	TT_FOR,            		// for
	TT_PRINT, 				// print
	TT_WHILE,         		// while
	TT_UNLESS, 				// unless
	TT_UNTIL, 				// until
	TT_THEN, 				// then
	TT_ELSIF, 				// elsif
	TT_ELSE, 				// else
	TT_END, 				// end
	TT_DO, 					// do
	TT_IN, 					// in
	TT_INCLUSIVE_RANGE,		// ..
	TT_EXCLUSIVE_RANGE, 	// ...

	// Functions Keywords
	TT_GETS,				// gets
	TT_RAND,				// rand
	TT_LENGHT,				// .lenght
	TT_TO_INT,				// .to_i
	TT_TO_STR,				// .to_s

	// Others
	TT_ID,           		// identifier
    TT_INTEGER,       		// integer
    TT_STRING,        		// string
};

inline std::string tt2str(enum TokenType type){
	switch (type)
	{
	// Specials
	case TT_UNEXPECTED_EOF:
		return "UNEXPECTED_EOF";
	case TT_INVALID_TOKEN:
		return "INVALID_TOKEN";
	case TT_END_OF_FILE	:
		return "END_OF_FILE";

	// Symbols
	case TT_SEMICOLON:
		return "SEMICOLON:";
	case TT_DOT:
		return "DOT";
	case TT_COMMA:
		return "COMMA";
	case TT_COLON:
		return "COLON";
	case TT_OPEN_PAR:
		return "OPEN_PAR";
	case TT_CLOSE_PAR:
		return "CLOSE_PAR";
	case TT_OPEN_BRA:
		return "OPEN_BRA";
	case TT_CLOSE_BRA:
		return "CLOSE_BRA";

	// Logic operators
	case TT_ASSIGN:
		return "ASSIGN";
	case TT_EQUAL:
		return "EQUAL";
	case TT_NOT_EQUAL:
		return "NOT_EQUAL";
	case TT_LOWER:
		return "LOWER";
	case TT_LOWER_EQUAL:
		return "LOWER_EQUAL";
	case TT_GREATER:
		return "GREATER";
	case TT_GREATER_EQUAL:
		return "GREATER_EQUAL";
	case TT_CONTAINS:
		return "CONTAINS";
	case TT_NOT:
		return "NOT";

	// Conector operators
	case TT_OR:
		return "OR";
	case TT_AND:
		return "AND";

	// Arithmetic operators
	case TT_ADD:
		return "ADD";
	case TT_SUB:
		return "SUB";
	case TT_MUL:
		return "MUL";
	case TT_DIV:
		return "DIV";
	case TT_MOD:
		return "MOD";
	case TT_EXP:
		return "EXP";

	// Commands Keywords
	case TT_PUTS:
		return "PUTS";
	case TT_IF:
		return "IF";
	case TT_FOR:
		return "FOR";
	case TT_PRINT:
		return "PRINT";
	case TT_WHILE:
		return "WHILE";
	case TT_UNLESS:
		return "UNLESS";
	case TT_UNTIL:
		return "UNTIL";
	case TT_THEN:
		return "THEN";
	case TT_ELSIF:
		return "ELSIF";
	case TT_ELSE:
		return "ELSE";
	case TT_END:
		return "END";
	case TT_DO:
		return "DO";
	case TT_IN:
		return "IN";
	case TT_INCLUSIVE_RANGE:
		return "INCLUSIVE_RANGE";
	case TT_EXCLUSIVE_RANGE:
		return "EXCLUSIVE_RANGE";

	// Functions Keywords
	case TT_GETS:
		return "GETS";
	case TT_RAND:
		return "RAND";
	case TT_LENGHT:
		return "LENGHT";
	case TT_TO_INT:
		return "TO_INT";
	case TT_TO_STR:
		return "TO_STR";

	// Others
	case TT_ID:
		return "ID";
    case TT_INTEGER:
		return "INTEGER";
    case TT_STRING:
		return "STRING";

	default:
		throw std::string("invalid token type");
	}
}
#endif
