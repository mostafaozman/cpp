/*
  Mostafa Osman
  September 12 2019
  This code plays a guessing game. It picks a random number from 1 - 100 and asks the player
  to guess. It well then tell you wether the guess is too high or low while keeping track of 
  the number of guesses. After the number is guessed the program will ask you if you want to
  play again. 
 */ 
#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL));
  int random = rand() % 101;
  // Generates a random number from 1 - 100
  int numguesses = 0;
  int guess = 0; 
  char answer; 
  bool playing = true; 
  // Declares all variables

  while (playing == true)
    {
      cout << "Please guess a number from 1 to 100" << endl; 
      cin >> guess;
      // Promts for a guess and records it
      if (guess == random)
	{
	  cout << "You guessed the right number, it was " << random << "!";
	  cout << " It took you: " << numguesses << " guesses." << endl;
	  cout << "Would you like to play again? y/n " << endl;
	  cin >> answer; 
	  // If the guess is the same as the random number, displays number of guesses and 
	  // asks if you want to play again
	  
	  if (answer == 'y')
	    {
	      playing = true;
	      
	      random = rand() % 101;
	      numguesses = 0; 
	      // Plays again and generates a new random number
	    }

	  else if (answer == 'n')
	    {
	      playing = false;
	      numguesses = 0; 

	      // If no then ends program
	    }
	}

      else if (guess > random)
	{
	  cout << "You guessed to high! Please try again." << endl; 
	    numguesses += 1; 
	    // If guess is greater than random, add one to number of guesses
	}

      else if (guess < random)
	{
	  cout << "You guessed too low! Please try again." << endl;
	    numguesses += 1;

	    // If guess is less than random, add one to number of guesses
	}
    } 
  return 0; 
}
