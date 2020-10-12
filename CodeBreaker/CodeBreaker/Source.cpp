/*By: Naszir Merritt
10/11/2020

In this project we used arrays to create a word jumble for the player.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	char playAgain = 'y';

	while (playAgain == 'y' || playAgain == 'Y')
	{
		cout << "\t\t\tWelcome to the beginning of the rest of your life, Spy jumble!\n\n";
		cout << "The following is a test to see your place in this secret service, unscramble the following words to the best of your ability.\n";
		cout << "Now you may run into trouble, enter 'hint' for a clue on the word.\n";
		cout << "Enter 'quit' to quit the game.\n\n";
		for (int i = 0; i < 3; ++i) // number of jumbles cycled through
		{

			
			enum fields { WORD, HINT, NUM_FIELDS }; // enumeration file set up for your array
			const int NUM_WORDS = 10; // constant capacity of the array
			const string WORDS[NUM_WORDS][NUM_FIELDS] =

			{
				{"laser", "There are alot of these protecting the safe."},
				{"watch", " This is key to keeping track oif time during a mission."},
				{"tranquilizer", "You can use this to put your enemies to sleep."},
				{"jet", "We will take this to get to missions ASAP."},
				{"a.i.", "This system will help you navigate through challenging obstacles."},
				{"robot", "Many of our engineers work on this technology, for environments not safe for humans to be in."},
				{"headquarters", "This is homebase where all intel and agents meet."},
				{"comrades", "These will be your lifeline on the job. Don't leave anyone behind, there safety come before the mission."},
				{"companions", "Each agent has an animal partner."},
				{"gadgets", "These are tools to use in a tight spot."}

			};// contents within array


			srand(static_cast<unsigned int>(time(0))); // random set up
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD]; // word to guess 
			string theHint = WORDS[choice][HINT]; // hint for guess 
			string jumble = theWord; // jumbled version of the word 
			int length = jumble.size();
			// jumbling word 
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;


			}





			cout << "The jumble is: " << jumble; // giving user jumbled word

			string guess;
			cout << "\n\nYour guess: "; // asking user for input
			cin >> guess;

			while ((guess != theWord) && (guess != "quit")) 
			{
				if (guess == "hint")
				{
					cout << theHint; // hint on the jumbke at hand
				}
				else
				{
					cout << "Sorry, That's not it.";

				}
				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == theWord) // correct guess outcome
			{
				cout << "\n That's it you guessed it!\n";

			}
		}
		cout << "would you like to play again?";
		cin >> playAgain;
	}
	cout << "\nThanks for playing.\n";

	return 0;
}
