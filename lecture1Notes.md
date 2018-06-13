# Lesson 1

## Intro

### cout

```c++
cout << "Hello world";
```

* cout << **stream that represents the computer screen**
* << : stream insertion operator - inserts sth onto stream
* string: on the right is inserted into the thing on the left of the <<

```c++ 
```


```c++ 
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello world"
}
```

* cout is found in the file named iostream
* you can"t use the word "cout" unless you are using the namespace std
* int main() says this is where to start executing statements
	* it is not always the 1st theing to appear in c++ programs
* {being and end of the program}


### endl  - end line
```c++
	#include <iostream>
	using namespace std;

	init main() 
	{
		cout << "Hi" << endl;
		cout << "How are you?" << endl;
	}
```


* cout: write following list of items to screen
* <<: here comes the 1st item
* 'Hi': 1st item string
* endl: tell the computer to hit the return key
* ; means end of statement

```c++
#include <iostream>
using namespace std;

init main() 
{
	cout << "Hi" << endl 
	<< "How are you?" << endl;
}
```

### \ - escape character
```c++
#include <iostream>
using namespace std;

init main() 
{
	cout << "Hi" << endl 
	<< "Bob said, \"How are you?\"" << endl;
}
```

## Thinking through our strategy for writing a C++ program

* Ask what are the steps involved in accomplishing the task at hand? 
* Write the steps out
* Eg: To calculate paycheck for the week
	* Get # of hours worked from the user and store it
	* Calculate # hours * hourly rate
	* Display paycheck amount on screen



### >>  - stream extraction operator
```c++
#include <iostream>
using namespace std;

init main() 
{
	// STEP 1: Get info from user
	// declare variables 
	int hoursWorked;
	int hourlyRate;
	int paycheckAmount;

	cout << "Please enter the number of hours worked: ";
	cin >> hoursWorked  // wait for user to type in value and put that value into the variable hoursWorked
	
	cout << "Please enter rate per hour: ";
	cin >> hourlyRate;
	// Step 2: Calculate
	// ASSIGNMENT OPERATOR = 
	paycheckAmount = hoursWorked * hourlyRate;
	
	// Step 3: Display amount to user
	cout << "The amout of the paycheck is "
				<< paycheckAmount << "dollars." << endl;

}

```

