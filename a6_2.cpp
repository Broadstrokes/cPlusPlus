//  a6_2.cpp
//  Created by Dan Sajjad on 6/26/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.

/*
 The program records high-score data for some game. The program asks the user to enter five names, and five scores. It stores the data in memory, and prints it back out sorted by score (highest to lowest).
 
 The data is stored in two dynamic arrays: 1) an array of strings named names, and 2) an array of ints named scores. These arrays are declared in the main function.
 
 All user input is done in the function initializeArrays.
 sortData function sorts both arrays in descending order by score.
 displayData function displays the final list of names and scores.
 */


// DYNAMIC MEMORY - DYNAMIC ARRAYS




#include <iostream>
#include <string>
using namespace std;

const string PROMPT0 = "How many scores will you enter?: ";
const string PROMPT1 = "Enter the name for score #";
const string PROMPT2 = "Enter the score for score #";

void promptUserForData(string playerNames[], int playerScores[], int &count);
void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);
int findIndexOfLargest(int list[], int startingIndex, int numItems);






int main() {
    int size;
    cout << PROMPT0;
    cin >> size;
    
    string *names = new string[size];
    int *scores = new int[size];
    
    initializeArrays(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);
    
    delete [] names;
    delete [] scores;
}






/**
 * All user input is done in the function initializeArrays. Loops and
 * continues to prompt users for data
 *
 * @param names  string array - empty array to store player names
 * @param scores int array - empty array to store player scores
 * @param size   int - indicates the size of the arrays
 */
void initializeArrays(string names[], int scores[], int size) {
    int count = 1;
    
    promptUserForData(names, scores, count);
    
    while (count < size) {
        count++;
        promptUserForData(names, scores, count);
    }
}






/**
 * This is a helper function used by initializeArrays to prompt the user
 to input player names and their scores. As the program receives the data,
 it is stored in the respective arrays
 
 * @param playerNames  string array - empty array to store player names
 * @param playerScores int array - empty array to store player scores
 * @param count        int - indicates the size of the arrays
 */
void promptUserForData(string playerNames[], int playerScores[], int &count) {
    cout << PROMPT1 << count << ": ";
    cin >> playerNames[count - 1];
    cout << PROMPT2 << count << ": ";
    cin >> playerScores[count - 1];
}







/**
 * Displays sorted player scores on the screen
 * @param names  string array - sorted array of player names
 * @param scores int array - sorted array of player scores
 * @param size   int - indicates the size of the arrays
 */
void displayData(const string names[], const int scores[], int size) {
    int count = 0;
    
    cout << "Top Scorers: " << endl;
    
    while (count < size) {
        cout << names[count] << ": " << scores[count] << endl;
        count++;
    }
}







/**
 * Sorts player scores in a descending order and their respective names
 * in the same order
 *
 * @param names  string array - unsorted array of player names
 * @param scores int array - unsorted array of player scores
 * @param size   int - indicates the size of the arrays
 */
void sortData(string names[], int scores[], int size) {
    int indexToSwap;
    
    for (int i = 0; i < size; i++) {
        indexToSwap = findIndexOfLargest(scores, i, size);
        swap(scores[i], scores[indexToSwap]);
        swap(names[i], names[indexToSwap]);
    }
}






/**
 * Given an array of integers, returns the index of the largest
 * integer
 *
 * @param  list          int array - indicates list of scores
 * @param  startingIndex int - indicates the index after which to start searching
 * @param  numItems      int - indicates the size of the array
 * @return               int - indicates the index of the largest integer after the starting index
 */
int findIndexOfLargest(int list[], int startingIndex, int numItems) {
    int indexOfLargest = startingIndex;
    
    for (int i = startingIndex + 1; i < numItems; i++) {
        if (list[i] > list[indexOfLargest]) {
            indexOfLargest = i;
        }
    }
    
    return indexOfLargest;
}






/*
     How many scores will you enter?: 3
     Enter the name for score #1: a
     Enter the score for score #1: 20
     Enter the name for score #2: b
     Enter the score for score #2: 10
     Enter the name for score #3: c
     Enter the score for score #3: 80
     Top Scorers:
     c: 80
     a: 20
     b: 10
     Program ended with exit code: 0
 
 
     How many scores will you enter?: 6
     Enter the name for score #1: a
     Enter the score for score #1: 50
     Enter the name for score #2: b
     Enter the score for score #2: 20
     Enter the name for score #3: c
     Enter the score for score #3: 80
     Enter the name for score #4: d
     Enter the score for score #4: -50
     Enter the name for score #5: e
     Enter the score for score #5: 70
     Enter the name for score #6: f
     Enter the score for score #6: -40
     Top Scorers:
     c: 80
     e: 70
     a: 50
     b: 20
     f: -40
     d: -50
     Program ended with exit code: 0
 */
