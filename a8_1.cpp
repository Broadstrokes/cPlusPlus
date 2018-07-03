/*
 The program records high-score data for some game. The program asks the user to enter five names, and five scores. It stores the data in memory, and prints it back out sorted by score (highest to lowest).
 
 All user input is done in the function initializeArrays.
 sortData function sorts both arrays in descending order by score.
 displayData function displays the final list of names and scores.
 */



/*
    cin << doesn't add the newline.  It leaves it in the input stream.  
    So if the next input is cin.getline() with the default delimiter of newline, 
    that getline() will execute without bringing in any "real" characters, 
    because the first thing it sees in the input stream is the delimiter.  
    cin.ignore() gets that newline out of the input stream, and then getline() behaves as expected.

    char name[24];
    int score;

    cin >> score;
    cin.getline(name, 24);
    Without cin.ignore() after cin >> score;  the newline entered by the user when 
    they enter the score is left in the input stream.  The default terminator character 
    for getline is newline.  Since the first character in the input stream after 
    cin >> score; executes is a newline, getline() immediately sees that character and 
    assumes that it has no more characters to read.

    cin.ignore() is ignoring (consuming without doing anything) the newline that is at 
    the beginning of the input stream after cin >> score; executes, so that getline() 
    can see the characters following that ignored newline.
 */


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const string PROMPT0 = "How many scores will you enter?: ";
const string PROMPT1 = "Enter the name for score #";
const string PROMPT2 = "Enter the score for score #";

// Declare struct
struct highscore {
    int score;  // player's score
    char name[24]; // player's name
};



void initializeData(highscore scores[], int size);
void sortData(highscore scores[], int size);
void displayData(const highscore scores[], int size);
int findIndexOfLargest(
    const highscore scores[],
    int startingIndex, 
    int numItems
);



int main() {
    int size; // number of players
    
    cout << PROMPT0;
    cin >> size;
    
    /*
        Define an array with size number of elements. 
        Each element is a highscore struct
     */
    highscore scores[size]; 
    
    initializeData(scores, size);
    sortData(scores, size);
    displayData(scores, size);
}

/**
 * All user input is done in this function. The function 
 * loops and continues to prompt user for data that gets
 * stored in individual structs stored in an array.
 * 
 * @param scores an array holding structs with 
 *               name and score properties
 *               
 * @param size   size of the array holding the structs
 */
void initializeData(highscore scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << PROMPT1 << (i + 1) << ": ";
        cin >> scores[i].name;
        cout << PROMPT2 << (i + 1) << ": ";
        cin >> scores[i].score;
    }
}
/**
 * Sorts the array holding structs based on score
 * in ascending order
 * 
 * @param scores an array holding structs with 
 *               name and score properties
 *               
 * @param size   size of the array holding the structs
 */
void sortData(highscore scores[], int size) {
    int indexToSwap;
    
    for (int i = 0; i < size; i++) {
        indexToSwap = findIndexOfLargest(scores, i, size);
        swap(scores[i], scores[indexToSwap]);
    }
 }


/**
 * Displays player names and scores in 
 * the array holding the structs
 * 
 * @param scores an array holding structs with 
 *               name and score properties
 *               
 * @param size   size of the array holding the structs
 */
void displayData(const highscore scores[], int size) {
    
    cout << "Top Scorers: " << endl;
    
    for (int i = 0; i < size; i++) {
       cout << scores[i].name << ": " << scores[i].score << endl;
    }
}

/**
 * Finds the index of the struct with the highest score
 * in a given array
 * 
 * @param scores    an array holding structs with 
 *                  name and score properties
 *               
 * @param  startingIndex indicates the index after which to start searching
 * 
 * @param size   size of the array holding the structs
 * @return int   index of the struct with the highest score 
 *               beyond the starting index
 */
int findIndexOfLargest(
    const highscore scores[],
    int startingIndex, 
    int numItems
) {
    int indexOfLargest = startingIndex;
    
    for (int i = startingIndex + 1; i < numItems; i++) {
        if (scores[i].score > scores[indexOfLargest].score) {
            indexOfLargest = i;
        }
    }
    return indexOfLargest;
}




/*
     How many scores will you enter?: 5
     Enter the name for score #1: kyle
     Enter the score for score #1: 200
     Enter the name for score #2: john
     Enter the score for score #2: 100
     Enter the name for score #3: cathy
     Enter the score for score #3: -400
     Enter the name for score #4: bee
     Enter the score for score #4: 1000
     Enter the name for score #5: tim
     Enter the score for score #5: -50
     Top Scorers:
     bee: 1000
     kyle: 200
     john: 100
     tim: -50
     cathy: -400
     Program ended with exit code: 0
 */
