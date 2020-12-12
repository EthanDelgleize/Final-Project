//Hangman Final project
//Ethan Delgleize
//Aaron Martinez
// Llendel Reyes
// Kane SVelan
// Jaydon Eppinette

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cctype>
#include <vector>
#include <string.h>

using namespace std;

const int MAX_WORD_SIZE = 21;
const int MAX_WORD_LIST = 5;
void Search(char[], char[], char, int);
void HangmanGreeting(string);
string Menu();
int main()
{
	string categoryName;
	string userName;
	string chosenWord;
	string wordList[MAX_WORD_LIST];			//String array that holds list of words
	char wordComplete[MAX_WORD_SIZE];		//Char array that holds selected word
	char wordIncomplete[MAX_WORD_SIZE];
	char wordCheck[MAX_WORD_SIZE];
	char choice; // Variable that holds the user's choice to begin or try again. 
	
	char input;
	int lives = 5;
	int numguess = 10;
	int wordlength;
	int randomNum = (rand() % 5);			//Initializes a random number generator
	srand(time(0));							//Creates random number
	int index = 0;							//Sets index to 0
	bool check;
	cout << "			Please enter your username:" << endl;
	cin >> userName;

	cout << endl;
	HangmanGreeting(userName);
	cout << "			Hello " << userName << "!" << endl;
	cout << endl;
	cout << "			Press y if you would like to start a game, or n if you would like to quit." << endl;
	cin >> choice;




	if (choice == 'N' || choice == 'n')
	{
		cout << "			Have a nice day!" << endl;
		return 0;
	}
	else if (choice == 'Y' || choice == 'y')
	{
		chosenWord = Menu();
		wordlength = chosenWord.length();
		for (int i = 0; i < wordlength; i++)
		{
			wordIncomplete[i] = '-';
			wordCheck[i] = '-';
			wordComplete[i] = chosenWord[i];

		}
		for (int i = wordlength; i < MAX_WORD_SIZE - 1; i++)
		{
			wordIncomplete[i] = ' ';
			wordCheck[i] = ' ';
			wordComplete[i] = ' ';

		}

	}


	while (lives > 0)
	{
		while (numguess > 0)
		{
			for (int i = 0; i < wordlength; i++)
			{

				wordCheck[i] = wordIncomplete[i];
			}
			cout << "Enter a lower case letter." << "\n> ";
			for (int i = 0; i < wordlength; i++)
			{
				cout << wordIncomplete[i];
			}
			cout << endl;
			cin >> input;
			while (!((input == 'a') || (input == 'b') || (input == 'c') || (input == 'd') || (input == 'e') || (input == 'f') || (input == 'g') || (input == 'h') || (input == 'i') || (input == 'j') || (input == 'k') || (input == 'l') || (input == 'm') || (input == 'n') || (input == 'o') || (input == 'p') || (input == 'q') || (input == 'r') || (input == 's') || (input == 't') || (input == 'u') || (input == 'v') || (input == 'w') || (input == 'x') || (input == 'y') || (input == 'z')))
			{
				cout << "ERROR: not a lower alphabetical letter." << "\n> ";

				cin.clear();

				cin.ignore(132, '\n');

				cin >> input;
			}



			Search(wordComplete, wordIncomplete, input, wordlength);
			for (int i = 0; i < wordlength; i++)
			{

				if (wordCheck[i] == wordIncomplete[i])
				{
					check = true;
				}
				else
				{
					check = false;
					cout << "Correct, please enter your next guess." << endl;
					break;
				}

			}
			if (check == true)
			{
				cout << "Incorrect guess plese enter a new letter " << endl;
				numguess--;
			}
			cout << "Guesses left " << numguess << endl;
			for (int i = 0; i < wordlength; i++)
			{
				cout << wordIncomplete[i];
			}
			cout << endl;
			for (int i = 0; i < wordlength; i++)
			{
				if (wordComplete[i] == wordIncomplete[i])
				{
					check = true;
				}
				else
				{
					check = false;
					break;
				}

			}
			if (check == true)
			{
				cout << "You have completed the word to choose your next topic press Y or press N to exit the game" << endl;
				cin >> choice;




				if (choice == 'N' || choice == 'n')
				{
					cout << "			Have a nice day!" << endl;
					return 0;
				}
				else if (choice == 'Y' || choice == 'y')
					chosenWord = Menu();
			
				wordlength = chosenWord.length();
				for (int i = 0; i < wordlength; i++)
				{
					wordIncomplete[i] = '-';
					wordComplete[i] = chosenWord[i];

				}
				for (int i = wordlength; i < MAX_WORD_SIZE-1; i++)
				{
					wordIncomplete[i] = ' ';
					wordComplete[i] = ' ';

				}
				numguess = 10;

			}
			if (numguess == 0)
			{
				lives--;
				if (lives == 0)
				{
					cout << "GAME OVER" << endl;
					exit(1);
				}
				cout << "The word was ";
				for (int i = 0; i < wordlength; i++)
				{
					
					cout << wordComplete[i];

				}
					cout << " You lost a life to choose a new topic press Y, press N to exit" << endl;

				cout << "LIVES : " << lives << endl;
				cin >> choice;
				if (choice == 'N' || choice == 'n')
				{
					cout << "			Have a nice day!" << endl;
					return 0;
				}
				else if (choice == 'Y' || choice == 'y')
				chosenWord = Menu();
				numguess = 10;
				wordlength = chosenWord.length();
				for (int i = 0; i < wordlength; i++)
				{
					wordIncomplete[i] = '-';
					wordComplete[i] = chosenWord[i];

				}
				for (int i = wordlength; i < MAX_WORD_SIZE - 1; i++)
				{
					wordIncomplete[i] = ' ';
					wordComplete[i] = ' ';

				}
			}
		}

	}

}

		



void HangmanGreeting(string)
{
	cout << "			|---------------------------------------------|" << endl;
	cout << "			|                   |                         |" << endl;
	cout << "			|                   |                         |" << endl;
	cout << "			|                  (O)                        |" << endl;
	cout << "			|                  /|\\                       |" << endl;
	cout << "			|                   |                         |" << endl;
	cout << "			|                  /|\\                       |" << endl;
	cout << "			|               __________                    |" << endl;
	cout << "			|_______________|________|____________________| " << endl;
	cout << "				    Welcome to Hangman!                      " << endl << endl << endl;
}

void Search(char wordComplete[], char wordIncomplete[], char input, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (wordComplete[i] == input)
		{
			wordIncomplete[i] = wordComplete[i];
		}


	}
}
string Menu()
{
	string categoryName;
	cout << "			Choose a word category by typing the name followed by txt." << endl;
	cout << "			___________________" << endl;
	cout << endl;
	cout << "			1. cars.txt" << endl;
	cout << "			2. foods.txt" << endl;
	cout << "			3. locations.txt" << endl;
	cout << "			4. sports.txt" << endl;
	cout << "			___________________" << endl;
	cin >> categoryName;					//Allows user to enter in the category name
	cout << "			You have chosen " << categoryName << "!" << endl;
	ifstream inputFile;
	inputFile.open(categoryName.c_str(), ios::in);   //Category name file is opened 

	if (inputFile.fail())							//Checks for file opening error
	{
		cout << "			Error opening file.";
		cout << "			Did you add '.txt' ? Didn't think so, genius." << endl;
		exit(1);

	}
	string line;			//Defines a string that will read a line from the .txt file word category

	vector<string> words;   // Creates a vector

	while (getline(inputFile, line))
		words.push_back(line);

 return words[rand() % words.size()];

}