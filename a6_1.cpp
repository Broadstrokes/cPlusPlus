//
//  main.cpp
//  a6_1
//
//  Created by Dan Sajjad on 6/25/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.

/*
 */


#include <iostream>
#include <string>
using namespace std;

void noNegatives(int *x);


int main() {
    //Create two integer variables named x and y
    int x, y;
    
    // Create an int pointer named p1
    int *p1;
    
    //Store the address of x in p1
    p1 = &x;
    
    //Use only p1 (not x) to set the value of x to 99
    *p1 = 99;
    
    //Using cout and x (not p1), display the value of x
    cout << x << endl;
    
    //Using cout and the pointer p1 (not x), display the value of x
    cout << *p1 << endl;
    
    //Store the address of y into p1
    p1 = &y;
    //Use only p1 (not y) to set the value of y to -300
    *p1 = -300;
    
    cout << "y: " << y << endl;
    //    cout << "*p1: " << *p1 << endl;
    cout << "x: " << x  << endl;

    //Create two new variables: an int named temp, and an int pointer named p2. Make p2 point to x.
    int temp;
    int *p2;
    
    p2 = &x;

        cout << "=========== 10 ==============" << endl;
    //Use only temp, p1, and p2 (not x or y) to swap the values in x and y (this will take a few statements. Don't use a swap function)
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    cout << "y: " << y << endl;
//    cout << "*p1: " << *p1 << endl;
    cout << "x: " << x  << endl;
    
    //Invoke the function twice: once with the address of x as the argument, and once with the address of y. Use x or y for the argument (not p1 or p2)
    
    
    cout << "=========== 12 ==============" << endl;
    noNegatives(&x);
    cout << "x: " << x  << endl;
    noNegatives(&y);
    cout << "y: " << y << endl;

    cout << "=========== 13 ==============" << endl;

    p2 = &x;
    cout << "x is : " << *p2 << endl;
    p2 = &y;
    cout << "y is : " << *p2 << endl;
    
    // Create an int array named 'a' with two elements. Make p2 point to the first element of a.

    int a[2];
    p2 = &a[0];
    
    cout << "=========== 15 ==============" << endl;
    //Use only p2 and x (not a) to initialize the first element of a with the value of x.
    *p2 = x;
    
    cout << a[0] << endl;
    
    //Use only p2 and y (not a) to initialize the second element of a with the value of y. Leave p2 pointing to the first element of a. Don't use pointer arithmetic. Hint: don't forget that pointers and arrays are the same thing.
    
    *p2 = y;
    p2 = &a[1];
    
}
//Write a function with the following signature: void noNegatives(int *x). The function should accept the address of an int variable. If the value of this integer is negative then it should set it to zero
void noNegatives(int *x) {
    if (*x < 0) {
        *x = 0;
    }
}


