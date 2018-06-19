//
//  main.cpp
//  a3_1
//
//  Created by Dan Sajjad on 6/17/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//


/*
 Write a program that plays a number guessing game with a Human user. The Human user will think of a number between 1 and 100, inclusive. The program will make guesses and the user will tell the program to guess higher or lower.
 
 h = high;
 l = low;
 c = correct;
 
 A sample run of the program might look like this:
 
 Ready to play (y/n)? y
 Think of a number between 1 and 100.
 Is it 50 (h/l/c)? h
 Is it 75 (h/l/c)? h
 Is it 88 (h/l/c)? l
 Is it 81 (h/l/c)? c
 Great! Do you want to play again (y/n)? y
 Think of a number between 1 and 100.
 Is it 50 (h/l/c)? l
 Is it 25 (h/l/c)? h
 Is it 37 (h/l/c)? c
 Great! Do you want to play again (y/n)? n
*/


#include <iostream>
#include <string>
using namespace std;

int getMidpoint(int low, int high);
void playOneGame();
void getUserResponseToGuess(int guess, char &result);

const string RESTART_GAME_MESSAGE = "Great! Do you want to play again (y/n)? ";
const string GAME_GREETING_MESSAGE = "Ready to play (y/n)? ";
const string ASK_USER_TO_GUESS_MESSAGE = "Think of a number between 1 and 100.";


int main() {
    char response;

    cout << GAME_GREETING_MESSAGE;
    cin >> response;
    
    while (response == 'y') {
        playOneGame();

        cout << RESTART_GAME_MESSAGE;
        cin >> response;
    }
}






void getUserResponseToGuess(int guess, char &result) {
    cout << "Is it "<< guess << " (h/l/c)? ";
    cin >> result;
}






void playOneGame() {
    int low, high, mid;
    char result = '\0';
    
    low = 1;
    high = 100;
    mid = getMidpoint(low, high);
    
    cout << ASK_USER_TO_GUESS_MESSAGE << endl;
    getUserResponseToGuess(mid, result);
    
    while (result != 'c') {
        if (result == 'h') {
            low = mid + 1;
        } else if (result == 'l') {
            high = mid - 1;
        }
        
        mid = getMidpoint(low, high);
        
        getUserResponseToGuess(mid, result);
    }
}






int getMidpoint(int low, int high) {
    return (high + low) / 2;
}






/*
 Ready to play (y/n)? y
 Think of a number between 1 and 100.
 Is it 50 (h/l/c)? h
 Is it 75 (h/l/c)? h
 Is it 88 (h/l/c)? l
 Is it 81 (h/l/c)? h
 Is it 84 (h/l/c)? h
 Is it 86 (h/l/c)? l
 Is it 85 (h/l/c)? c
 Great! Do you want to play again (y/n)? y
 Think of a number between 1 and 100.
 Is it 50 (h/l/c)? l
 Is it 25 (h/l/c)? l
 Is it 12 (h/l/c)? h
 Is it 18 (h/l/c)? h
 Is it 21 (h/l/c)? h
 Is it 23 (h/l/c)? c
 Great! Do you want to play again (y/n)? n
 Program ended with exit code: 0
*/
