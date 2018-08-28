#include <iostream>
#include <string>
using namespace std;

int calculatePowers(int base, int power);
int loopSum(int start, int end);

int main() {
  string myString= "Hello world";
  cout << myString << endl;

  int x = calculatePowers(3, 10);
  cout << "x: " << x;

  int y = loopSum(1, 9);
  cout << "y: " << y;
}

int calculatePowers(const int base, const int power) {
  int answer = 1;
  int currentPower = 1;
  while (currentPower <= power) {
    answer = answer * base;
    currentPower++;
  }
  return answer;
}

int loopSum(const int start, const int end) {
  int answer = 0;
  for (int i = start; i < end; i++) {
    answer += i;
  }

  return answer;
}