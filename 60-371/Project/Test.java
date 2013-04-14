import java.lang.Math;
import java.util.Arrays;

class test {
	public static void main(String[] args) {
		int j;
		int numInTen = 0;
		double average = 0;

		for (j = 1; j <= 100000; j++) {
			int i;
			int numGuess = 0;
			int code[] = new int[4];
			int guess[] = new int[4];
			boolean correct = false;

			for (i = 0; i < 4; i++) {
				code[i] = (int)(Math.random() * 6) + 1;
			}

			while (!correct) {
				for (i = 0; i < 4; i++) {
					guess[i] = (int)(Math.random() * 6) + 1;

//					if (i == 0)
//						System.out.println("Code \t Guess \t " + j);

//					System.out.println(code[i] + " \t " + guess[i] + " \t " + j);
				}

				++numGuess;

				if (Arrays.equals(code, guess))
					correct = true;
			}

//			System.out.println("Number of guesses: " + numGuess);

			if (numGuess <= 10)
				++numInTen;

			average += numGuess;
		}

		--j;
		average = (average / j);

		System.out.format("\n" +
						  "Number of codes guessed: %d\n" +
						  "Number of codes guessed on [1, 10] turns: %d\n" +
						  "Average guesses: %.2f\n", j, numInTen, average);

		return;
	}
}
