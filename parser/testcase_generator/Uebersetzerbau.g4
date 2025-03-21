grammar Uebersetzerbau;

program: ((funcdef | fundec) ';')+ EOF;

funcdef: fundec stats END;

fundec: ID '(' pars ')' ':' type;

pars: (par (',' par)*)?;

par: ID ':' type;

type: (ARRAY OF)* INT;

stats: (stat ';')*;

stat:
	RETURN expr
	| IF cond THEN stats (ELSE stats)? END
	| WHILE cond DO stats END
	| VAR ID ':' type ':=' expr
	| lexpr ':=' expr
	| term;

cond: (cterm OR)* (NOT)? cterm;

cterm: '(' cond ')' | expr '=' expr | expr '<' expr;

lexpr: ID | term '[' term ']';

expr: term ('+' term)* | term ('*' term)* | term '-' term;

term:
	'(' expr ')'
	| NUM
	| term '[' expr ']'
	| ID
	| ID '(' (expr (',' expr)*)? ')';

END: 'end';
IF: 'if';
THEN: 'then';
ELSE: 'else';
WHILE: 'while';
DO: 'do';
VAR: 'var';
ARRAY: 'array';
OF: 'of';
INT: 'int';
RETURN: 'return';
OR: 'or';
NOT: 'not';

NUM: [0x]? [0-9]+;

ID: [a-zA-Z][a-zA-Z_0-9]*;

WS: [ \t\n\r\f]+ -> skip;
COMMENT: '/*' .*? '*/' -> skip;