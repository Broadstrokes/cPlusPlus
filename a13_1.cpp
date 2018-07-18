//
//  mystring.cpp
//  a13_1
//
//  Created by Dan Sajjad on 7/14/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.

#include "mystring.h"
#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"

using namespace std;



namespace cs_mystring {
    
    // DEFAULT CONSTRUCTOR
    MyString::MyString() {
        str = new char[1];
        strcpy(str, "");
    }
    
    
    
    
    
    
    // CONSTRUCTOR 2
    MyString::MyString(const char *inString) {
        str = new char[strlen(inString) + 1];
        strcpy(str, inString);
    }
    
    
    
    
    
    
    // DEEP COPY CONSTRUCTOR
    // this is needed because if we make a function call eg: f(item1)
    // we are passing item1 by value so c++ makes a copy
    // but it makes a shallow copy, the str property of copied object will point to item1s address
    // we want to make a deep copy so that whatever item1's str is holding we copy that over
    // we have to make sure that the param is pass by reference not pass by value
    // when we are making this copy constructor because when we call using pass by value
    // this function we are writing will get called and we'll get an infinite recursive
    
    // Copy constructor is used in 3 different situations in c++
        // 1. pass by value
        // 2. when a value function returns an inventory object
        // 3. when you initialize an object
            // Eg: invItem item1 = item3; this doesn't call the assignment operator
            // In cpp int x = 7 is the same a saying int x(7);
            // therefore invItem item1 = item3 is same as invItem item1(item3);
    MyString::MyString(const MyString& deepCopyMe) {
        // never use delete in a constructor
        // unlike the assignment operator we a creating a new object
        // str is not pointing to anything, thus delete [] str is not needed
        // there is nothing to delete
        str = new char[strlen(deepCopyMe.str) + 1];
        strcpy(str, deepCopyMe.str);
        
        // we don't need to return anything as constructors don't return anything
    }
    
    
    
    
    
    // In java dallocation of memory on head is done automatically
    // In c++ you have to do it
    // thus when f(item1) is called a copy of item1 is made on the stack inside the function
    // item1's copy is delete once the function is over but the array on the heap
    // remains and has to be deleted
    
    // DESTRUCTOR
    // this will automatically get called at the end of a function
    // whenever an automaic variable goes out of scope
    // so I can deallocate whatever the automatic variable is pointing at
    // it takes no params
    MyString::~MyString() {
        delete [] str;
    }
    
    
    
    
    
    // RETURN LENGTH
    int MyString::length() const {
        return (unsigned)strlen(str);
    }
    
    
                /*
                 STREAM OPERATORS OVERLOAD
                 */
    
    
    
    
    // OUTPUT
    ostream& operator<<(ostream& out, const MyString& source) {
        out << source.str;
        return out;
    }
    
    
    
    
    
    
    // INPUT
    istream& operator>>(istream& in, MyString& target) {
        
        while (isspace(in.peek())){
            in.ignore();
        }
        
        char temp[128];
        in.getline(temp, 127, ':');
        delete [] target.str;
        target.str = new char[strlen(temp) + 1];
        strcpy(target.str, temp);
        
        return in;
    }
    
    
    
    
                 /*
                  BIG 3
                  */
    
    
    
    
    
    // ASSIGNMENT OPERATOR OVERLOAD - DEEP COPY
    MyString MyString::operator=(const MyString& right) {
        
        // check if memory address (this) of calling object is not the
        // same as memory address (&right) of parameter object right
        // this is the same as saying &(*this)
        if (this != &right) {
            // deallocate the memory the calling object is pointing at
            // this takes care of the memory leak
            delete [] str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }
        
        return *this; // a = b = 7; assignment operator returns what is being assigned
    }
    

    
    
                /*
                 SQUARE BRACKET OPERATOR OVERLOAD
                 */

    
    
    
    // read access to the chars
    // c++ understands which operator to call based on the 'const'
    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }

    
    
    
    // instead of returning the value return a reference so a user can do something like
    // item1[1] = 'c', a reference can be on the right side of an = operator
    // otherwise it would be 'a' = 'c', which would not work. 
    // returns the client a reference to the char so they can
    // change the value
    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }

    

                /*
                 COMPARATORS
                 */
    
    
    
    
    
    bool operator<(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) < 0);
    }
   
    
    
    
    
    
    bool operator<=(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) <= 0);
    }

    
    
    
    
    
    bool operator>(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) > 0);
    }

    
    
    
    
    
    bool operator>=(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) >= 0);
    }

    
    
    
    
    
    bool operator==(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) == 0);
    }

    
    
    
    
    
    bool operator!=(const MyString& left, const MyString& right) {
        return (strcmp(left.str, right.str) != 0);
    }
}



