#include <iostream>
using namespace std;

int findRemainder(int dividend, int divisor);

int main() {
 cout << findRemainder(5, 2) << endl; //1
 cout << findRemainder(20, 2) << endl; //0
 cout << findRemainder(5, 3) << endl;//2
 cout << findRemainder(29, 3) << endl; 
 cout << findRemainder(47, 8) << endl; 
}


// int remainder;

int findRemainder(int dividend, int divisor) {
  if (dividend == divisor) {
    return 0;
  } else if (dividend < divisor) {
    return dividend;  
  }
    
  return findRemainder(dividend - divisor, divisor);
}