import java.io.*;
import java_cup.runtime.*;

%%
%implements java_cup.runtime.Scanner
%type Symbol
%function next_token
%class A3Scanner
%eofval{ return null;
%eofval}

COMMENT = \/\*\*([^*]|[\r\n]|(\*([^*]|[\r\n]))|(\*\*([^\/]|[\r\n])))*\*\*\/ 
QUOTE = \"([^\"])*\"
NUMBER = [0-9]+|[0-9]+\.[0-9]+
IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
%%

{COMMENT} 	 { }
{QUOTE} 	 { return new Symbol(A3Symbol.QUOTE); }
"IF" 		 { return new Symbol(A3Symbol.IF); }
"ELSE" 		 { return new Symbol(A3Symbol.ELSE); }
"WRITE" 	 { return new Symbol(A3Symbol.WRITE); }
"READ" 		 { return new Symbol(A3Symbol.READ); }
"RETURN" 	 { return new Symbol(A3Symbol.RETURN); }
"BEGIN" 	 { return new Symbol(A3Symbol.BEGIN); }
"END" 		 { return new Symbol(A3Symbol.END); }
"MAIN" 		 { return new Symbol(A3Symbol.MAIN); }
"INT" 		 { return new Symbol(A3Symbol.INT); }
"REAL" 		 { return new Symbol(A3Symbol.REAL); }
";"			 { return new Symbol(A3Symbol.SEMI); }
","			 { return new Symbol(A3Symbol.COMMA); }
"("			 { return new Symbol(A3Symbol.LPAREN); }
")"			 { return new Symbol(A3Symbol.RPAREN); }
"+"			 { return new Symbol(A3Symbol.PLUS); }
"-"			 { return new Symbol(A3Symbol.MINUS); }
"*"			 { return new Symbol(A3Symbol.TIMES); }
"/"			 { return new Symbol(A3Symbol.DIVIDE); }
":="		 { return new Symbol(A3Symbol.CEQUAL); }
"=="		 { return new Symbol(A3Symbol.EEQUAL); }
"!="		 { return new Symbol(A3Symbol.NEQUAL); }
{NUMBER}  	 { return new Symbol(A3Symbol.NUMBER); }
{IDENTIFIER} { return new Symbol(A3Symbol.IDENTIFIER); }
[\r\n] 		 { }
. 			 { }
