// Keywords2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

// Create an int var to count the number of simulations being run starting at 1
int loop = 1;

int main()
{
	// Display Title of program to user
	cout << "Hello and welcome to the code breaker challenge";

	// Ask the recruit to login using thier name
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string name;
	cout << "\nEnter your name: ";
	cin >> name;

	// Display an overview of what Keywords II is to the recruit 
	cout << "\n------------------------------------------------------------------------------";
	cout << "\nThis code breaker challenge is designed to test your\nability to guess a word in a certain amount of guesses";
	cout << "\n------------------------------------------------------------------------------";

	// Display directions to the recruit on how to use Keywords
	cout << "\n------------------------------------------------------------------------------";
	cout << "\nYou will have 8 chances to guess each word that is shown.";
	cout << "\nThe amount of letters in each word will be displayed with _";
	cout << "\nThere will be 3 words in each simulation.";
	cout << "\nIf you guess correctly you win and can choose to play again.";
	cout << "\n------------------------------------------------------------------------------" << endl;

	// Create a collection of 10 words you had wrote down manually
	const int MAX_WRONG = 8; // Max number of incorrect guesses allowed
	vector<string> words; //Collection of possible words to guess
	words.push_back("HELLO");
	words.push_back("HARD");
	words.push_back("STARWARS");
	words.push_back("HYPER");
	words.push_back("FRIEND");
	words.push_back("MANIA");
	words.push_back("ANIMATION");
	words.push_back("OPENING");
	words.push_back("SURF");
	words.push_back("GOODBYE");

	// Display the simulation # is staring to the recruit. 
	cout << "\nThis is simulation #" << loop << endl;

	int answered = 0;
	int wrong = 0; //Number of incorrect guesses

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	// Tell recruit how many incorrect guesses he or she has left
	// Show recruit the letters he or she has guessed
	// Show player how much of the secret word he or she has guessed
	while (answered < 3) // Establishes that the user needs to answer 3 correctly to complete the game
	{
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		const string THE_WORD = words[0]; //Word to guess
		string soFar(THE_WORD.size(), '-'); //Word guessed so far
		string used = ""; //Letters already guessed

		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{

			cout << "\n\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left. " << name << "\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is:\n" << soFar << endl;

			// Get recruit's next guess
			char guess;
			cout << "\n\nEnter your guess " << name << ": ";
			cin >> guess;
			guess = toupper(guess); //Make uppercase since secret word in uppercase

			// While recruit has entered a letter that he or she has already guessed
			while (used.find(guess) != string::npos)
			{
				cout << "\nYou've already guessed " << guess << endl;
				cout << "enter your guess"; // Get recruit ’s guess
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess; // Add the new guess to the group of used letters

			// If the guess is in the secret word
			// Tell the recruit the guess is correct
			// Update the word guessed so far with the new letter
			// Otherwise
			// Tell the recruit the guess is incorrect
			// Increment the number of incorrect guesses the recruit has made
			if (THE_WORD.find(guess) != string::npos)
			{
				cout << "That's right " << name << "! " << guess << " is in the word.\n";
				//Update soFar to include newly guessed letter
				for (int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}
		// If the recruit has made too many incorrect guesses
		// Tell the recruit that he or she has failed the Keywords II course.
		// Otherwise
		// Congratulate the recruit on guessing the secret words
		if (wrong == MAX_WRONG)
		{
			cout << "\nYou reached the max amount of tries " << name << ". Here is a new word";
			cout << "\nThe word was " << THE_WORD << endl;
			main();
		}
		else
		{
			answered++; // add 1 to the variable answered
			int left = 3 - answered;
			cout << "\nYou guessed it! You have " << left << " left to answer."; // Display how many left to answer
		}
	}

	// Ask the recruit if they would like to run the simulation again
	string again;
	cout << "\nWould you like to play again " << name << "? Y or N: ";
	cin >> again;

	// If the recruit wants to run the simulation again
	// Increment the number of simiulations ran counter
	// Move program execution back up to // Display the simulation # is staring to the recruit.
	if ((again == "Y") | (again == "y"))
	{
		++loop;
		main();
	}

	// Otherwise 
	// Display End of Simulations to the recruit
	// Pause the Simulation with press any key to continue
	else
	{
		cout << "Thanks for Playing " << name << "!" << endl;
		return 0;
	}
}