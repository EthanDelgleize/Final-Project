
//
//¦¦+¦¦¦¦+¦¦¦¦¦¦+¦¦¦¦+¦¦¦¦+¦¦¦¦¦¦¦+¦¦¦¦+¦¦¦¦¦¦+¦¦¦¦¦¦+¦¦¦¦+¦¦¦¦+
//¦¦¦¦¦¦¦¦¦¦+--¦¦+¦¦¦¦+¦¦¦¦¦¦+----+¦¦¦¦¦+¦¦¦¦¦¦¦¦+--¦¦+¦¦¦¦+¦¦¦¦
//¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦+¦¦¦¦¦¦¦¦¦¦+¦¦¦+¦¦¦¦+¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦+¦¦¦
//¦¦+--¦¦¦¦¦+--¦¦¦¦¦¦+¦¦¦¦¦¦¦¦¦¦+¦¦+¦¦¦+¦¦++¦¦¦¦¦+--¦¦¦¦¦¦+¦¦¦¦¦
//¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦¦¦+¦¦¦¦¦¦++¦¦¦¦+-+¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦+¦¦¦¦
//+-+¦¦+-++-+¦¦+-++-+¦¦+--+¦+-----+¦+-+¦¦¦¦¦+-++-+¦¦+-++-+¦¦+--+


//                      ~Created by~
//                    
//                    Ethan Delgleize
//                     Aaron Martinez
//                     Llendel Reyes
//                      Kane SVelan
//                    Jaydon Eppinette
// 


#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cctype>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace std;

const int MAX_WORD_SIZE = 21;
const int MAX_WORD_LIST = 5;

void Search(char[], char[], char, int);
void HangmanGreeting(string);
void load();
void gotoxy();

string Menu();

int main()
{
    string categoryName;
    string userName;
    string chosenWord;
    string wordList[MAX_WORD_LIST];            //String array that holds list of words
    char wordComplete[MAX_WORD_SIZE];        //Char array that holds selected word
    char wordIncomplete[MAX_WORD_SIZE];
    char wordCheck[MAX_WORD_SIZE];
    char choice; // Variable that holds the user's choice to begin or try again.

    char input;
    int lives = 5;
    int numguess = 10;
    int wordlength;
    int randomNum = (rand() % 5);            //Initializes a random number generator
    srand(time(0));                            //Creates random number
    int index = 0;                            //Sets index to 0
    bool check;


    //******LOADING SCREEN****************************************
    //mess with this to change screen color
    system("color 0f");
    //    0 = Black       8 = Gray
    //    1 = Blue        9 = Light Blue
    //    2 = Green       A = Light Green
    //    3 = Aqua        B = Light Aqua
    //    4 = Red         C = Light Red
    //    5 = Purple      D = Light Purple
    //    6 = Yellow      E = Light Yellow
    //    7 = White       F = Bright White
    load();
    cout << endl << endl << endl << endl << endl << endl << endl;
    //************************************************************


    cout << "            Please enter your username:" << endl;
    cin >> userName;

    cout << endl;
    HangmanGreeting(userName);
    cout << "            Hello " << userName << "!" << endl;
    cout << endl;
    cout << "            Press y if you would like to start a game, or n if you would like to quit." << endl;
    do {
        cin >> choice;
        if (choice == 'N' || choice == 'n')
        {
            cout << "            Have a nice day!" << endl;
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
            break;
        }
        else
            cout << "Invalid input please enter Y or N" << endl;
    } while (choice != 'y' || choice != 'n' || choice == 'Y' || choice == 'N');
    
{

}
    while (lives > 0)
    {
        while (numguess > 0)
        {
            for (int i = 0; i < wordlength; i++)
            {

                wordCheck[i] = wordIncomplete[i];
            }
            cout << endl;
            cout << endl;
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
                    cout << endl;
                    cout << endl;
                    cout << "Correct, please enter your next guess." << endl;
                    break;
                }

            }
            if (check == true)
            {
                cout << endl;
                cout << endl;
                cout << "Incorrect guess please enter a new letter. " << endl;
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
                cout << endl;
                cout << endl;
                cout << "Congratulations You Win!" << endl;
                cout << "You have completed the word to choose your next topic press Y or press N to exit the game" << endl;
                do {
                    cin >> choice;

                    if (choice == 'N' || choice == 'n')
                    {
                        cout << "            Have a nice day!" << endl;
                        return 0;
                    }
                    else if (choice == 'Y' || choice == 'y')
                    {
                        chosenWord = Menu();

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
                        break;
                    }
                    else
                        cout << "invalid input please enter Y or N" << endl;
                      
                } while (choice != 'y' || choice != 'n' || choice == 'Y' || choice == 'N');
                numguess = 10;

            }
            if (numguess == 0)
            {
                lives--;
                if (lives == 0)
                {
                    cout << endl;
                    cout << endl;
                    cout << "GAME OVER!JaydonJaydon" << endl;
                    exit(1);
                }
                cout << "The word was ";
                for (int i = 0; i < wordlength; i++)
                {

                    cout << wordComplete[i];

                }
                cout << endl;
                cout << endl;
                cout << " You lost a life to choose a new topic press Y, press N to exit" << endl;

                cout << "LIVES : " << lives << endl;
                do{
                cin >> choice;
                if (choice == 'N' || choice == 'n')
                {
                    cout << "            Have a nice day!" << endl;
                    return 0;
                }
                else if (choice == 'Y' || choice == 'y')
                {
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
                    break;
                }
                else
                    cout << "Invlaid intput please enter Y or N" << endl;
             } while (choice != 'y' || choice != 'n' || choice == 'Y' || choice == 'N');
            }
        }

    }

}
string Menu()
{

    while (1) {
        ifstream inputFile;
        int categoryChoice;
        string categoryName;


        cout << "            Choose a word category by typing the number category." << endl;
        cout << "            ___________________" << endl;
        cout << endl;
        cout << "            1. Cars" << endl;
        cout << "            2. Foods" << endl;
        cout << "            3. Locations" << endl;
        cout << "            4. Sports" << endl;
        cout << "            ___________________" << endl;
        cin >> categoryChoice;                    //Allows user to enter in the category name

        if (categoryChoice == 1) {
            inputFile.open("cars.txt"); // opens cars txt file
            categoryName = "Cars";
        }
        else if (categoryChoice == 2) {
            inputFile.open("foods.txt"); // opens foods txt file
            categoryName = "Foods";
        }
        else if (categoryChoice == 3) {
            inputFile.open("locations.txt"); // opens locations txt file
            categoryName = "Locations";
        }
        else if (categoryChoice == 4) {
            inputFile.open("sports.txt"); // opens sports txt file
            categoryName = "Sports";
        }
        else if (inputFile.fail()) {
            cout << "            Error opening file.";

            exit(1);
        }
        else {
            cout << "Wrong input. Try again.";
            continue; // goes onto next iteration
        }
        cout << "            You have chosen " << categoryName << "!" << endl;

        vector<string> words;                   // Creates a vector

        string line;                            //Defines a string that will read a line from the .txt file word category

        while (getline(inputFile, line))        //reads line from inputFile
            words.push_back(line);

        return words[rand() % words.size()];    //Returns a random word, stored in words vector

    }

}

//*****************************
//Function: HangmanGreeting   *
//Purpose: Greeting the users *
//*****************************

void HangmanGreeting(string)
{
    cout << "            |---------------------------------------------|" << endl;
    cout << "            |                   |                         |" << endl;
    cout << "            |                   |                         |" << endl;
    cout << "            |                  (O)                        |" << endl;
    cout << "            |                  /|\\                        |" << endl;
    cout << "            |                   |                         |" << endl;
    cout << "            |                  / \\                        |" << endl;
    cout << "            |               __________                    |" << endl;
    cout << "            |_______________|________|____________________| " << endl;
    cout << "                    Welcome to Hangman!                      " << endl << endl << endl;
}

//*************************************
//Function: Search                    *
//Purpose: searches for complete word *
//*************************************

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
//****************************************
//Function: Loading Screen from YouTube  *
//Purpose: looks cool                    *
//****************************************
void gotoxy(int x, int y)
{
    COORD d;
    d.X = x;
    d.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}
void load()
{
    char a = 219;
    gotoxy(36, 14);
    cout << "Loading..." << endl;
    gotoxy(30, 16);
    for (int r = 1; r <= 20; r++)
    {
        for (int q = 0; q <= 100000000; q++);
        cout << a;
    }
}
