#include <iostream>
#include <algorithm>

using namespace std;



int findSmallest(const int list[], int numItems);
void printVertical(int num);

int main() {

	int numbers[5] = {10, 1, 3, 4, 5};

	cout << findSmallest(numbers, 5) << endl;


	printVertical(9746);

}


		///////////////////
		// FIND SMALLEST //
		///////////////////

/**
 * Return the smallest item in the list
 * @param  list     array of integers
 * @param  numItems size of the array
 * @return          smallest item in the list
 */

// recursive approach try 1
// int findSmallest(const int list[], int numItems) {
// 	if (numItems == 1) { 	// base case;
// 		return list[0];
// 	} else { //If the last item in the list is smaller than the result of this function call, then we should return the last item in the list. Otherwise, we should return the result of this function call
// 		if (list[numItems - 1] < findSmallest(list, numItems-1)) {
// 			return list[numItems - 1];
// 		} else {
// 			return findSmallest(list, numItems - 1);
// 		}
// 	}
// }


// recursive approach - refactor try 1
// int findSmallest(const int list[], int numItems) {
// 	if (numItems == 1) { return list[0]; }
// 	else {
// 		int smallest = findSmallest(list, numItems - 1);
// 		if (list[numItems - 1] < smallest) { return list[numItems - 1]; }
// 		else { return smallest; }
// 	}
// }


// recursive approach - refactor refactor 1
int findSmallest(const int list[], int numItems) {
	if (numItems == 1) return list[0];
	else 
		return min(list[numItems-1], findSmallest(list, numItems - 1));
}


// iterative approach
// int findSmallest(const int list[], int numItems) {
// 	int smallest = list[0], count = 0;

// 	while (count < numItems) {
// 			if (list[count] < smallest) {
// 				smallest = list[count];	
// 			}
// 		count++;
// 	}


// 	return smallest;
// }


		/////////////////////
		// PRINT VERTICAL  //
		/////////////////////


/**
 * Take a single integer argument and write the integer vertically, one digit per line. 
 * We will assume that the arguement is non-negative. Eg: int = 9746, output:
 * 9
 * 7
 * 4
 * 6
 * @param num integer
 */
void printVertical(int num) {
	if (num < 10) {
		cout << num << endl;
	} else {
		printVertical(num/10);
		cout << num % 10 << endl;
	}
}

