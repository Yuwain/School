//Jeremy High 	   - 103306452
//Lab Assignment 1 - 60-212-51
//September 20th, 2012

import java.util.Scanner;

//Program is used to calculate the next prime number after an input number
public class Prime {
	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		int x = 0;
		int n = 0;
		
		System.out.print("Input a number to find the first prime after: ");

		x = in.nextInt();
		n = x;
		++x;
		x = SearchPrime(x);

		System.out.println("The next prime number after " + n + " is " + x);
	}

//Input: An integer, x
//Output: The next prime number after x
//Purpose: To find the next prime number after x
	public static int SearchPrime(int x) {
		int y;

		for (; ; ++x)
			for (y = (x/2); y > 0; --y)
				if ((x % y == 0) && y != 1)
					break;
				else if ((x % y == 0) && y == 1)
					return x;
				
			

	}
}
