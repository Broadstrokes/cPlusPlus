//
//  mystring.h
//  a14_1
//
//  Created by Dan Sajjad on 7/16/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

/*
    This is the Implementation of a string class with a private data member,
    which is a c-string called str and an int data member MAX_READ_SIZE.

    This object is designed to make working with sequences of characters
    a little more convenient and less error-prone than handling raw c-strings.
    The MyString class handles constructing strings, reading/printing, and
    accessing characters. In addition, the MyString object has the ability to
    make a full deep-copy of itself when copied.


    The following functions are available:


    MyString();
    post: The calling object has been created and initialized so that
    the str property is an empty char. Creates an empty MyString object


    MyString(const char *inString);
    post: The calling object has been created and initialized so that
    the str equals the inString. Copies the string data.

    MyString(const MyString& deepCopyMe);
    post: The calling object has been created and initialized so that
    the str equals the passed in MyString object str

    MyString operator=(const MyString& right);
    post: If the object on the right is not the calling object, the
    calling object is deep copied from the object on the right


    ~MyString();
    Called automatically when an object on the stack is deallocated
    post: deallocate any memory on the heap that the object is pointing to

    friend std::ostream& operator<<(std::ostream& out, const MyString& source);
    post: Prints out the characters of a MyString

    friend std::istream& operator>>(std::istream& in, MyString& target);
    pre: This function will only read in 127 characters max
    post: Ignores leading spaces and then reads characters into the string up to
    the first whitespace character


    friend bool operator<(const MyString& left, const MyString& right);
    post: Returns true if the left MyString is less than right MyString.
    Otherwise returns false. The ordering is based on ASCII values.

    friend bool operator<=(const MyString& left, const MyString& right);
    post: Returns true if the left MyString is less than or equal to
    right MyString. Otherwise returns false. The ordering is based on ASCII values.

    friend bool operator>(const MyString& left, const MyString& right);
    post: Returns true if the left MyString is greater than the right MyString.
    Otherwise returns false. The ordering is based on ASCII values.

    friend bool operator>=(const MyString& left, const MyString& right);
    post: Returns true if the left MyString is greater than or equal to
    right MyString. Otherwise returns false. The ordering is based on ASCII values.

    friend bool operator==(const MyString& left, const MyString& right);
    post: Returns true if the left MyString equals right MyString.
    Otherwise returns false. The ordering is based on ASCII values.

    friend bool operator!=(const MyString& left, const MyString& right);
    post: Returns true if the left MyString does not equal right MyString.
    Otherwise returns false. The ordering is based on ASCII values.

    friend MyString operator+(const MyString& left, const MyString& right);
    post: returns a concatenated string made using left MyString and
    right MyString

    MyString operator+=(const MyString& right);
    pre: only MyStrings can be on the left-hand side of a += operation,
    but either MyStrings or C-strings may appear on the right side
    post: the calling MyString is incremented with the right MyString and is returned


    char operator[](int index) const;
    pre: index is bound within the range 0 to length of the calling MyString
    post: returns the character at a specific index


    char& operator[](int index);
    pre: index is bound within the range 0 to length of the calling MyString
    post: returns the client a reference to the char at a specfic index


    int length() const;
    post: returns the length of a MyString c-string


    void read(std::istream& in, char delimiter);
    pre: This function will read in 127 characters max
    post: Allows the client programmer to specify the delimiting character
    Places everything up to but not including the delimiting character into
    the calling object
 
 */

namespace cs_mystring {
    class MyString {
    public:
        MyString();
        MyString(const char *inString);
        MyString(const MyString& deepCopyMe);
        
        MyString operator=(const MyString& right);
        
        ~MyString();
        
        friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        
        
        friend MyString operator+(const MyString& left, const MyString& right);
        MyString operator+=(const MyString& right);
        
        char operator[](int index) const;
        char& operator[](int index);
        
        int length() const;
        void read(std::istream& in, char delimiter);
        
        
    private:
        char *str; // C-string
        static const int MAX_READ_SIZE = 127;
    };
}

#endif /* MYSTRING_H */


/*
     ----- Testing basic String creation & printing
     string [0] = Wow
     string [1] = C++ is neat!
     string [2] =
     string [3] = a-z
 
     ----- Now reading MyStrings from file
 
     ----- first, word by word
     Read string = The
     Read string = first
     Read string = time
     Read string = we
     Read string = will
     Read string = read
     Read string = individual
     Read string = words,
     Read string = next
     Read string = we
     Read string = read
     Read string = whole
     Read string = lines
 
     ----- now, line by line
     Read string = The  first  time  we  will
     Read string =     read individual words, next
     Read string = we read whole lines
 
     ----- Testing access to characters (using const)
     Whole string is abcdefghijklmnopqsrtuvwxyz
     now char by char: abcdefghijklmnopqsrtuvwxyz
     ----- Testing access to characters (using non-const)
     Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ
 
     ----- Testing relational operators between MyStrings
     Comparing app to apple
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
     Comparing apple to
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
     Comparing  to Banana
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
     Comparing Banana to Banana
     Is left < right? false
     Is left <= right? true
     Is left > right? false
     Is left >= right? true
     Does left == right? true
     Does left != right ? false
 
     ----- Testing relations between MyStrings and char *
     Comparing he to hello
     Is left < right? true
     Is left <= right? true
     Is left > right? false
     Is left >= right? false
     Does left == right? false
     Does left != right ? true
     Comparing why to wackity
     Is left < right? false
     Is left <= right? false
     Is left > right? true
     Is left >= right? true
     Does left == right? false
     Does left != right ? true
 
     ----- Testing concatentation on MyStrings
     outrageous + milk = outrageousmilk
     milk +  = milk
     + cow = cow
     cow + bell = cowbell
 
     ----- Testing concatentation between MyString and char *
     abcde + XYZ = abcdeXYZ
     XYZ + abcde = XYZabcde
 
     ----- Testing shorthand concat/assign on MyStrings
     who += what = whowhatandwhowhat
     what += WHEN = whatWHENandwhatWHEN
     WHEN += Where = WHENWhereandWHENWhere
     Where += why = WherewhyandWherewhy
 
     ----- Testing shorthand concat/assign using char *
     I love  += programming = I love programming
 
     ----- Testing copy constructor and operator= on MyStrings
     original is cake, copy is fake
     original is cake, copy is fake
     after self assignment, copy is Copy Cat
     Testing pass & return MyStrings by value and ref
     after calling Append, sum is BinkyBoo
     val is winky
     after assign,  val is BinkyBoo
     Program ended with exit code: 0
 
 */
