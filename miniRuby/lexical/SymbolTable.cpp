
#include "SymbolTable.h"

SymbolTable::SymbolTable() {
	// Symbols
	m_symbols[";"] = TT_SEMICOLON;
	m_symbols["."] = TT_DOT;
	m_symbols[","] = TT_COMMA;
	m_symbols[":"] = TT_COLON;
	m_symbols["("] = TT_OPEN_PAR;
	m_symbols[")"] = TT_CLOSE_PAR;
	m_symbols["["] = TT_OPEN_BRA;
	m_symbols["]"] = TT_CLOSE_BRA;

	// Logic operators
	m_symbols["="] = TT_ASSIGN;
	m_symbols["=="] = TT_EQUAL;
	m_symbols["!="] = TT_NOT_EQUAL;
	m_symbols["<"] = TT_LOWER;
	m_symbols["<="] = TT_LOWER_EQUAL;
	m_symbols[">"] = TT_GREATER;
	m_symbols[">="] = TT_GREATER_EQUAL;
	m_symbols["==="] = TT_CONTAINS;
	m_symbols["not"] = TT_NOT;

	// Conector operators
	m_symbols["or"] = TT_OR;
	m_symbols["and"] = TT_AND;

	// Arithmetic operators
	m_symbols["+"] = TT_ADD;
	m_symbols["-"] = TT_SUB;
	m_symbols["*"] = TT_MUL;
	m_symbols["/"] = TT_DIV;
	m_symbols["%"] = TT_MOD;
	m_symbols["**"] = TT_EXP;

	// Commands Keywords
	m_symbols["puts"] = TT_PUTS;
	m_symbols["if"] = TT_IF;
	m_symbols["for"] = TT_FOR;
	m_symbols["print"] = TT_PRINT;
	m_symbols["while"] = TT_WHILE;
	m_symbols["unless"] = TT_UNLESS;
	m_symbols["until"] = TT_UNTIL;
	m_symbols["then"] = TT_THEN;
	m_symbols["elsif"] = TT_ELSIF;
	m_symbols["else"] = TT_ELSE;
	m_symbols["end"] = TT_END;
	m_symbols["do"] = TT_DO;
	m_symbols["in"] = TT_IN;
	m_symbols[".."] = TT_INCLUSIVE_RANGE;
	m_symbols["..."] = TT_EXCLUSIVE_RANGE;

	// Functions Keywords
	m_symbols["gets"] = TT_GETS;
	m_symbols["rand"] = TT_RAND;
	m_symbols["length"] = TT_LENGHT;
	m_symbols["to_i"] = TT_TO_INT;
	m_symbols["to_s"] = TT_TO_STR;
}

SymbolTable::~SymbolTable(){

}

bool SymbolTable::contains(const std::string& token) const{
	return m_symbols.find(token) != m_symbols.end();

}

enum TokenType SymbolTable::find(const std::string& token) {
	return this->contains(token) ? m_symbols[token] : TT_ID;
}
