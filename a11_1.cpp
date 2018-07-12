//
//  main.cpp
//  a11_1
//
//  Created by Dan Sajjad on 7/10/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//  Class: CS110B - Programming Fundamentals C++
//  Teacher: Dave Harden



/*
     Create a fraction class that has various member functions
     to perform calculation on fractions
 */


#include <iostream>
#include <cassert>
using namespace std;

struct fractionParts {
    int numerator;
    int denominator;
};


fractionParts simplifyFraction(int numerator, int denominator, int divisor = 2);



            ///////////////////////////////
            // Fraction class definition //
            ///////////////////////////////

class Fraction {
    public:
        Fraction(int inNumerator = 0, int inDenominator = 1);
        friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);
    
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
    
        Fraction operator+=(const Fraction& right);
        Fraction operator-=(const Fraction& right);
        Fraction operator*=(const Fraction& right);
        Fraction operator/=(const Fraction& right);
    
        Fraction operator++();
        Fraction operator--();
        Fraction operator++(int);
        Fraction operator--(int);
    
    private:
        int numerator, denominator;
        void simplify();
};


                /////////////////////
                // Class Functions //
                /////////////////////



/*
 Class Invariant: a Fraction object has 2 int data members:
 numerator, which stores the numerator, and
 denominator, which stores the denominator
 Fraction objects will always be stored in lowest terms
 */


/**
 * Set the numerator and the denominator in simplest form
 * @param inNumerator   the numerator's value
 * @param inDenominator the denominator's value
 */
Fraction::Fraction(int inNumerator, int inDenominator) {
    assert(inDenominator != 0);
    
    numerator = inNumerator;
    denominator = inDenominator;
    simplify();
}






/**
 * Simplify the fraction using the helper function
 * simplifyFraction - see helper.h for documentation
 */
void Fraction::simplify() {
    fractionParts simplifiedFrac; // struct type
    
    simplifiedFrac = simplifyFraction(numerator, denominator);
    
    
    numerator = simplifiedFrac.numerator;
    denominator = simplifiedFrac.denominator;
}





                ///////////////////////////
                // Overloading Operators //
                ///////////////////////////


///////////////////////////////////////////////////////
// Overload Operators: 4 Basic Arithmetic Operations //
///////////////////////////////////////////////////////







/**
 * Function that adds a fraction
 * @param  left fraction to be added
 * @return Fraction      resulting fraction
 */
Fraction operator+(const Fraction& left, const Fraction& right) {
    int outNumerator, outDenominator;
    
    outDenominator =
    (left.denominator * right.denominator);
    
    outNumerator =
    (right.denominator * left.numerator) +
    (right.numerator * left.denominator);
    
    Fraction output(outNumerator, outDenominator);
    return output;
}







/**
 * Function to subtract another fraction
 * @param  right fraction to be subtracted
 * @return Fraction      resulting fraction
 */
Fraction operator-(const Fraction& left, const Fraction& right) {
    int outNumerator, outDenominator;
    
    outDenominator =
    (left.denominator * right.denominator);
    
    outNumerator =
    (right.denominator * left.numerator) -
    (right.numerator * left.denominator);
    
    Fraction output(outNumerator, outDenominator);
    return output;
}







/**
 * Function to return result of a multiplication by another fraction
 * @param  right fraction to be multiplied
 * @return Fraction      resulting fraction
 */
Fraction operator*(const Fraction& left, const Fraction& right) {
    int outNumerator, outDenominator;
    
    outNumerator = left.numerator * right.numerator;
    outDenominator = left.denominator * right.denominator;
    
    Fraction output(outNumerator, outDenominator);
    return output;
}







/**
 * Function to return result of a dividision by another fraction
 * @param  right fraction to divide by
 * @return Fraction      resulting fraction
 */
Fraction operator/(const Fraction& left, const Fraction& right) {
    int outNumerator, outDenominator;
    
    outNumerator = left.numerator * right.denominator;
    outDenominator = left.denominator * right.numerator;
    
    Fraction output(outNumerator, outDenominator);
    return output;
}




/////////////////////////////////////////////////////////////////
// Overload Operators: 4 Shorthand Basic Arithmetic Operations //
/////////////////////////////////////////////////////////////////






Fraction Fraction::operator+=(const Fraction& right) {
    *this = *this + right;
    return *this;
}






Fraction Fraction::operator-=(const Fraction& right) {
    *this = *this - right;
    return *this;
}







Fraction Fraction::operator*=(const Fraction& right) {
    *this = *this * right;
    return *this;
}






Fraction Fraction::operator/=(const Fraction& right) {
    *this = *this / right;
    return *this;
}





////////////////////////////////////////////////
// Overload Operators: 6 Relational Operators //
////////////////////////////////////////////////






bool operator<(const Fraction& left, const Fraction& right) {
    int leftSide = left.numerator * right.denominator;
    int rightSide = left.denominator * right.numerator;
    
    return leftSide < rightSide;
}






bool operator<=(const Fraction& left, const Fraction& right) {
    int leftSide = left.numerator * right.denominator;
    int rightSide = left.denominator * right.numerator;
    
    return leftSide <= rightSide;
}






bool operator>(const Fraction& left, const Fraction& right) {
    int leftSide = left.numerator * right.denominator;
    int rightSide = left.denominator * right.numerator;
    
    return leftSide > rightSide;
}





bool operator>=(const Fraction& left, const Fraction& right) {
    int leftSide = left.numerator * right.denominator;
    int rightSide = left.denominator * right.numerator;
    
    return leftSide >= rightSide;
}






bool operator==(const Fraction& left, const Fraction& right) {
    int leftSide = left.numerator * right.denominator;
    int rightSide = left.denominator * right.numerator;
    
    return leftSide == rightSide;
}







bool operator!=(const Fraction& left, const Fraction& right) {
    int leftSide = left.numerator * right.denominator;
    int rightSide = left.denominator * right.numerator;
    
    return leftSide != rightSide;
}





/////////////////////////////////////////////////////////
// Overload Operators: 2 Pre Increment/Decrement Operators //
/////////////////////////////////////////////////////////






Fraction Fraction::operator++() {
    numerator = numerator + denominator;
    return *this;
}







Fraction Fraction::operator--() {
    numerator = numerator - denominator;
    return *this;
}





//////////////////////////////////////////////////////////////
// Overload Operators: 2 Post Increment/Decrement Operators //
//////////////////////////////////////////////////////////////







Fraction Fraction::operator++(int) {
    Fraction temp(numerator, denominator);
    numerator = numerator + denominator;
    return temp;
}






Fraction Fraction::operator--(int) {
    Fraction temp(numerator, denominator);
    numerator = numerator - denominator;
    return temp;
}




/////////////////////////////////////
// Overload Operators: << Operator //
/////////////////////////////////////






ostream& operator<<(ostream& out, const Fraction& right) {
    out << right.numerator << "/" << right.denominator;
    return out;
}





            //////////
            // MAIN //
            //////////




int main() {
    int x = 1, y = 3, z = 4;
    Fraction f1(9,8);
    Fraction f2(2,3);
    Fraction result;
    Fraction f14;
    
    cout << f14 << endl;
    cout << "The result starts off at " << result << endl;
    
    cout << "The product of " << f1 << " and " << f2;
    cout << " is " << f1 * f2 << endl;
    
    cout << "The quotient of " << f1 << " and " << f2;
    cout << " is " << f1 / f2 << endl;
    
    cout << "The sum of " << f1 << " and " << f2;
    cout << " is " << f1 + f2 << endl;
    
    
    cout << "The difference of " << f1 << " and " << f2;
    cout << " is " << f1 - f2 << endl;
    
    
    if (f1 == f2){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
    
    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3 * (f4);
    
    cout << "The product of " << f3; cout << " and " << f4;
    cout << " is " << f3 * f4 << endl;
    
    Fraction f5(1, 2);
    cout << "The ++fraction of " << f5 << " is " << ++f5 << endl;
    cout << "The --fraction of " << f5 << " is " << --f5 << endl;
    
    
    Fraction f6(1, 2);
    cout << "The fraction++ of " << f6 << " is " << f6++ << endl;
    cout << "The fraction-- of " << f6 << " is " << f6-- << endl;
    
    
    Fraction f7(3, 2);
    cout << "The fraction++ of " << f7 << " is " << f7++ << endl;
    cout << "The fraction-- of " << f7 << " is " << f7-- << endl;
    
    
    cout << "The ++fraction of " << f5 << " is " << ++f5 << endl;
    cout << "The --fraction of " << f5 << " is " << --f5 << endl;
    
    
    cout << "The sum of " << f7 << " is " << x + f7 << endl;
    
    cout << "The sum of " << f7 << " & " << y << " is " << (f7 += y) << endl;
    cout << f7 << endl;
    
    cout << "The difference of " << f7 << " & " << y << " is " << (f7 -= y) << endl;
    cout << f7 << endl;
    
    cout << "The multiple of " << f7 << " & " << y << " is " << (f7 *= y) << endl;
    cout << f7 << endl;
    
    Fraction f8(8,3);
    cout << "The multiple of " << f8 << " & " << y << " is " << (f8 *= y) << endl;
    cout << f8 << endl;
    
    Fraction f9(1,8);
    cout << "The division of " << f8 << " & " << f9 << " is " << (f8 /= f9) << endl;
    cout << f8 << endl;
    
    cout << "The division of " << f8 << " & " << z << " is " << (f8 /= z) << endl;
    cout << f8 << endl;
    
    cout << f8 - f9 << endl;
    cout << "Is " << f8 << " < " << f9  << ": " << (f8 < f9) << endl;
    cout << "Is " << f8 << " > " << f9  << ": " << (f8 > f9) << endl;
    cout << "Is " << f8 << " == " << 16  << ": " << (f8 == 16) << endl;
    cout << "Is " << f8 << " == " << x  << ": " << (f8 == x) << endl;
    cout << "Is " << f8 << " != " << x  << ": " << (f8 != x) << endl;
    
    Fraction f10(16);
    cout << "Is " << f8 << " == " << f10  << ": " << (f8 == f10) << endl;
    
    Fraction f11, f12(3), f13(4,7);
    f11 = f12 + f13;
    cout << f12 << " plus " << f13 << " is " << f11 << endl;
}





            ///////////////////////////////////////////
            // Helper function to simplify fractions //
            ///////////////////////////////////////////







/**
 * This is a helper function that takes a numerator,
 * a denominator and a starting divisor as params and outputs
 * the reduced numerator and denominator. The function recursively proceeds to
 * reduce the fraction until it can no longer be reduced and is in
 * the simplest form.
 *
 * @param  numerator          indicates the numerator
 * @param  denominator        indicates the denominator
 * @param  divisor      indicates the divisor that you'd like to start
 *                      reducing the fraction by. Default value is 2 since,
 every number is divisible by 1. Divisibility test starts
 at 2.
 * @return              a struct with the reduced numerator and denominator
 */
fractionParts simplifyFraction(int numerator, int denominator, int divisor /* = 2*/) {
    if (divisor > numerator || divisor > denominator) { // Exit condition
        fractionParts output = {numerator, denominator};
        return output;
    } else {
        if (numerator % divisor == 0 && denominator % divisor == 0) {
            return simplifyFraction(numerator/divisor, denominator/divisor, divisor);
        } else {
            return simplifyFraction(numerator, denominator, divisor + 1);
        }
    }
    
    return simplifyFraction(numerator, denominator, divisor);
}






                ////////////////////
                // Program Output //
                ////////////////////


/*
    0/1
    The result starts off at 0/1
    The product of 9/8 and 2/3 is 3/4
    The quotient of 9/8 and 2/3 is 27/16
    The sum of 9/8 and 2/3 is 43/24
    The difference of 9/8 and 2/3 is 11/24
    The two Fractions are not equal.
    The product of 3/2 and 2/3 is 1/1
    The ++fraction of 1/2 is 3/2
    The --fraction of 3/2 is 1/2
    The fraction++ of 1/2 is 1/2
    The fraction-- of 3/2 is 3/2
    The fraction++ of 3/2 is 3/2
    The fraction-- of 5/2 is 5/2
    The ++fraction of 1/2 is 3/2
    The --fraction of 3/2 is 1/2
    The sum of 3/2 is 5/2
    The sum of 3/2 & 3 is 9/2
    9/2
    The difference of 9/2 & 3 is 3/2
    3/2
    The multiple of 3/2 & 3 is 9/2
    9/2
    The multiple of 8/3 & 3 is 8/1
    8/1
    The division of 8/1 & 1/8 is 64/1
    64/1
    The division of 64/1 & 4 is 16/1
    16/1
    127/8
    Is 16/1 < 1/8: 0
    Is 16/1 > 1/8: 1
    Is 16/1 == 16: 1
    Is 16/1 == 1: 0
    Is 16/1 != 1: 1
    Is 16/1 == 16/1: 1
    3/1 plus 4/7 is 25/7
    Program ended with exit code: 0
*/