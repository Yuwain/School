/***************************************************************************************
	Written by:			Jeremy High
	Student ID:			103306452
	Written on:			March 20th, 2013

	This program tests an AI for the game Mastermind. The AI measures how 
	well a player is doing and increases its difficulty accordingly

	Currently, the player and AI choose codes and the AI guesses better 
	as the player wins more often

	TODO Track what numbers players guess most often, have AI choose least 
	likely for password making
***************************************************************************************/

/* Imports */
import java.lang.Math;
import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Mastermind {
	public static void main(String[] args) {
		int turn = 1;						//Used to keep under 11 guesses
		int round = 0;						//How many rounds have been played
		int spotTotal = 0;					//Amount of numbers in both the guess and the code
		int playerWins = 0;					//How many times the player has won
		int computerWins = 0;				//How many times the AI has won
		int winDifference = 0;				//playerWins - computerWins
		
		int[] spot = new int[2];			//Holds the amount of matching numbers
		int[] numUsed = new int[6];			//The number of times a certain number is used in playerCode
		int[] playerCode = new int[4];		//The password the AI wants to guess
		int[] playerGuess = new int[4];		//The guess we're making
		int[] computerCode = new int[4];	//The password the player wants to guess
		int[] computerGuess = new int[4];	//The guess we're making

		int[][] guessList = new int[10][4];	//Holds the guesses we've already made

		boolean playing = true;				//True until player wants to stop
		boolean memory = false;				//Increases the success rate of HardAI
		boolean correct = false;			//True if the guess is the same as the code
		boolean validAnswer = false;		//True if player inputs a valid answer
		
		String answer;						//Used to tell if player wants to keep playing

		Scanner in = new Scanner(System.in);

		while (playing) {
			++round;

			/* Re-initialize variables for new rounds */
			if (round > 1) {
				turn = 1;
				spotTotal = 0;
				correct = false;
				validAnswer = false;
				winDifference = playerWins - computerWins;
				memory = winDifference >= 5 ? true : false; 

				for (int[] row : guessList)
					Arrays.fill(row, 0);
			}

			GetCodes(playerCode, computerCode, in);

			while (!correct && turn <= 10) {
				GetGuess(playerGuess, in);

				if (correct = CompareCorrect(computerCode, playerGuess, spot)) {
					++playerWins;
					System.out.println("\nPlayer has guessed the code!");
				} else {

					/* Change difficulty based on how much player wins */
					if (playerWins <= -3) {
						for (int i = 0; i < 4; ++i) //Generate a random guess
							computerGuess[i] = (int)(Math.random() * 6) + 1;
					} else if (playerWins < 3) {
						MediumAI(computerGuess, numUsed, round, guessList);
					} else {
						HardAI(computerGuess, turn, spotTotal, guessList);
					}

					for (int i = 0; i < 4; ++i) {
						if (i == 0)
							System.out.print("Computer has guessed ");
						System.out.print(computerGuess[i]);
					}

					if (correct = CompareCorrect(playerCode, computerGuess, spot)) {
						++computerWins;
						System.out.println("\nComputer has guessed the code!");
					} else {
						if (memory)
							System.arraycopy(computerGuess, 0, guessList[turn - 1], 0, 4);

						spotTotal = spot[0] + spot[1];
					}
				}

				++turn;
			}

			if (!correct)
				System.out.println("\nNeither the player nor the computer guessed correctly");

			for (int i = 0; i < 4; ++i)
				++numUsed[playerCode[i] - 1];

			/* Ask if player wants to keep playing */
			while (!validAnswer) {
				validAnswer = true;

				System.out.println("Play another round? (Y/N)");
				answer = in.next();
			
				if (answer.equals("y") || answer.equals("Y")) {
					playing = true;
				} else if (answer.equals("n") || answer.equals("N")) {
					playing = false;
				} else {
					System.err.println("Invalid option");
					validAnswer = false;
				}
			}
		}

		PrintGameStats(numUsed, playerWins, computerWins);

		return;
	}

	/***************************************************************************************
		Gets the two codes that need to be guessed, player's code first

		PlayerCode		- The code the player makes and that the AI wants to guess
		ComputerCode	- The code the AI makes and that the player wants to guess
	***************************************************************************************/
	private static void GetCodes(int[] playerCode, int[] computerCode, Scanner in) {
		boolean validCode = false;	

		/* Player inputs a 4 digit code until it is valid */
		while (!validCode) {
			validCode = true;

			for (int i = 0; i < 4; ++i) {
				if (i == 0) {
					System.out.println("Please enter a four digit password:");
				}

				int temp = in.nextInt();

				if (temp > 6 || temp < 1) {
					System.err.println("Invalid number");
					validCode = false;
					break;
				} else {
					playerCode[i] = temp;
				}
			} 
		}

		System.out.println("Player code set");

		/* Computer generates a random 4 digit code */
		for (int i = 0; i < 4; ++i)
			computerCode[i] = (int)(Math.random() * 6) + 1;

		System.out.println("Computer code set \n");

		return;
	}

	/***************************************************************************************
		Gets the player's next guess, checking to make sure it is valid

		PlayerGuess		- The guess the player is making
	***************************************************************************************/
	private static void GetGuess(int[] playerGuess, Scanner in) {
		boolean validGuess = false;

		/* Player inputs a 4 digit guess until it is valid */
		while (!validGuess) {
			validGuess = true;

			for (int i = 0; i < 4; ++i) {
				if (i == 0)
					System.out.println("Please input a four digit guess:");

				int temp = in.nextInt();

				if (temp > 6 || temp < 0) {
					System.err.println("Invalid number");
					validGuess = false;
					break;
				} else {
					playerGuess[i] = temp;
				}
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (i == 0)
				System.out.print("Player has guessed ");
			System.out.print(playerGuess[i]);
		}

		return;
	}

	/***************************************************************************************
		Compares to see how many elements are the same at the same position
	 
		Code	- The code we want to guess
		Spot	- An array of how many elements are the same and how many are in the 
				  wrong place
		Guess	- The code that is being guessed

		Returns true if the guess is the same as the code and returns false otherwise
	***************************************************************************************/
	private static boolean CompareCorrect(int[] code, int[] guess, int[] spot) {
		int[] temp = new int[4]; //The code is modified, so we work with a different array
		System.arraycopy(code, 0, temp, 0, code.length);

		int[] copy = new int[4]; //The guess is modified, so we work with a different array
		System.arraycopy(guess, 0, copy, 0, guess.length);

		spot[0] = 0; //The amount of numbers in the correct position
		spot[1] = 0; //The amount of numbers in the incorrect position

		/* Check for correct position */
		for (int i = 0; i < 4; ++i) {
			if (copy[i] == temp[i]) {
				temp[i] = 0;
				copy[i] = 0;
				++spot[0];
			}
		}

		/* Check for incorrect position */
		if (spot[0] != 4) {
			for (int k = 0; k < 4; ++k) {
				for (int i = 0; i < 4; ++i) {
					if (copy[k] == temp[i] && copy[k] != 0) {
						temp[i] = 0;
						copy[k] = 0;
						++spot[1];
					}

				}
			}

			System.out.println("\n" +
							   "Number in correct spot: " + spot[0] + "\n" +
							   "Number in incorrect spot: " + spot[1] + "\n");
			return false;
		} else {
			return true;
		}
	}

	/***************************************************************************************
		Generates a guess based on the number the player chooses most frequently 
		for their code

		Method has ~0.78% success rate with memory
		Method has ~0.78% success rate without memory

		Guess		- The code we are generating
		Round		- The round of the game we currently playing	  
		numUsed		- The amount of times the number i+1 has been used in the code made 
					  by the player
		guessList	- The list of all previous guesses made this round
	***************************************************************************************/
	private static void MediumAI(int[] guess, int[] numUsed, int round, int[][] guessList) {
		int max = 0;
		int pos = 0;

		boolean loop = true;

		/* Find which number is used most frequently */
		for (int i = 0; i < numUsed.length; ++i) {
			if (numUsed[i] > max) {
				max = numUsed[i];
				pos = (i + 1);
			}
		}

		while (loop) {
			loop = false;

			/* Doubles the probability of the most common
			   number being chosen by the computer */
			for (int i = 0; i < 4; ++i) {
				if ((Math.random() < 0.4) && round > 1) {
					guess[i] = pos;
				} else {
					guess[i] = (int)(Math.random() * 6) + 1;
				}
			}

			/* Check if guess has been made before */
			for (int i = 0; i < 10; ++i) {
				if (Arrays.equals(guessList[i], guess)) {
					loop = true;
					break;
				}
			}
		}

		return;
	}

	/***************************************************************************************
		Generates a guess by first finding what numbers are in the code and then
		shuffling those four digits around

		Method has ~49% success rate with memory
		Method has ~40% success rate without memory

		Turn		- The current turn in the current round
		Guess		- The code we are generating
		InCode		- The amount of numbers in our guess that are also in the code
		guessList	- The list of all previous guesses made this round
	***************************************************************************************/
	private static void HardAI(int[] guess, int turn, int inCode, int[][] guessList) {

		boolean loop = true;

		/* The first 6 turns are devoted to finding which 
		   numbers in are the code (unless found already) */
		if (turn <= 6 && inCode != 4) {
			for (int i = inCode; i < 4; ++i)
				guess[i] = turn;
		} else {
			while (loop) {
				loop = false;

				/* Create an ArrayList, populate and 
				   shuffle it to get our next guess */
				List<Integer> list = new ArrayList<Integer>();

				for (int i = 0; i < 4; ++i)
					list.add(guess[i]);

				Collections.shuffle(list);

				for (int i = 0; i < 4; ++i)
					guess[i] = list.get(i);

				/* Check if guess has been made before */
				for (int i = 0; i < 10; ++i) {
					if (Arrays.equals(guessList[i], guess)) {
						loop = true;
						break;
					}
				}
			} 
		}

		return;
	}

	/***************************************************************************************
	 	Prints the wins for each player as well as the number of times the user
		has chosen each number for their code

		numUsed			- How many times the player has chosen each number in 
						  their code
		playerWins		- How many times the player has won
		computerWins	- How many times the computer has won
	***************************************************************************************/
	private static void PrintGameStats(int[] numUsed, int playerWins, int computerWins) {
		System.out.println("\nPlayer wins: " + playerWins + "\n" +
						   "Computer wins: " + computerWins);

		for (int i = 0; i < 6; ++i) {
			if (i == 0) {
				System.out.println("Times each number has been used in the player code:\n" +
								   "1 \t 2 \t 3 \t 4 \t 5 \t 6\n");
			}

			System.out.print(numUsed[i] + " \t ");
		}

		System.out.println();
	}
}
