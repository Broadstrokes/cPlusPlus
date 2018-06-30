#
include < iostream > #include < cctype > #include < cstring >
  using namespace std;

/*
  strlen()
  strcat
  strcpy
  strncat
  strncpy
  strcmp
  strstr
*/

/*
  Following are NOT c-string functions. The C++ library provides several functions for testing characters. To use these functions you must include the cctype header file.
  isalpha()
  isalnum
  isdigit
  islower
  isprint
  ispunct
  isupper
  isspace
  toupper
  tolower
*/

/*
  In C++, a C-string is a sequence of characters stored in consecutive mem-
  ory locations, terminated by a null character.
*/

/*
atoi Accepts a C-string as an argument. The function converts the C-string to an integer and returns that value.
Example Usage: int num = atoi("4569");

atol Accepts a C-string as an argument. The function converts the C-string to a long inte- ger and returns that value.
Example Usage: long lnum = atol("500000");

atof Accepts a C-string as an argument. The function converts the C-string to a double and returns that value.
Example Usage: double fnum = atof("3.14159");
*/

/*
  However, if you look at getDimensions carefully the situation is different. getDimensions is not receiving values with which to initialize its parameters. On the contrary, getDimensions would like to start out with empty parameters, fill them up with the users input, and then pass this information back to main! We cannot do this with pass-by-value. In this kind of situation, when a function wants to pass information back to the calling function, we must use our second parameter passing mechanism, pass-by-reference. Syntactically, this is really simple. We simply add an & symbol in the function's parameter list, like this:
*/

/*
This brings up another detail that we need to discuss here. We do not want the findSmallest function to be able to modify the variable list declared in main. Usually we would accomplish this by making list a pass-by-value parameter, but that won't work in this case because arrays are always pass-by-reference automatically. So we use the const keyword, which simply makes it against the rules for this function to modify the array. In our findSmallest function that will look like this:

    int findSmallest(const int list[], int numItems)
    {
        <body of function>
    }

*/

/*
The next thing that happens is the call to getDimensions. As we enter getDimensions, two parameters are declared, and memory is allocated for these two new variables. If these parameters were pass-by-value parameters, they would get initialized to the values of the corresonding arguments. In this case, the values of the corresponding arguments are unknown, and so the parameters would both get initialized to junk. However, these parameters are not pass-by-value, they are pass-by-reference. The way pass-by-reference works is that instead of being initialized to the value stored in the corresponding argument, the parameters are initialized to the memory address of the corresponding argument. If we assume for a moment that width is stored at memory location 5000 and height is stored at memory location 5004, the situation would look like this:
*/


/*
  int a;
  int* somePonter; //declare a pointer
  somePonter = &a; //inptr gets address of a;
  *somePonter = 47 // assign value 47 to a using "dereferencing" or "indirection"

  string* strptr2; // string pointer
  string* strptr3; // string pointer
  string str2("there"); // string object
  string str3("penelope"); //string object
  strptr2 = &str2; // point to the object
  strptr3 = &str3; // point to the object
  Next let's declare an array of pointers to string objects and initialize the first three elements of the array to point to the string objects we just created.

  string* array[10] = {strptr1, strptr2, strptr3};  // declare string pointer array holding pointers

  Now let's do an assignment and print the results:

  *array[0] = *array[1] + *array[2];
  cout << *array[0] << " " << *array[1] << " " << *array[2] << endl;

In C++ arrays are actually pointer constants. To illustrate this, let's declare an array of ints and a pointer to an int:

int array2[10]; // declare array
int* ptr; // declare pointer

ptr = array2; // assign array2 to pointer 
ptr = &array2[0]; // same as above

Now that ptr and array2 are the same thing, we can use them interchangeably. 


*/

int lastIndexOf(const char * inString, char target);
void reverse(char * inString);
int replace(char * inString, char target, char replacementChar);

int main() {
  const int SIZE = 51;
  char userString[SIZE];
  char letter = 'x';
  char answer;

  char str1[15] = "Hello World";
  char str2[15] = "C++ is fun!";
  char str3[6] = "apple";
  char str4[5] = "baby";
  // Get a string from the user;


  // do {
  // cin.clear();
  // cout << "Enter a string (up to 50 characters)";
  // cin.getline(userString, SIZE);
  // cout << "Enter target" << endl;
  // cin.get(letter);
  // cout << lastIndexOf(userString, letter) << endl;
  // cout << str1;
  // cout << "=========reversing=======" << endl;
  reverse(str1);
  reverse(str2);
  reverse(str3);
  reverse(str4);
  // cin.ignore();
  // cout << "Play again? "; 
  // cin.get(answer);
  // } while (answer == 'y');
}


//****************************************************************
// Definition of countChars. The parameter inString is a pointer *
// that points to a string. The parameter Ch is a character that *
// the function searches for in the string. The function returns *
// the number of times the character appears in the string. *
//****************************************************************

/*
  This function finds the last index where the target char can be found in the string. it returns -1 if the target char does not appear in the string. The function should be case sensitive (so 'b' is not a match for 'B').
*/
int lastIndexOf(const char * inString, char target) {
  int index = strlen(inString);

  while (index >= 0) {
    if (inString[index] == target) {
      return index;
    }
    index--;
  }
  return -1;
}

/*
  This function alters any string that is passed in. It should reverse the string. If "flower" gets passed in it should be reversed in place to "rewolf". For efficiency, this must be done "in place", i.e., without creating a second array.
*/
void reverse(char * inString) {
  char temp;
  int i = 0;
  int j = strlen(inString) - 1;

  while (i < j) {
    temp = inString[i];
    inString[i] = inString[j];
    inString[j] = temp;

    i++;
    j--;
  }

  cout << "REVERSED ====== " << endl;
  cout << inString << endl;
}

/*
  This function finds all instances of the char 'target' in the string and replace them with 'replacementChar'. It returns the number of replacements that it makes. If the target char does not appear in the string it should return 0.
*/

int replace(char * inString, char target, char replacementChar) {

}