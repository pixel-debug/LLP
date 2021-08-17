
# Mini Ruby

## Trabalho prático da disciplina Linguagens de Programação.

O	 objetivo	 é	 desenvolver	 um	 interpretador	 para	 um subconjunto	 de	 uma	 linguagem	 de	 programação conhecida.	 Para	 isso	 foi	 criada	 miniRuby, uma	 linguagem	 de	 programação	 de	 brinquedo	 baseada	 em	 Ruby.	Ela	possui	suporte	a	tipos dinâmicos	inteiros,	strings	e	arranjos	indexados.

## Gramática.
```
<code> ::= { <cmd> }
<cmd> ::= <if> | <unless> | <while> | <until> | <for> | <output> | <assign>
<if> ::= if <boolexpr> [ then ] <code> { elsif <boolexpr> [ then ] <code> } [ else <code> ] end
<unless> ::= unless <boolexpr> [ then ] <code> [ else <code> ] end

<while> ::= while <boolexpr> [ do ] <code> end
<until> ::= until <boolexpr> [ do ] <code> end
<for> ::= for <id> in <expr> [ do ] <code> end
<output> ::= ( puts | print ) [ <expr> ] [ <post> ] ';'
<assign> ::= <access> { ',' <access> } '=' <expr> { ',' <expr> } [ <post> ] ';'
<post> ::= ( if | unless ) <boolexpr>

<boolexpr> ::= [ not ] <cmpexpr> [ (and | or) <boolexpr> ]
<cmpexpr> ::= <expr> ( '==' | '!=' | '<' | '<=' | '>' | '>=' | '===' ) <expr>
<expr> ::= <arith> [ ( '..' | '...' ) <arith> ]
<arith> ::= <term> { ('+' | '-') <term> }
<term> ::= <power> { ('*' | '/' | '%') <power> }
<power> ::= <factor> { '**' <factor> }
<factor> ::= [ '+' | '-' ] ( <const> | <input> | <access> ) [ <function> ]
<const> ::= <integer> | <string> | <array>
<input> ::= gets | rand
<array> ::= '[' [ <expr> { ',' <expr> } ] ']'
<access> ::= ( <id> | '(' <expr> ')' ) [ '[' <expr> ']' ]
<function> ::= '.' ( length | to_i | to_s )
```
	
## Para rodar o prejeto:
    Entre na pasta com o comando cd/miniRuby
    make
    ./rubi exemplos/[name file].mrb
