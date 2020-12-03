//Category Chooser Function
// Llendeezy
// Kane SVelan
// Jaydon Eppinette

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cctype>
#include <vector>

using namespace std;

const int MAX_WORD_SIZE = 21;
const int MAX_WORD_LIST = 5;
void HangmanGreeting(string);
int main()
{
	string categoryName;
	string userName;
	string chosenWord;
	string wordList[MAX_WORD_LIST];			//String array that holds list of words
	char wordComplete[MAX_WORD_SIZE];		//Char array that holds selected word
	char choice; // Variable that holds the user's choice to begin or try again. 
	char choice2; // Endgame Replay Option

	int randomNum = (rand() % 5);			//Initializes a random number generator
	srand(time(0));							//Creates random number
	int index = 0;							//Sets index to 0
	cout << "			Please enter your username:" << endl;
	cin >> userName;

	cout << endl;
	do
	{
		HangmanGreeting(userName);
		cout << "			Hello " << userName << "!" << endl;
		cout << endl;
		cout << "			Press y if you would like to start a game, or n if you would like to quit." << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
		{
			if (choice == 'N' || choice == 'n')
			{
				cout << "			Have a nice day!" << endl;
				return 0;
			}
			if (choice == 'Y' || choice == 'y')
			{
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

				cout << words[rand() % words.size()] << endl;
			}

		}
		else if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			cout << "			Invalid Input" << endl << endl;
			return 0;
		}
		do
		{
			cout << "			Would you like to play again?" << endl;
			cin >> choice2;
			if (choice2 == 'N' && 'n')
			{
				cout << "			Goodbye!" << endl;
				return 0;
			}
			if (choice2 == 'Y' && 'y')
			{
				cout << "			Have fun!" << endl;
			}
			else if (choice2 != 'Y' && choice2 != 'y' && choice2 != 'N' && choice2 != 'n')
			{
				cout << "			Invalid input!" << endl << endl;
			}
		} while (choice2 != 'Y' && choice2 != 'y' && choice2 != 'N' && choice2 != 'n');
	} 
	while (choice2 != 'N' && choice2 != 'n');

}


void HangmanGreeting(string)
{
cout << "			|---------------------------------------------|" << endl;
cout << "			|                   |                         |" << endl;
cout << "			|                   |                         |" << endl;
cout << "			|                  (O)                        |" << endl;
cout << "			|                  /|\\                        |" << endl;
cout << "			|                   |                         |" << endl;
cout << "			|                  /|\\                        |" << endl;
cout << "			|               __________                    |" << endl;
cout << "			|_______________|________|____________________| " << endl;
cout << "				    Welcome to Hangman!                      "      << endl << endl << endl;
}


	


