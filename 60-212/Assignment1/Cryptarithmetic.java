//Jeremy High 	- 103306452
//Assignment 1 	- 60-212-52
//September 11th, 2012

//Program is used to solve the cryptarithmetic puzzle TOO + TOO + TOO + TOO = GOOD
public class Cryptarithmetic
{
	public static void main(String[] args) 
	{
		int T, O, G, D;
	
		//Checks every possible combination of numbers
		for (T = 0; T <= 9; ++T)
			for (O = 0; O <= 9; ++O)
				for (G = 0; G <= 9; ++G)
					for (D = 0; D <= 9; ++D)

						//Checks if math works out correctly, that none of the letters have the same number as another, and that T and G aren't 0
						if ((CheckMath(T, O, G, D) == 1) && T != O && T != G && T != D && O != G && O != D && G != D && T != 0 && G != 0)
							System.out.println("T = " + T + " O = " + O + " G = " + G + " D = " + D +
											   "\n\tTOO	" + T + O + O + 
											   "\n\tTOO	" + T + O + O +
											   "\n\tTOO	" + T + O + O +
											   "\n+\tTOO	" + T + O + O +
											   "\n------------------------" +
											   "\n\tGOOD   " + G + O + O + D +
											   "\n");
	}
	
	//Input: Integers T, O, G, and D
	//Output: 1 if TOO + TOO + TOO + TOO = GOOD, 0 if not
	//Purpose: To check if the necessary math works
	public static int CheckMath(int T, int O, int G, int D)
	{
		if ((T * 400 + O * 44) == (G * 1000 + O * 110 + D))
			return 1;
		else
			return 0;
	}
}
