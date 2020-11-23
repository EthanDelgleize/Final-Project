//
//  main.cpp
//  Final Project
//
//  Created by Llendel Reyes on 11/17/20.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int MAX_WORD_SIZE = 21;
const int MAX_WORD_LIST = 5;

int main() {
    
    ifstream inputFile;
    inputFile.open("locations.txt");
    string chosenWord;
    string wordList[MAX_WORD_LIST];
    char wordComplete[MAX_WORD_SIZE]; // char array that holds selected word
    srand(time(0)); // completely random number
    int randomNum = (rand() % 5); // random number generator
    int index = 0;
    
    
    if(inputFile.is_open()){
        for (int i = 0; i < MAX_WORD_LIST; i++) {
            inputFile >> wordList[i]; // put words from file into a list
        }
       
    }
    
    chosenWord = wordList[randomNum];
        
    strcpy(wordComplete, chosenWord.c_str()); // copies string variable into a char array
    
    inputFile.close();
    
    while (wordComplete[index] != NULL) {
        cout << wordComplete[index];
        index++;
    }
    cout << endl;
    
    int numCharacters = chosenWord.length();
    char wordIncomplete[numCharacters]; // char array that keeps track of user guesses
    
    for (int i = 0; i < MAX_WORD_SIZE; i++) {
        if(isalpha(wordComplete[i])){
            wordIncomplete[i] = '-'; // places a dash for every letter in array
        }
        else{
            wordIncomplete[i] = ' '; // places a space character when an element in the array does not have a letter
        }
    }
    
    for (int i = 0; i < numCharacters; i++) {
        cout << wordIncomplete[i];
    }
    
    cout<< endl;
    
    
    return 0;
}
