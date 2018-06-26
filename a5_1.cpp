//
//  main.cpp
//  a5_1
//
//  Created by Dan Sajjad on 6/24/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//

/*
    The program records high-score data for some game. The program asks the user to enter five names, and five scores. It stores the data in memory, and prints it back out sorted by score (highest to lowest).

    The data is stored in two arrays: 1) an array of strings named names, and 2) an array of ints named scores. These arrays are declared in the main function.   

    All user input is done in the function initializeArrays. 
    sortData function sorts both arrays in descending order by score.
    displayData function displays the final list of names and scores.
*/






#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
const string PROMPT1 = "Enter the name for score #";
const string PROMPT2 = "Enter the score for score #";

void promptUserForData(string playerNames[], int playerScores[], int &count);
void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);
int findIndexOfLargest(int list[], int startingIndex, int numItems);






int main() {
    string names[SIZE];
    int scores[SIZE];
    
    initializeArrays(names, scores, SIZE);
    sortData(names, scores, SIZE);
    displayData(names, scores, SIZE);
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

    while (count < SIZE) {
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
    cout << "Top Scorers: " << endl;
    int count = 0;
    while (count < SIZE) {
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
    Enter the name for score #1:  suzy
    Enter the score for score #1:  600
    Enter the name for score #2:  kim
    Enter the score for score #2:  9900
    Enter the name for score #3:  bob
    Enter the score for score #3:  1012
    Enter the name for score #4:  armando
    Enter the score for score #4:  8000
    Enter the name for score #5:  tim
    Enter the score for score #5:  514
    Top Scorers: 
    kim: 9900
    armando: 8000
    bob: 1012
    suzy: 600
    tim: 514



    Enter the name for score #1:  Mike
    Enter the score for score #1:  600
    Enter the name for score #2:  Cathy
    Enter the score for score #2:  200
    Enter the name for score #3:  Tim
    Enter the score for score #3:  300
    Enter the name for score #4:  Liza
    Enter the score for score #4:  200
    Enter the name for score #5:  Felix
    Enter the score for score #5:  -400
    Top Scorers: 
    Mike: 600
    Tim: 300
    Liza: 200
    Cathy: 200
    Felix: -400

    Enter the name for score #1:  a
    Enter the score for score #1:  5
    Enter the name for score #2:  b
    Enter the score for score #2:  3
    Enter the name for score #3:  c
    Enter the score for score #3:  -4
    Enter the name for score #4:  d
    Enter the score for score #4:  -1
    Enter the name for score #5:  e
    Enter the score for score #5:  2
    Top Scorers: 
    a: 5
    b: 3
    e: 2
    d: -1
    c: -4
*/
