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
void swap(int *ptr1, int *ptr2);

int main() {
    //Create two integer variables named x and y
    int x, y;
    
    // Create an int pointer named p1 - Declare a pointer
    int *p1;
    
    //Store the address of x in p1 - "Address Of" Operator
    p1 = &x;
    
    //Use only p1 (not x) to set the value of x to 99 - Dereference/Indirection Operator - Access a variable indirectly
    // To access a variable that a pointer points to, we place the indirection operator in front of a pointer variable
    *p1 = 99;
    
    
    cout << "=========== 5 ==============" << endl;
    //Using cout and x (not p1), display the value of x
    cout << x << endl;
    
    
    cout << "=========== 6 ==============" << endl;
    //Using cout and the pointer p1 (not x), display the value of x
    cout << *p1 << endl;
    
    //Store the address of y into p1
    p1 = &y;
    //Use only p1 (not y) to set the value of y to -300
    *p1 = -300;
    
    cout << "=========== 9 ==============" << endl;
    //Create two new variables: an int named temp, and an int pointer named p2.
    int temp;
    int *p2;
    //Make p2 point to x.
    p2 = &x;

    cout << "=========== 10 ==============" << endl;
    //Use only temp, p1, and p2 (not x or y) to swap the values in x and y (this will take a few statements. Don't use a swap function)
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
    
    cout << "=========== 12 ==============" << endl;
    //Invoke the function twice: once with the address of x as the argument, and once with the address of y. Use x or y for the argument (not p1 or p2)
    
    noNegatives(&x);
    noNegatives(&y);

    cout << "=========== 13 ==============" << endl;
    //Use p2 to display the values in x and y (this will require both assignment statements and cout statements). You can use x and y in assignment statements, but not in your cout statement. this should produce the output
    p2 = &x;
    cout << "x is : " << *p2 << endl;
    
    p2 = &y;
    cout << "y is : " << *p2 << endl;
    cout << "=========== 14 ==============" << endl;
    //Create an int array named 'a' with two elements.
    int a[2];
    //Make p2 point to the first element of a.
    //    p2 = &a[0];
    p2 = a;
    
    cout << "=========== 15 ==============" << endl;
    //Use only p2 and x (not a) to initialize the first element of a with the value of x.
    p2[0] = x;
    
    cout << "=========== 16 ==============" << endl;
    //Use only p2 and y (not a) to initialize the second element of a with the value of y. Leave p2 pointing to the first element of a. Don't use pointer arithmetic. Hint: don't forget that pointers and arrays are the same thing.
    p2[1] = y;
    
    cout << a[0] << endl;
    cout << a[1] << endl;
    
    
    cout << "=========== 17 ==============" << endl;
    // Using cout and p2 only, display the address of the first element in a.
    cout << &p2[0] << endl;
    
    
    cout << "=========== 18 ==============" << endl;
    //Using cout and p2 only, display the address of the second element in a. Leave p2 pointing to the first element of a. Don't use pointer arithmetic.
    cout << &p2[1] << endl;
    
    
    cout << "=========== 19 ==============" << endl;
    //Use p1, p2, and temp to swap the values in the two elements of array 'a'. (first point p1 at a[0], then point p2 at a[1], then do not use "a" again. After this the swapping steps should look very similar to step 10. Don't use a swap function.)
    p1 = &a[0];
    p2 = &a[1];
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "=========== 20 ==============" << endl;
    //Display the values of the two elements. (The first element should be 99, the second 0).
    cout << a[0] << endl; // 99
    cout << a[1] << endl; // 0

    cout << "=========== 22 ==============" << endl;
    //Invoke your swap function with the addresses of x and y (using the address-of operator), then print their values. (x should be 99, y should be 0).
    swap(&x, &y);
    cout << x << endl; // 99
    cout << y << endl; // 0

    cout << "=========== 23 ==============" << endl;
    //Invoke your swap function with the address of the two elements in array 'a', then print their values. (a[0] should be 0, a[1] should be 99)
    swap(&a[0], &a[1]);
    cout << a[0] << endl; // 0
    cout << a[1] << endl; // 99

    
}

//Write a function with the following signature: void noNegatives(int *x). The function should accept the address of an int variable. If the value of this integer is negative then it should set it to zero
void noNegatives(int *x) {
    if (*x < 0) {
        *x = 0;
    }
}


//Write a function named 'swap' that accepts two pointers to integers as arguments, and then swaps the contents of the two integers. Do not use any reference parameters.

void swap(int *ptr1, int *ptr2) {
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

