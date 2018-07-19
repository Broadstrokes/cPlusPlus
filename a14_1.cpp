//
//  mystring.cpp
//  a14_1
//
//  Created by Dan Sajjad on 7/16/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.


#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"

using namespace std;

namespace cs_mystring {
    /*
     Class Invariant: a MyString object has 2 data members as follows:
     char data member: str, which stores a c-string
     int data member: MAX_READ_SIZE, which indicates the max size of characters
     that can be read by the extraction operator and the read function
     */
    
    
    
    
    
    
    /*
     default constructor. Initializes the object with an empty character
     */
    MyString::MyString() {
        str = new char[1];
        strcpy(str, "");
    }
    
    
    
    
    
    /*
     Constructor 2
     Initializes calling object using the passed in c-string
     
     @param inString char   c-string to store in the calling object
     */
    MyString::MyString(const char *inString) {
        str = new char[strlen(inString) + 1];
        strcpy(str, inString);
    }
    
    
    
    
    
    /*
     Deep copy constructor
     Deep copy a MyString object onto a calling object
     
     We want to make a deep copy so that whatever deepCopyMe's str is
     holding we copy that over we have to make sure that the param is pass by
     reference not pass by value
     
     @param deepCopyMe  MyString the object to deep copy from
     */
    MyString::MyString(const MyString& deepCopyMe) {
        str = new char[strlen(deepCopyMe.str) + 1];
        strcpy(str, deepCopyMe.str);
    }
    
    
    
    
    
    
    /*
     Assignment operator overload
     
     check if memory address (this) of calling object is not the
     same as memory address (&right) of parameter object right
     and then deep copy the right object onto the calling object
     
     @param right  MyString right operand object to deep copy
                            onto the calling object
     @return MyString       the calling object after being deep copied
    */
    MyString MyString::operator=(const MyString& right) {
        if (this != &right) {
            delete [] str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }
        
        return *this;
    }
    
    
    
    
    
    
    /*
     Destructor
     
     Called automatically when an object on the stack is deallocated
    */
    MyString::~MyString() {
        delete [] str;
    }
    
    
    
    
    
    
    /*
     Returns length of the calling object
     
     @return int    length of the calling object
     */
    int MyString::length() const {
        return (unsigned)strlen(str);
    }
    

    
    
    
    
    /*
     Prints out the characters of a MyString
     
     @param  source     MyString to be inserted into the stream
     @return            left operand
     */
    ostream& operator<<(ostream& out, const MyString& source) {
        out << source.str;
        return out;
    }
    
    
    
    
    
    /*
     This function will read in 127 characters
     Ignores leading spaces and then reads characters into the string
     up to the first whitespace character
     
     @param  target     MyString to be read into the calling object
     @return            left operand
     */
    istream& operator>>(istream& in, MyString& target) {
        char temp[target.MAX_READ_SIZE + 1];
        in >> temp;
        delete [] target.str;
        target.str = new char[strlen(temp) + 1];
        strcpy(target.str, temp);
        
        return in;
    }
    
    
    
    
    
    
    /*
     This function will read in 127 characters max
     Allows the client programmer to specify the delimiting character
     Places everything up to but not including the delimiting character into
     the calling object
     
     @param delimiter   the delimiting character
     */
    void MyString::read(istream& in, char delimiter) {
        char temp[MAX_READ_SIZE + 1];
        in.getline(temp, MAX_READ_SIZE, delimiter);
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }
    
    
    
    
    
    
    /*
     SQUARE BRACKET OPERATOR OVERLOAD
     */
    
    
    
    
    
    /*
     Provide read access to the chars
     c++ understands which operator to call based on the 'const'
     
     @param int     position of the character to retrieve
     @return char   character at the specified index
     */
    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }
    
    
    
    
    
    
    /*
     Instead of returning the value return a reference so a user can
     do something like item1[1] = 'c', a reference can be on the right
     side of an = operator otherwise it would be 'a' = 'c', which
     would not work. Returns the client a reference to the char so they
     can change the value
     Puting an & after the word "char" returns a reference to (or memory
     address of) a variable instead of a copy of the variable
     
     @param int     position of the character to retrieve
     @return        reference to the character at the specified index
     */
    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }
    
    
    
    
    
    
    /*
     Concatenate 2 strings
     
     @param left    MyString object
     @param right   MyString object
     @return MyString returns a concatenated string made using the calling MyString right and right MyString
     */
    MyString operator+(const MyString& left, const MyString& right) {
        char temp[strlen(left.str) + strlen(right.str) + 1];
        strcpy(temp, left.str);
        strcat(temp, right.str);
        return temp;
    }
    
    
    
    
    
    
    /*
     Append a string to a calling object
     
     @param right      MyString or C-string to be appended
     @return MyString  the calling MyString is incremented with the right MyString and is returned
     */
    MyString MyString::operator+=(const MyString& right) {
        *this = *this + right;
        return *this;
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
