# Lesson 2

## Expression & Operators

* variable = expression; 


## Order of operations

* PEMDAS
	* P
	* E
	* Multiplication, division, modulo done left to right
		* if multiplcation came 1st we multiply 1st
			* 24 / 3 * 4 = 32
		* if division came 1st we divide 1st
	* AS done left to right

## Modulus & Division

* What happens when we do division and it doesn't come out to be an integer?
	* in C++ when you divide 2 integers, the result is an integer
	* The fraction or decimal part gets truncated or chopped off
		* Eg: 23 / 4 = 5 

### Modulus Operator

* Using the Modulus operator we can get the remainder
	* 23 % 4 = 3
* We can use the modulus to check if a # is divisible by another
	* if output of a modulus operation is 0, then divisible

## Double Variables & Values
	
* Double value
	* a # that has a decimal point in it (same as a float)
	* In C++ 5 is an int and 5.0 is a double
	* Because of the way computers store double, you can never assume that a double value is being stored with the exact percision
		* > for this reason, you should never use the equals (==) operator to compare doubles
	* Always use 'int' unless the situation requires 'dobule' i.e use of non-integer values

### Convert int -> double
* if int is a literal, you can just add .0 to the literal
	* Eg: To force C++ to treat int 47 as a double just use 47.0
* if the int is a variable, you should use static-cast
	* Eg: int numCorrect needs to be converted 
	* static_cast <dobule> (numCorrect)
* > Operators +, -, \*, /, %, require both operands to be of the same type

