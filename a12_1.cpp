//
//  fraction.cpp
//  a12_1 final
//
//  Created by Dan Sajjad on 7/14/18.
//  Copyright © 2018 Dan Sajjad. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "fraction.h"
#include "helper.h"

using namespace std;


namespace cs_Fraction {
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
     * The function can handle -ive fractions 
     * simplifyFraction - see helper.h for documentation
     */
    void Fraction::simplify() {
        fractionParts simplifiedFrac; // struct type
        bool fractionIsNegative = false;
        bool numeratorIsNegative = false;
        bool denominatorIsNegative = false;
        
        if (numerator == 0) {
            // no need to go through the simplification process if numerator is 0 since 
            // the denominator is irrelvant
            // On cout a denominator of 1 will print 0; 
            denominator = 1;
        } else {

            // Convert numerator and denominator to +ive values for simplification
            if (numerator < 0) {
                numerator *= -1;
                numeratorIsNegative = true;
            }
            
            if (denominator < 0) {
                denominator *= -1;
                denominatorIsNegative = true;
            }
            
            // Ensure the resulting franction has the right sign
            fractionIsNegative = (!numeratorIsNegative && denominatorIsNegative) ||
                                 (numeratorIsNegative && !denominatorIsNegative);
            
            // Recursively reduce the fraction to lowest terms 
            simplifiedFrac = simplifyFraction(numerator, denominator);
            
            
            // Set the fraction's reduced numerator 
            if (fractionIsNegative) {
                numerator = simplifiedFrac.numerator * -1;
            } else {
                numerator = simplifiedFrac.numerator;
            }
            
            // Set the fraction's reduced denominator 
            denominator = simplifiedFrac.denominator;
        }
    }
    
    
    
    
    
    ///////////////////////////
    // Overloading Operators //
    ///////////////////////////
    
    
    ///////////////////////////////////////////////////////
    // Overload Operators: 4 Basic Arithmetic Operations //
    ///////////////////////////////////////////////////////
    
    /**
     * Function that adds a fraction
     * @param  left         fraction to be added
     * @param  right        other fraction to be added
     * @return Fraction     resulting fraction
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
     * @param  left         fraction 
     * @param  right        other fraction to be subtracted
     * @return Fraction     resulting fraction
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
     * @param  left         fraction to be multiplied
     * @param  right        other fraction to be multiplied with
     * @return Fraction     resulting fraction
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
     * @param  left          dividend fraction
     * @param  right         divisor fraction
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

    /**
     * Overload opertrator += 
     * Performs shorthand addition 
     * @param  right         right operand fraction to be added
     */
    Fraction Fraction::operator+=(const Fraction& right) {
        *this = *this + right;
        return *this;
    }





    /**
     * Overload opertrator -= 
     * Performs shorthand subtraction
     * @param  right        right operand fraction to be subtracted
     */
    Fraction Fraction::operator-=(const Fraction& right) {
        *this = *this - right;
        return *this;
    }






    /**
     * Overload opertrator *= 
     * Performs shorthand multiplication
     * @param  right         right operand fraction to be multiplied
     */
    Fraction Fraction::operator*=(const Fraction& right) {
        *this = *this * right;
        return *this;
    }






    /**
     * Overload opertrator /= 
     * Performs shorthand division 
     * @param  right         right operand fraction to divide by
     */
    Fraction Fraction::operator/=(const Fraction& right) {
        *this = *this / right;
        return *this;
    }






    ////////////////////////////////////////////////
    // Overload Operators: 6 Relational Operators //
    ////////////////////////////////////////////////






    /**
     * Overload opertrator < 
     * Performs less than comparision
     * @param  left      left operand 
     * @param  right     right operand 
     * @return bool     
     */
    bool operator<(const Fraction& left, const Fraction& right) {
        int leftSide = left.numerator * right.denominator;
        int rightSide = left.denominator * right.numerator;
        
        return leftSide < rightSide;
    }






    /**
     * Overload opertrator <=
     * Performs less than equal to comparision
     * @param  left      left operand 
     * @param  right     right operand 
     * @return bool     
     */    
    bool operator<=(const Fraction& left, const Fraction& right) {
        int leftSide = left.numerator * right.denominator;
        int rightSide = left.denominator * right.numerator;
        
        return leftSide <= rightSide;
    }






    /**
     * Overload opertrator >
     * Performs greater than comparision
     * @param  left      left operand 
     * @param  right     right operand 
     * @return bool     
     */
    bool operator>(const Fraction& left, const Fraction& right) {
        int leftSide = left.numerator * right.denominator;
        int rightSide = left.denominator * right.numerator;
        
        return leftSide > rightSide;
    }






    /**
     * Overload opertrator >=
     * Performs greater than eqaul to comparision
     * @param  left      left operand 
     * @param  right     right operand 
     * @return bool     
     */
    bool operator>=(const Fraction& left, const Fraction& right) {
        int leftSide = left.numerator * right.denominator;
        int rightSide = left.denominator * right.numerator;
        
        return leftSide >= rightSide;
    }
    





    /**
     * Overload opertrator == 
     * Performs equality check (i.e. if 2 fractions equal)
     * @param  left      left operand 
     * @param  right     right operand 
     * @return bool     
     */
    bool operator==(const Fraction& left, const Fraction& right) {
        int leftSide = left.numerator * right.denominator;
        int rightSide = left.denominator * right.numerator;
        
        return leftSide == rightSide;
    }
    
    



    /**
     * Overload opertrator !=
     * Performs not equal check - returns true if 2 fractions are not equal
     * @param  left      left operand 
     * @param  right     right operand 
     * @return bool     
     */
    bool operator!=(const Fraction& left, const Fraction& right) {
        int leftSide = left.numerator * right.denominator;
        int rightSide = left.denominator * right.numerator;
        
        return leftSide != rightSide;
    }
    
    /////////////////////////////////////////////////////////
    // Overload Operators: 2 Pre Increment/Decrement Operators //
    /////////////////////////////////////////////////////////
    




    /**
     * Overload opertrator pre-increment addition
     */
    Fraction Fraction::operator++() {
        numerator = numerator + denominator;
        return *this;
    }
    





    /**
     * Overload opertrator pre-increment subtraction
     */
    Fraction Fraction::operator--() {
        numerator = numerator - denominator;
        return *this;
    }
    
    /////////////////////////////////////////////////////////
    // Overload Operators: 2 Post Increment/Decrement Operators //
    /////////////////////////////////////////////////////////
    

    /**
     * Overload opertrator post-increment addition
     */
    Fraction Fraction::operator++(int) {
        Fraction temp(numerator, denominator);
        numerator = numerator + denominator;
        return temp;
    }





    /**
     * Overload opertrator post-increment subtraction
     */
    Fraction Fraction::operator--(int) {
        Fraction temp(numerator, denominator);
        numerator = numerator - denominator;
        return temp;
    }
    




    /////////////////////////////////////
    // Overload Operators: << Operator //
    /////////////////////////////////////
    





    /**
     * Overload stream insertion opertrator
     * Inserts the right operand into the stream represented by the left operand, 
     * and returns the left operand.
     * @param out       ostream 
     * @param right     fraction to be inserted into the stream
     * @return          left operand
     */
    ostream& operator<<(ostream& out, const Fraction& right) {
        int numerator = right.numerator;
        int denominator = right.denominator;
        int quotient, remainder;
        

        if (denominator == 1) { // print whole #
            out << numerator;
        } else if (numerator > denominator) { // print a +ive mixed fraction
            quotient = numerator / denominator;
            remainder = numerator % denominator;
            out << quotient << '+' << remainder << "/" << denominator;
        } else if (numerator < 0 && (numerator * -1) >  denominator) { // -ive mixed fraction
            quotient = numerator / denominator;
            remainder = (numerator % denominator) * -1;
            out << quotient << '+' << remainder << "/" << denominator;
        } else { // print a simple fraction
            out << numerator << "/" << denominator;
        }
        
        
        return out;
    }
    
    

    /////////////////////////////////////
    // Overload Operators: >> Operator //
    /////////////////////////////////////



    /**
     * Overload stream extraction opertrator
     * Reads exactly one fraction value from input of the following formats: 
     * mixed number, negative number, whole numbers
     * and returns the left operand.
     * @param in        istream 
     * @param right     fraction to be inserted into the stream
     * @return          left operand
     */
    istream& operator>>(std::istream& in, Fraction& right) {
    /*
     You read an int.
     
     If the next character after the int is a +, then you know you have to read
     two more ints, and then you're done (mixed number).
     
     If the next character after the int is a /, then you know you have to read
     one more int, then you're done (fraction).
     
     If the next character is neither of those, then you're already done 
     (whole number).
     
     */


        int numerator, remainder = 0, denominator = 1;

        in >> numerator;

        if (in.peek() == '+') {
            in.ignore();
            in >> remainder;
            in.ignore();
            in >> denominator;

            if (numerator < 0) {
                numerator = (numerator * -1 * denominator + remainder) * -1;
            } else {
                numerator = numerator * denominator + remainder;
            }
        } else if (in.peek() == '/') {
            in.ignore();
            in >> denominator;
        }
        

        Fraction temp(numerator, denominator);
        
        right.numerator = temp.numerator;
        right.denominator = temp.denominator;
        
        
        return in;
    }
    

}
