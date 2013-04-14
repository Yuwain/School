import java.io.*;

%%
%{ 	public static void main(String $$[]) throws Exception
	{
		A2 _$_ = new A2(new FileReader("A2.input"));
		FileWriter $ = new FileWriter("A2.output");	
		_$_.yylex();

		$.write("identifiers: " +  _$_.___ + "\nkeywords: " + _$_._____ + "\nnumbers: " + _$_._______ + "\nlines: " + _$_.yyline + "\nquotedString: " + _$_._________);
		$.close();
	}
%}

%line
%integer
%class A2
%{
	int ___, _____, _________, _______;
%}
%%

\/\*\*([^*]|[\r\n]|(\*([^*]|[\r\n]))|(\*\*([^\/]|[\r\n])))*\*\*\/ {}
\"([^\"])*\" {
	++_________;
}
IF|ELSE|WRITE|READ|RETURN|BEGIN|END|MAIN|INT|REAL { 
	++_____;
}
[0123456789]+|[0123456789]+\.[0123456789]+ {
	++_______;
}
[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]* { 
	++___;
}
\r|\n|. {}
