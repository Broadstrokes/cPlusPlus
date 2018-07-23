#include <iostream>

using namespace std;



int findSmallest(const int list[], int numItems);


int main() {
	cout << "Hello world" << endl;

	int numbers[5] = {10, 1, 3, 4, 5};

	// for (int i = 0; i < 5; i++) {
	// 	cout << numbers[i] << endl; 
	// };

	cout << findSmallest(numbers, 5) << endl;
}


/**
 * Return the smallest item in the list
 * @param  list     array of integers
 * @param  numItems size of the array
 * @return          smallest item in the list
 */

// recursive approach try 1
int findSmallest(const int list[], int numItems) {
	if (numItems == 1) { 	// base case;
		return list[0];
	} else { //If the last item in the list is smaller than the result of this function call, then we should return the last item in the list. Otherwise, we should return the result of this function call
		if (list[numItems - 1] < findSmallest(list, numItems-1)) {
			return list[numItems - 1];
		} else {
			return findSmallest(list, numItems - 1);
		}
	}
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
