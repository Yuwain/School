import java.io.*;
import java_cup.runtime.*;

%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class A4Scanner
%eofval{ return null;
%eofval}

COMMENT = \/\*\*([^*]|[\r\n]|(\*([^*]|[\r\n]))|(\*\*([^\/]|[\r\n])))*\*\*\/ 
QUOTE = \"([^\"])*\"
NUMBER = [0-9]+|[0-9]+\.[0-9]+
IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
%%

{COMMENT} 	 { }
{QUOTE} 	 { return new Symbol(A4Symbol.QUOTE, yytext()); }
"IF" 		 { return new Symbol(A4Symbol.IF); }
"ELSE" 		 { return new Symbol(A4Symbol.ELSE); }
"WRITE" 	 { return new Symbol(A4Symbol.WRITE); }
"READ" 		 { return new Symbol(A4Symbol.READ); }
"RETURN" 	 { return new Symbol(A4Symbol.RETURN); }
"BEGIN" 	 { return new Symbol(A4Symbol.BEGIN); }
"END" 		 { return new Symbol(A4Symbol.END); }
"MAIN" 		 { return new Symbol(A4Symbol.MAIN); }
"INT" 		 { return new Symbol(A4Symbol.INT); }
"REAL" 		 { return new Symbol(A4Symbol.REAL); }
";"			 { return new Symbol(A4Symbol.SEMI); }
","			 { return new Symbol(A4Symbol.COMMA); }
"("			 { return new Symbol(A4Symbol.LPAREN); }
")"			 { return new Symbol(A4Symbol.RPAREN); }
"+"			 { return new Symbol(A4Symbol.PLUS); }
"-"			 { return new Symbol(A4Symbol.MINUS); }
"*"			 { return new Symbol(A4Symbol.TIMES); }
"/"			 { return new Symbol(A4Symbol.DIVIDE); }
":="		 { return new Symbol(A4Symbol.CEQUAL); }
"=="		 { return new Symbol(A4Symbol.EEQUAL); }
"!="		 { return new Symbol(A4Symbol.NEQUAL); }
{NUMBER}  	 { return new Symbol(A4Symbol.NUMBER, yytext()); }
{IDENTIFIER} { return new Symbol(A4Symbol.IDENTIFIER, yytext()); }
\r|\n|\t|" " { }
. 			 { return new Symbol(A4Symbol.ERROR); }
