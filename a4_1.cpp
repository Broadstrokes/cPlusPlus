//
//  a4_1.cpp
//
//  Created by Dan Sajjad on 6/21/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//  Class: CS110B - Programming Fundamentals C++
//  Teacher: Dave Harden
//

/*
     The program reads five cards from the user,
     then analyzes the cards and prints out the category of hand that they represent.
 
 */


#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 5;


void readNumbers(int list[]);
int numOccurances(const int hand[], int card, int startIndex);
int getSmallest(const int hand[]);
bool hasNextItemInSequence(const int hand[], int current);
int getThreeOfAKindsValue(const int hand[]);

bool  containsPair(const int hand[]);
bool  containsTwoPair(const int hand[]);
bool  containsThreeOfaKind(const int hand[]);
bool  containsStraight(const int hand[]);
bool  containsFullHouse(const int hand[]);
bool  containsFourOfaKind(const int hand[]);







int main() {
    int hand[ARRAY_SIZE];
    
    readNumbers(hand);
    
    if (containsFourOfaKind(hand)) {
        cout << "Four of a kind!" << endl;
    } else if (containsFullHouse(hand)) {
        cout << "Full House!" << endl;
    } else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a kind!" << endl;
    } else if (containsTwoPair(hand)) {
        cout << "Two Pair!" << endl;
    } else if (containsPair(hand)) {
        cout << "Pair!" << endl;
    } else {
        cout << "High Card!" << endl;
    }
}






// post:  returns the number of occurance of a given value in a given array
int numOccurances(const int hand[], int card, int startIndex) {
    int occurances = 0;
    for (int i = startIndex; i < ARRAY_SIZE; i++) {
        
        if (card == hand[i]) {
            occurances++;
        }
    }
    
    return occurances;
}






// post:  returns true if and only if there are one or more pairs in the hand.  Note that
// this function returns false if there are more than two of the same card (and no other pairs).
bool containsPair(const int hand[]) {
    int numPairs = 0;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (numOccurances(hand, hand[i], i) == 2) {
            numPairs++;
        }
    }
    
    
    if (containsThreeOfaKind(hand)) {
        return false;
    } else if (containsFourOfaKind(hand)) {
        return false;
    } else if (numPairs >= 1) {
        return true;
    } else {
        return false;
    }
}







// post: returns true if and only if there are two or more pairs in the hand.
bool containsTwoPair(const int hand[]) {
    int numPairs = 0;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (numOccurances(hand, hand[i], i) == 2) {
            numPairs++;
        }
    }
    if (containsThreeOfaKind(hand)) {
        return false;
    } else if (numPairs >= 2) {
        return true;
    } else {
        return false;
    }
}








// post: returns true if and only if there are one or more three-of-a-kinds in the hand.
bool  containsThreeOfaKind(const int hand[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (containsFourOfaKind(hand)) {
            return false;
        } else if (numOccurances(hand, hand[i], i) == 3) {
            return true;
        }
    }
    
    return false;
}







// post: returns true if there is a pair and a three-of-a-kind in the hand.
bool  containsFullHouse(const int hand[]) {
    int threeOfAKindsValue;
    
    if (containsThreeOfaKind(hand)) {
        threeOfAKindsValue = getThreeOfAKindsValue(hand);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (hand[i] != threeOfAKindsValue) {
                return numOccurances(hand, hand[i], i) == 2;
            }
        }
    }
    
    return false;
}







// post: returns true if there is a four-of-a-kind in the hand.
bool  containsFourOfaKind(const int hand[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (numOccurances(hand, hand[i], i) == 4) {
            return true;
        }
    }
    
    return false;
}








// post: returns true if there are 5 consecutive cards in the hand.
bool  containsStraight(const int hand[]) {
    int current = getSmallest(hand);
    
    if (containsPair(hand)) {
        return false;
    } else {
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (!hasNextItemInSequence(hand, current)) {
                return false;
            } else {
                current = current + 1;
            }
        }
    }
    return true;
}









// post: returns the smallest integer in a given array
int getSmallest(const int hand[]) {
    int smallest = hand[0];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (smallest > hand[i]) {
            smallest = hand[i];
        }
    }
    return smallest;
}








// post: returns a boolean if given an value an array contains the
// next value i.e.  nextValue = currentValue + 1;
bool hasNextItemInSequence(const int hand[], int current) {
    int nextItem = current + 1;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (nextItem == hand[i]) {
            return true;
        }
    }
    return false;
}








// post: returns the integer that appears 3 times in an array
int getThreeOfAKindsValue(const int hand[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (numOccurances(hand, hand[i], i) == 3) {
            return hand[i];
        }
    }
    return -1;
}







// post: put the user input into an array
void readNumbers(int list[]) {
    int number;
    int count = 0;
    
    cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
    cout << "Card 1: ";
    
    cin >> number;
    
    while (count < ARRAY_SIZE) {
        list[count] = number;
        count++;
        
        if (count < ARRAY_SIZE) {
            cout << "Card " << count + 1 << ": ";
            cin >> number;
        }
    };
}






/*
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 5
 Card 2: 3
 Card 3: 2
 Card 4: 2
 Card 5: 2
 Three of a kind!
 Program ended with exit code: 0
 
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 6
 Card 2: 3
 Card 3: 4
 Card 4: 5
 Card 5: 7
 Straight!
 Program ended with exit code: 0
*/
