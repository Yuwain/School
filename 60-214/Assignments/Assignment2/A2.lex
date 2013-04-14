import java.io.*;

%%
%{ 	public static void main(String argv[]) throws Exception
	{
		A2 ylex = new A2(new FileReader("A2.input"));
		FileWriter out = new FileWriter("A2.output");	
		ylex.yylex();

		out.write("Identifiers: " +  ylex.identifiers + 
				  "\nKeywords: " + ylex.keywords + 
				  "\nNumbers: " + ylex.numbers + 
				  "\nLines: " + ylex.yyline + 
				  "\nQuotedString: " + ylex.quotes +
				  "\n");
		out.close();
	}
%}

%line
%integer
%class A2
%{
	int identifiers, keywords, quotes, numbers;
%}

COMMENT = \/\*\*([^*]|[\r\n]|(\*([^*]|[\r\n]))|(\*\*([^\/]|[\r\n])))*\*\*\/ 
QUOTE = \"([^\"])*\"
KEYWORD = IF|ELSE|WRITE|READ|RETURN|BEGIN|END|MAIN|INT|REAL
NUMBER = [0-9]+|[0-9]+\.[0-9]+
IDENTIFIER = [a-zA-Z][a-zA-Z0-9]*
%%

{COMMENT} 		{}
{QUOTE} 		{ ++quotes; }
{KEYWORD} 		{ ++keywords; }
{NUMBER} 		{ ++numbers; }
{IDENTIFIER} 	{ ++identifiers; }
[\r\n] 			{}
.				{}
