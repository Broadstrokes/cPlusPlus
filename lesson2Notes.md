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

### Conversion Rules
1. Expressions - Expression has 1 int operand and 1 dobule operand, int is changed temporarily to a dobule, the result will be a dobule 
	* (2 + 3.5) / 5 
		* 2 becomes 2.0, thus 2.0 + 3.5 = 5.5
		* 5.5 / 5, now 5 will become 5.0, thus 5.5 / 5.0
		* the result is 1.1
2. Assignments - C++ automatically changes the value of the expression on the right of the assignment operator to match the type of the variable on the left of the assignment operator
```cpp 
	
	int i; 
	dobule x; 
	dobule y;

	x = 11;
	y = 4; 
	i = x / y; // 2

	/*
		11/4 = 2.75, 
		C++ notes that i should be an int, thus before assigning value to i, it 
		converts 2.75 to an int, and i will equal 2
	 */

```

```cpp 
	int i; 
	int j;
	dobule x; 

	i = 11;
	j = 4; 
	x = i / j;  // 2.0

	/*
		int 11 / int 4  = 2
		C++ notes that x is a dobule, and before assiginig value to x, 
		it converts 2 to a dobule, thus x equals 2.0

	 */
```
* > When mixing ints and dobules we have to be very careful to follow C++ rules

## Char variables & values

* char is used to store a character in a variable 
	* letters, digits, symbols
* enclosed by single quotes: 'm'
* we distinguish char variable and char values by placing a single quote around character values
	* in a program if we see 'x', it a character value, not a variable
	* Eg: char ch = '?'
* NB: 
	* > When a char value is typed in by the user, the user should NOT enclose it in quotes
	* > char stores exaclty one character. It doesn't make sense to say ch = 'hello'

```cpp
	char m, x; 
	m = 'x';
	x = 'm'

	cout << 'x';  // prints the character x
```

```cpp
	char m, x;
	m = 'x';
	x = 'm'

	cout << x; // prints the character m
```

```cpp
	char m, x;
	m = 'x';
	x = m;

	cout << x; // prints the character x
```

## String variables & values

* string values are a sequence of characters
* enclosed by double quotes: "Hi there"
* > Unlike other types in C++, when you use string variables, you must first ```#include <string>``` at top of your file. The compiler notices that you are using a 'string' variable type and automatically adds in the correct header file without you knowing. Its best practice to declare the headers and not to rely on the compiler to do it.
* ```string myNullOrEmpty = "";```  - is called a null or empty string
* > You can have a null string value, but you CANNOT have a null character value, because all character values MUST contain exactly 1 character
* You can use the string extraction operator to read a string
	* C++ uses the whitespace to markoff where the string starts & ends

```cpp
	// User entered: "My name is Dave"
	
	cin >> str1; // this will have the value "My"

	// To read all the words
	cin >> str1, str2, str3, str4;

```
* Concatenation: Adding 2 strings

```cpp
	string s1, s2, s3;
	s1 = "hi ";
	s2 = " there!";
	s3 = s1 + s2;

	cout << s3; // hi there!
```
### String types functions
* .length()
```cpp
	string s1; 
	s1 = "Hello";
	cout << s1.length() << endl; // prints 5
```
* .substr()
	* 1st argument indicates the starting index
	* 2nd argument indicates the # of characters to be included
```cpp
	string s1, s2; 
	s1 = "monkey see monkey do";
	s2 = s1.substr(3, 7);

	cout << s2; // key see 
```

## Comments
* single line: //
* multiple line: /\*\*/

## Named constants
* It is usually best not to use int or double literals in code, instead, we define named constants at the top of the file & use those in the place of actual literals. Eg: ```const int HOURLY_PAYRATE = 20```
* Why use named constants
	* modifying code is easier: need to change only in 1 place
	* self documenting code - const name makes it obvious what the value is
* Use all UPPERCASE for constants
* > An important example of where constants aren't useful is in formulas where the number doesn't represent anything in particular. For example, the formula to convert from celsius to fahrenheit is F = (9/5)C + 32. The 9/5 and the 32 don't represent anything in particular; they are just numbers that happen to make the formula work. Don't use named constants in this case.
* Make constants GLOBAL
	* In most cases constants should be declared OUTSIDE, right above the int main(), as opposed to variables, which are declared INSIDE int main().

## Stream extraction operator: >>
