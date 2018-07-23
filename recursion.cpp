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



// iterative approach
int findSmallest(const int list[], int numItems) {
	int smallest = list[0], count = 0;

	while (count < numItems) {
			if (list[count] < smallest) {
				smallest = list[count];	
			}
		count++;
	}


	return smallest;
}
