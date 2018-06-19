//
//  main.cpp
//  a2_1
//
//  Created by Dan Sajjad on 6/17/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//

/*
 Generating a random num: num1 = rand() % (x + 1); where x is the high end of the range.
 */

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const string WIN_OUTPUT = "Congratulations!";
const string LOSE_OUTPUT = "Bust";
const string RESTART_GAME = "Would you like to play again? (y/n): ";
const int JACKPOT = 21;
const int HIGHEST_INCLUSIVE = 10;

int main() {
    srand(static_cast<unsigned>(time(0)));
    int playerScore, randomInt, firstCard, secondCard;
    char play;
    char dealAnotherCard;
    
    play = 'y';

    while (play == 'y') {
        dealAnotherCard = 'y';
        firstCard = (rand() % HIGHEST_INCLUSIVE) + 1;
        secondCard = (rand() % HIGHEST_INCLUSIVE) + 1;
        playerScore = firstCard + secondCard;

        cout << "First cards: " << firstCard << ", " << secondCard << endl;
        cout << "Total: " << playerScore << endl;

        while(playerScore < JACKPOT && dealAnotherCard == 'y') {
            cout << "Do you want another card? (y/n): ";
            cin >> dealAnotherCard;
            
            if (dealAnotherCard == 'y') {
                randomInt = (rand() % HIGHEST_INCLUSIVE) + 1; // generate random int between 1 & 10 inclusive
                playerScore += randomInt;

                cout << "Card: " << randomInt << endl;
                cout << "Total: " << playerScore << endl;
            }
        }

        if (playerScore ==  JACKPOT) {
            cout << WIN_OUTPUT << endl;
        } else if (playerScore > JACKPOT) {
            cout << LOSE_OUTPUT << endl;
        }
        
        cout << RESTART_GAME;
        cin >> play;
    }
    return 0;
}


/*
 First cards: 7, 1
 Total: 8
 Do you want another card? (y/n):  y
 Card: 5
 Total: 13
 Do you want another card? (y/n):  y
 Card: 9
 Total: 22
 Bust
 Would you like to play again? (y/n):  y
 First cards: 10, 1
 Total: 11
 Do you want another card? (y/n):  y
 Card: 5
 Total: 16
 Do you want another card? (y/n):  y
 Card: 3
 Total: 19
 Do you want another card? (y/n):  y
 Card: 9
 Total: 28
 Bust
 Would you like to play again? (y/n):  y
 First cards: 4, 4
 Total: 8
 Do you want another card? (y/n):  y
 Card: 1
 Total: 9
 Do you want another card? (y/n):  y
 Card: 5
 Total: 14
 Do you want another card? (y/n):  y
 Card: 5
 Total: 19
 Do you want another card? (y/n):  y
 Card: 2
 Total: 21
 Congratulations!
 Would you like to play again? (y/n):  y
 First cards: 9, 1
 Total: 10
 Do you want another card? (y/n):  n
 Would you like to play again? (y/n):  n
 */
