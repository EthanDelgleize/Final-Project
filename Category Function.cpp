//Category Chooser Function
//
//Kane SVelan
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>

using namespace std;

const int MAX_WORD_SIZE = 21;
const int MAX_WORD_LIST = 5;

int main()
{
	string categoryName;
	string userName;
	string chosenWord;
	string wordList[MAX_WORD_LIST];			//String array that holds list of words
	char wordComplete[MAX_WORD_SIZE];		//Char array that holds selected word


	int randomNum = (rand() % 5);			//Initializes a random number generator
	srand(time(0));							//Creates random number
	int index = 0;							//Sets index to 0

	cout << "     Welcome to Hangman!     " << endl;
	cout << "Please enter your username:" << endl;
	cin >> userName;

	cout << endl;
	cout << "Hello " << userName << "!" << endl;
	cout << endl;

	cout << "Choose a word category:" << endl;
	cout << "______________" << endl;
	cout << endl;
	cout << "cars.txt" << endl;
	cout << "foods.txt" << endl;
	cout << "locations.txt" << endl;
	cout << "sports.txt" << endl;
	cout << "______________" << endl;

	cin >> categoryName;							//Allows user to enter in the category name
	cout << "You have chosen " << categoryName << "!" << endl;

	ifstream inputFile;
	inputFile.open(categoryName.c_str(), ios::in);   //Category name file is opened to be read 

	if (inputFile.fail())							//Checks for file opening error
	{
		cout << "Error opening file.";
		cout << "Did you add '.txt' ? Didn't think so, genius." << endl;
		exit(1);
	}

	string line;			//line from category .txt file
	
	vector<string> categoryWord;		// vector to store category words from .txt file

	while (getline(inputFile, line))	//reads a line from .txt file
		words.push_back(line);			//adds a text line to be read

	cout << categoryWord[rand() % words.size()] << endl;	//Displays random word from category .txt file
															

	return 0;
}
