// Hangman validation check.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	char input;

	cout << "Enter a lower case letter." << "\n> ";
	cin >> input;
	
	while (!((input == 'a')||(input == 'b') || (input == 'c') || (input == 'd') || (input == 'e') || (input == 'f') || (input == 'g') || (input == 'h') || (input == 'i') || (input == 'j') || (input == 'k') || (input == 'l') || (input == 'm') || (input == 'n') || (input == 'o') || (input == 'p') || (input == 'q') || (input == 'r') || (input == 's') || (input == 't') || (input == 'u') || (input == 'v') || (input == 'w') || (input == 'x') || (input == 'y') || (input == 'z')))
	{
		cout << "ERROR: not a lower alphabetical letter." << "\n> ";

		cin.clear();

		cin.ignore(132,'\n');

		cin >> input;
	}	
}

