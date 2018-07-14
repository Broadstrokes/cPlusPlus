//
//  a9_1.cpp
//
//
//  Created by Dan Sajjad on 7/3/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//


/*
    Create a fraction class that has various functions
    to perform calculation on fractions
*/


#include <iostream>
using namespace std;

class Fraction {
    public:
        void set(int inNumerator, int inDenominator);
        void print();
        bool isEqualTo(Fraction otherFraction);
        Fraction addedTo(Fraction otherFraction);
        Fraction subtract(Fraction otherFraction);
        Fraction multipliedBy(Fraction otherFraction);
        Fraction dividedBy(Fraction otherFraction);
    
    private:
        int numerator, denominator;
};






/**
 * Function that adds a fraction
 * @param  otherFraction fraction to be added
 * @return Fraction      resulting fraction
 */
Fraction Fraction::addedTo(Fraction otherFraction) {
    Fraction output;
    
    output.denominator =
        (denominator * otherFraction.denominator);
    
    output.numerator =
        (otherFraction.denominator * numerator) +
        (otherFraction.numerator * denominator);
    
    return output;
}







/**
 * Function to subtract another fraction
 * @param  otherFraction fraction to be subtracted
 * @return Fraction      resulting fraction
 */
Fraction Fraction::subtract(Fraction otherFraction) {
    Fraction output;
    
    output.denominator =
        (denominator * otherFraction.denominator);
    
    output.numerator =
        (otherFraction.denominator * numerator) -
        (otherFraction.numerator * denominator);
    
    return output;
}






/**
 * Function to multiply another fraction
 * @param  otherFraction fraction to be multiplied
 * @return Fraction      resulting fraction
 */
Fraction Fraction::multipliedBy(Fraction otherFraction) {
    Fraction output;
    
    output.numerator = numerator * otherFraction.numerator;
    output.denominator = denominator * otherFraction.denominator;
    
    return output;
}







/**
 * Function to divide by another fraction
 * @param  otherFraction fraction to divide by
 * @return Fraction      resulting fraction
 */
Fraction Fraction::dividedBy(Fraction otherFraction) {
    Fraction output;
    
    output.numerator = numerator * otherFraction.denominator;
    output.denominator = denominator * otherFraction.numerator;
    
    return output;
}







/**
 * Function to compare another fraction
 * @param  otherFraction fraction to be compared
 * @return bool     indicating if the 2 fractions equal
 */
bool Fraction::isEqualTo(Fraction otherFraction) {
    return (
        (numerator * otherFraction.denominator) ==
        (denominator * otherFraction.numerator)
    );
}







/**
 * Print the fraction on screen
 */
void Fraction::print() {
    cout << numerator << "/" << denominator;
}






/**
 * Set the numerator and the denominator
 * @param inNumerator   the numerator's value
 * @param inDenominator the denominator's value
 */
void Fraction::set(int inNumerator, int inDenominator) {
    numerator = inNumerator;
    denominator = inDenominator;
}








int main() {
    Fraction f1;
    Fraction f2;
    Fraction result;
    
    f1.set(9, 8);
    f2.set(2, 3);
    
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
}

/*
    The product of 9/8 and 2/3 is 18/24
    The quotient of 9/8 and 2/3 is 27/16
    The sum of 9/8 and 2/3 is 43/24
    The difference of 9/8 and 2/3 is 11/24
    The two Fractions are not equal.
    Program ended with exit code: 0
*/
