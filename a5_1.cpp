//
//  a5_1.cpp
//
//  Created by Dan Sajjad on 6/24/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//  Class: CS110B - Programming Fundamentals C++

/*
 
*/


#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
const string PROMPT1 = "Enter the name for score #";
const string PROMPT2 = "Enter the score for score #";

void readDataEntry(string playerNames[], int playerScores[]);
void promptUserForData(string playerNames[], int playerScores[], int &count);
void displayDataInArray(const int list[], int size);

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int findIndexOfSmallest(int list[], int startingIndex, int numItems);


int main() {
    cout << "Starting program" << endl;
    string myFauxPlayers[SIZE] = {"Suzy", "Kim", "Bob", "Armando", "Tim"};
    int myFauxScores[SIZE] = {600, 9900, 1012, 8000, 514};

    
    
    string names[SIZE];
    int scores[SIZE];
    
//    initializeArrays(names, scores, SIZE);
//    findIndexOfSmallest(myFauxScores, 0, SIZE);
//    swap(myFauxScores[1], myFauxScores[4], SIZE);
//    displayData(myFauxPlayers, myFauxScores, SIZE);
    
        sortData(myFauxPlayers, myFauxScores, SIZE);
}

void initializeArrays(string names[], int scores[], int size) {
    int count = 1;

    promptUserForData(names, scores, count);

    while(count < SIZE) {
        count++;
        promptUserForData(names, scores, count);
    }
    
//    displayData(names, scores, SIZE);

//    displayDataInArray(myFauxScores);

    
    
}

void promptUserForData(string playerNames[], int playerScores[], int &count) {
    cout << PROMPT1 << count << ": " << endl;
    cin >> playerNames[count - 1];
    cout << PROMPT2 << count << ": " << endl;
    cin >> playerScores[count - 1];
}

void displayData(const string names[], const int scores[], int size) {
    cout << "Top Scorers: " << endl;
    int count = size - 1;
    while (count >= 0) {
        cout << names[count] << ": " << scores[count] << endl;
        count--;
    }
}


void sortData(string names[], int scores[], int size) {
    displayData(names, scores, size);
    int indexToSwap;
    for (int i = 0; i < size; i++) {
        indexToSwap = findIndexOfSmallest(scores, i, size);
        cout << "i: :" << i <<" Will move: " << indexToSwap << endl;
        swap(scores[i], scores[indexToSwap]);
        swap(names[i], names[indexToSwap]);
    }
    displayData(names, scores, size);

}

//void swap(string someStringArray[], idx1, idx2) {
//
//}


// [0, 1, 2, 3, 4]
//void swap(int someIntArray[], int idx1, int idx2) {
//    int temp = someIntArray[idx1];
//    someIntArray[idx1] = someIntArray[idx2];
//    someIntArray[idx2] = temp;
//}


int findIndexOfSmallest(int list[], int startingIndex, int numItems) {
    int indexOfSmallest = startingIndex;
    
//    displayDataInArray(list, numItems);
    
    
    for (int i = startingIndex + 1; i < numItems; i++) {
//        cout << "i: " << i << " curr: " << list[i] << endl;
        
        if(list[i] < list[indexOfSmallest]) {
            indexOfSmallest = i;
        }
    }
//    cout << "startingIndex: " << startingIndex << " indexOfSmallest: " << indexOfSmallest << endl;
    return indexOfSmallest;
}


//void displayDataInArray(const int list[], int size) {
//
//    int count = 0;
//    while (count < size) {
//        cout << "item: " << list[count] << endl;
//        count++;
//    }
//}