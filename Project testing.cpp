#include <iostream>
using namespace std;
void Search(char[], char[], char, int);
int main()
{

    int lives = 5;
    char wordIncomplete[4] = { '-','-','-','-' };
    char  wordComplete[4] = { 'n','e','p','u' };
    char wordCheck[4];
    char choice;
    char input;
    bool check;
    int numguess = 10;
    int size = 4;

    while (lives > 0)
    {

        while (numguess > 0)
        {
            for (int i = 0; i < size; i++)
            {

                wordCheck[i] = wordIncomplete[i];
            }
            cout << "Enter a lower case letter." << "\n> ";
            cin >> input;
            while (!((input == 'a') || (input == 'b') || (input == 'c') || (input == 'd') || (input == 'e') || (input == 'f') || (input == 'g') || (input == 'h') || (input == 'i') || (input == 'j') || (input == 'k') || (input == 'l') || (input == 'm') || (input == 'n') || (input == 'o') || (input == 'p') || (input == 'q') || (input == 'r') || (input == 's') || (input == 't') || (input == 'u') || (input == 'v') || (input == 'w') || (input == 'x') || (input == 'y') || (input == 'z')))
            {
                cout << "ERROR: not a lower alphabetical letter." << "\n> ";

                cin.clear();

                cin.ignore(132, '\n');

                cin >> input;
            }
            Search(wordComplete, wordIncomplete, input, size);
            for (int i = 0; i < size; i++)
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
                cout << "Incorect guess plese enter a new letter " << endl;
                numguess--;
            }


            cout << "Guesses left " << numguess << endl;
            cout << wordIncomplete << " " << endl;
            for (int i = 0; i < size; i++)
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
                cout << "You have completed the word please choose your next topic" << endl;
                //menu
                //cin >> choice;
                wordIncomplete[0] = '-';
                wordIncomplete[1] = '-';
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

                cout << "You lost a life please choose a new topic" << endl;
                cout << "LIVES : " << lives << endl;

                numguess = 10;
                //Display menu

                cin >> choice;

            }
        }
    }

    return 0;
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
