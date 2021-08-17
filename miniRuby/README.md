
# Mini Ruby

## Trabalho prático da disciplina Linguagens de Programação.

O	 objetivo	 é	 desenvolver	 um	 interpretador	 para	 um subconjunto	 de	 uma	 linguagem	 de	 programação conhecida.	 Para	 isso	 foi	 criada	 miniRuby, uma	 linguagem	 de	 programação	 de	 brinquedo	 baseada	 em	 Ruby.	Ela	possui	suporte	a	tipos dinâmicos	inteiros,	strings	e	arranjos	indexados.

## Características gerais
> A	linguagem	possui	escopo	global	para	as	variáveis.	A	linguagem	suporta	três tipos	 primitivos:	 inteiros (números	 inteiros	 de	 32 bits),	 strings (sequência	 de	caracteres	entre	aspas	simples) e	arranjos (elementos	separados	por	vírgula	entre colchetes	 ou	 sequências	 usando	 os	 operadores	 .. ou	 ...).	 Caso	 uma	 variável	 seja	usada	sem	ter	seu	valor	atribuído	previamente,	deve-se	considerar	o	valor	padrão	de	 string	 vazia (''). A	 linguagem	 não	 possui	 conversões	 implícitas,	 os	 valores	precisão	ser	convertidos	explicitamente	pelos	programadores	através	das	funções	.to_i (converte	 strings	 para	inteiro)	 ou	.to_s (converte	inteiros	 ou	arranjos	 para	strings).	 Ou seja,	 operações	 aritméticas	 só	 funcionam	 com	 inteiros,	 enquanto	concatenações (operador	 +)	 apenas	 entre	 strings	 ou	 apenas	 entre	 arranjos.	Operadores	 relacionais	 funcionam	 apenas	 com	 inteiros,	 exceto	 igualdade	(operador	==)	e diferença	(operador	!=)	que	funcionam	com	strings.	Arranjos	são	indexados	a	partir	do	índice	0	(zero)	e	podem	ser	acessados	via	colchetes	(ex.:	x[2]).	É  possível	 verificar	 se	 um	 elemento	 pertence	 a	 um	 arranjo (operador	 ===).	 A	linguagem	 possui	 comentários	 de	 uma	 linha	 onde	 são ignorados	 qualquer	sequência	 de	 caracteres	 após	 o	 símbolo #	 (hashtag).	 </br>
> A	 linguagem	 possui	 as	seguintes	características:
1) Comandos:
a. if:	executar	comandos	se	a expressão for	verdadeira.	
b. unless: executar	comandos	se	a expressão for	falsa.
c. while:	repetir	comandos	enquanto	a	expressão	for verdadeira.
d. until:	repetir	comandos	enquanto	a	expressão	for falsa.
e. for: repetir	comandos	para	uma	sequência	de	valores.
f. print/puts: imprimir	na	tela. Terminam	com	ponto	vírgula	(;).
g. atribuição:	 atribuir	 os	 valores	 das	 expressões	 do	 lado	 direito	 às	
expressões	 do	 lado	 esquerdo. As	 quantidades	 de	 ambos	 os	 lados	
devem	 bater	 e	 terminam	 com	 ponto	 vírgula	 (;).
				Ex.:	min,	max	=	max,	min; (trocam-se	seus	valores).
2) Constantes:
a. Inteiro:	número	formado	por	dígitos.
b. String:	uma	sequência	de	caracteres	entre	aspas	simples.
c. Arranjos: elementos	 separados	 por	 vírgulas	 entre	 colchetes,	 ou	
gerados	pelos	operadores	..	(dois	pontos)	ou	...	(três	pontos).
d. Lógico:	operações	de	comparações	que	obtém	um	valor	lógico (não	
podem	ser	armazenados em	variáveis).
3) Valores:
a. Variáveis (começam	com	_	ou	letras,	seguidos	de	_,	letras	ou	dígitos).
b. Literais (inteiros,	strings e	arranjos).
4) Operadores:
a. Inteiro: + (adição),	 - (subtração),	 * (multiplicação),
/ (divisão),	% (resto),	** (exponenciação).
b. String:	+ (concatenação)
c. Arranjos:	+ (concatenação),	.. (faixa	inclusivo,	ex.:	3..5	gera	[3,4,5])	
e	...	(faixa	exclusivo,	ex.:	3..5	gera	[3,	4]).
d. Lógico: == (igual entre	inteiros,	strings),	!= (diferença ente	inteiros	
ou	 strings),	 < (menor entre	 inteiros),	 > (maior entre	 inteiros),	 <=
(menor	 igual entre	 inteiros),	 >= (maior	 igual entre	 inteiros), ===
(contém inteiro	ou	string	em	um	arranjo),	not (negação).
e. Conector: and (E	lógico),	or (OU	lógico).
5) Funções:
a. gets:	ler	uma	linha do	teclado,	sem	o	caracter	de	nova	linha	(\n).
b. rand: gerar	um	número	inteiro	aleatório.
c. .length: obter	o	tamanho	de	um	arranjo.
d. .to_i: converter	uma	string	para	inteiro;	se	não	for	possível	converter	
para	0	(zero).
e. .to_s: converter	um	inteiro	ou	arranjo	para	string

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
