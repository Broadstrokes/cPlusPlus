//
//  a10_1.cpp
//
//  Created by Dan Sajjad on 7/5/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.



/*

    The Fraction class can be used to create objects that store a 
    numerator & a denominator. The following functions are available:



    Fraction();
    post:   The calling object has been created and initialized so that
            the numerator is 0, and the denominator is 1.


    Fraction(int inNumerator, int inDenominator);
    post:   The calling object has been created and initialized so that
            the numerator is inNumerator, and the denominator is 
            inDenominator.


    void print() const;
    post:   The calling object has been printed to the console window 
            in the format numerator/denominator

    bool isEqualTo(const Fraction otherFraction) const;
    post:   Returns true if the calling object equals the parameter 
            "otherDate".  Otherwise returns false.

    Fraction addedTo(const Fraction otherFraction) const;
    post:   Returns the Fraction determined by starting with the 
            calling object and adding the otherFraction.


    Fraction subtract(const Fraction otherFraction) const;
    post:   Returns the Fraction determined by starting with the 
            calling object and subtracting the otherFraction.


    Fraction multipliedBy(const Fraction otherFraction) const;
    post:   Returns the Fraction determined by starting with the 
            calling object and multiplying the otherFraction.

    Fraction dividedBy(const Fraction otherFraction) const;
    post:   Returns the Fraction determined by starting with the 
            calling object and dividing by the otherFraction.
 
 */


/*
 Create a fraction class that has various member functions
 to perform calculation on fractions
 */


#include <iostream>
#include <cassert>
//#include "fraction.h"
using namespace std;




class Fraction {
public:
    Fraction();
    Fraction(int inNumerator, int inDenominator);
    void print() const;
    void simplify();
    bool isEqualTo(const Fraction otherFraction) const;
    Fraction addedTo(const Fraction otherFraction) const;
    Fraction subtract(const Fraction otherFraction) const;
    Fraction multipliedBy(const Fraction otherFraction) const;
    Fraction dividedBy(const Fraction otherFraction) const;
    
private:
    int numerator, denominator;
};

Fraction simplifyFraction(int num, int denom, int divisor);

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}


/**
 * Sets the default values 
 * @param 
 */
Fraction::Fraction(int inNumerator, int inDenominator) {
    assert(inDenominator != 0);
    
    numerator = inNumerator;
    denominator = inDenominator;
}


void Fraction::simplify() {
    Fraction simplifiedFrac;
    simplifiedFrac = simplifyFraction(numerator, denominator, 2);
    
    numerator = simplifiedFrac.numerator;
    denominator = simplifiedFrac.denominator;
}




/**
 * Function that adds a fraction
 * @param  otherFraction fraction to be added
 * @return Fraction      resulting fraction
 */
Fraction Fraction::addedTo(const Fraction otherFraction) const {
    Fraction output;
    
    output.denominator =
    (denominator * otherFraction.denominator);
    
    output.numerator =
    (otherFraction.denominator * numerator) +
    (otherFraction.numerator * denominator);
    
    output.simplify();
    return output;
}







/**
 * Function to subtract another fraction
 * @param  otherFraction fraction to be subtracted
 * @return Fraction      resulting fraction
 */
Fraction Fraction::subtract(const Fraction otherFraction) const {
    Fraction output;
    
    output.denominator =
    (denominator * otherFraction.denominator);
    
    output.numerator =
    (otherFraction.denominator * numerator) -
    (otherFraction.numerator * denominator);
    
    output.simplify();
    return output;
}






/**
 * Function to multiply another fraction
 * @param  otherFraction fraction to be multiplied
 * @return Fraction      resulting fraction
 */
Fraction Fraction::multipliedBy(const Fraction otherFraction) const {
    Fraction output;
    
    output.numerator = numerator * otherFraction.numerator;
    output.denominator = denominator * otherFraction.denominator;
    
    output.simplify();
    return output;
}







/**
 * Function to divide by another fraction
 * @param  otherFraction fraction to divide by
 * @return Fraction      resulting fraction
 */
Fraction Fraction::dividedBy(const Fraction otherFraction) const {
    Fraction output;
    
    output.numerator = numerator * otherFraction.denominator;
    output.denominator = denominator * otherFraction.numerator;
    
    output.simplify();
    return output;
}







/**
 * Function to compare another fraction
 * @param  otherFraction fraction to be compared
 * @return bool     indicating if the 2 fractions equal
 */
bool Fraction::isEqualTo(const Fraction otherFraction) const {
    return (
            (numerator * otherFraction.denominator) ==
            (denominator * otherFraction.numerator)
            );
}







/**
 * Print the fraction on screen
 */
void Fraction::print() const {
    Fraction tempFrac(numerator, denominator);
    tempFrac.simplify();
    
    cout << tempFrac.numerator << "/" << tempFrac.denominator;
}






/**
 * Set the numerator and the denominator
 * @param inNumerator   the numerator's value
 * @param inDenominator the denominator's value
 */
//void Fraction::set(int inNumerator, int inDenominator) {
//    numerator = inNumerator;
//    denominator = inDenominator;
//}










int main()
{
    Fraction f1(9,8);
    Fraction f2(2,3);
    Fraction result;
    
    cout << "The result starts off at ";
    result.print();
    cout << endl;
    
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;
    
    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;
    
    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;
    
    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
    
    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}





/**
 * This is a helper function that takes a numerator and
 * a denominator and a starting divisor as params and outputs
 * the reducted Fraction. The function recursively proceeds to 
 * reduce the fraction until it can no longer be reduced and is in
 * its simplified state
 * 
 * @param  num          indicated the numerator
 * @param  denom        indicated the denominator
 * @param  divisor      indicated the divisor that you'd like to start
 *                      reducing the fraction by. 
 * @return Fraction     the reduced fraction
 */
Fraction simplifyFraction(int num, int denom, int divisor) {
    if (divisor > num || divisor > denom) {
        Fraction output(num, denom);
        return output;
    } else {
        if (num % divisor == 0 && denom % divisor == 0) {
            return simplifyFraction(num/divisor, denom/divisor, divisor);
        } else {
            return simplifyFraction(num, denom, divisor + 1);
        }
    }
    
    return simplifyFraction(num, denom, divisor);
}



/*
     The result starts off at 0/1
     The product of 9/8 and 2/3 is 3/4
     The quotient of 9/8 and 2/3 is 27/16
     The sum of 9/8 and 2/3 is 43/24
     The difference of 9/8 and 2/3 is 11/24
     The two Fractions are not equal.
     The product of 3/2 and 2/3 is 1/1
     Program ended with exit code: 0
*/

struct fractionParts {
    int numerator;
    int denominator;
};


fractionParts simplifyFraction(int numerator, int denominator, int divisor = 2);



reducedFractionParts simplifyFraction(int numerator, int denominator, int divisor) {
    if (divisor > numerator || divisor > denominator) { // Exit condition
        reducedFractionParts output = {numerator, denominator}; 
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