/*********************************************************************************
	Written by:		Jeremy High
	Student ID:		103306452
	Written on:		Friday, November 15th, 2013

	Used in parallel with tiny.jar and calc.tiny to perform the tasks required
	by the assignment 3 specifications
*********************************************************************************/
import java.util.*;

aspect A2 {
	int indent = 0;
	int numExpr = 0;
	int blockCount = 0;

	Hashtable<String, Integer> htable = new Hashtable<String, Integer>();

	/*****************************************************************************
		Suppresses original output and prints out the assignment expressions
	*****************************************************************************/
	String around(): call(* Program.toString(..)) { 
		StringBuffer str = new StringBuffer();
		int counter = 0;

		for (String v : Program.varTable.keySet()) {
			System.out.print("Assignment " + counter + " is: " + v + " = ");
			output2(Program.varTable.get(v));
			++counter;
			System.out.println("");
			int result = eval(Program.varTable.get(v));
			htable.put(v, result);
		}

		return "";
	}

	/*****************************************************************************
		Increases indentation for following printed lines

		e	- An expression on the right hand side of the assignment operator
	*****************************************************************************/
	int around(Expr e): call(int eval(Expr)) && args(e) { 
		int retval;

		++indent;
		return proceed(e);
	}

	/*****************************************************************************
		Prints out the arrows that point to question marks

		e	- An expression on the right hand side of the assignment operator
	*****************************************************************************/
	before(Expr e): call(int eval(Expr)) && args(e) {
		indent();
		output(e);

		if (blockCount == 0) {
			++numExpr;
		}

		System.out.println(" ==> ?");
	}

	/*****************************************************************************
		Prints out the arrows that point to actual values
		
		e	- An expression on the right hand side of the assignment operator
	*****************************************************************************/
	after(Expr e) returning (int i): call(int eval(Expr)) && args(e) {
		indent();
		output(e);

		System.out.println(" ==> "+ i);

		--indent;
	
	}

	/*****************************************************************************
		Recursively evaluates the expressions passed in

		e	- An expression on the right hand side of the assignment operator
	*****************************************************************************/
	int eval(Expr e) {
		int value;
		String id, op;
		Expr e1, e2;

		if (e.isPrimitive()) {
			if (e.getID() == null) {
				return e.getValue();
			} else {
				++blockCount;
				value = eval(Program.varTable.get(e.getID()));
				--blockCount;
				return value;
			}
		} else {
			op = e.getOp();
			e1 = e.getLeft();
			e2 = e.getRight();

			if (op.equals("*")) {
				return eval(e1) * eval(e2);
			} else {
				return eval(e1) + eval(e2);
			}
		}
	}

	/*****************************************************************************
		Recursively produces the output that is now printed to stdout

		e	- An expression on the right hand side of the assignment operator
	*****************************************************************************/
	void output(Expr e) {
		int value;
		String id, op;
		Expr e1, e2;

		if (e.isPrimitive()) {
			if (e.getID() == null) {
				System.out.print(e.getValue());
			} else {
				System.out.print(e.getID());
			}
		} else {
			op = e.getOp();
			e1 = e.getLeft();
			e2 = e.getRight();

			System.out.print("(");
			if (op.equals("*")) {
				output(e1); 
				System.out.print("*"); 
				output(e2);
			} else {
				output(e1);
				System.out.print("+"); 
				output(e2);
			}

			System.out.print(")");
		}
	}

	/*****************************************************************************
		Similar to output(), but prints from htable instead of getting the ID

		e	- An expression on the right hand side of the assignment operator
	*****************************************************************************/
	void output2(Expr e) {
		int value;
		String id, op;
		Expr e1, e2;

		if (e.isPrimitive()) {
			if (e.getID() == null) {
				System.out.print(e.getValue());
			} else {
				System.out.print(htable.get(e.getID()));
			}
		} else {
			op = e.getOp();
			e1 = e.getLeft();
			e2 = e.getRight();

			System.out.print("(");
			if (op.equals("*")) {
				output(e1); 
				System.out.print("*"); 
				output(e2);
			} else {
				output(e1);
				System.out.print("+"); 
				output(e2);
			}

			System.out.print(")");
		}
	}

	/*****************************************************************************
		Generates the indentation for each line of the output
	*****************************************************************************/
	void indent() {
		int i;

		for (i = indent; i > 0; --i) {
			System.out.print("    ");
		}
	}

	/*****************************************************************************
		Prints out the number of expressions found in the .tiny file
	*****************************************************************************/
	after(): execution(public static * main(..)) {
		System.out.println("Number of expressions: " + numExpr);
	}
}
