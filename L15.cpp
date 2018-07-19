#include <iostream>
#include <cassert>
#include <string>
using namespace std;

/////////////////////////
// EMPLOYEE BASE CLASS //
/////////////////////////

class employee {
public:
	employee();
	employee(const string& inName, const string& inSSN);
	void changeName(const string& newName);
	void changeSSN(const string& newSSN);
	string getName() const;
	string getSSN() const;
protected: 
	string name;
	string ssn;
	double netPay;
};


employee::employee() { netPay = 0; }

employee::employee(const string& inName, const string& inSSN) {
	name = inName;
	ssn = inSSN;
	netPay = 0;
}

string employee::getName() const { return name; }
string employee::getSSN() const { return ssn; }
void employee::changeName(const string& newName) { name = newName; }
void employee::changeSSN(const string& newSSN) { ssn = newSSN; }


///////////////////////////////////
// HOURLY EMPLOYEE DERIVED CLASS //
///////////////////////////////////

class hourlyEmp: public employee { // public memeber of the base class will be public members of the derived class
public: 
	hourlyEmp();
	hourlyEmp(const string& inName, const string& inSSN, double inPayRate, double inHours);
	
	double getHours() const;

	void setHours(double newHours);
	void giveRaise(double amount);
	void printCheck() const;
private:
	double hours;
	double payRate;
};


hourlyEmp::hourlyEmp() {
	payRate = 0;
	hours = 0;
}

hourlyEmp::hourlyEmp(const string& newName,
                     const string& newSsn,
                     double newPayRate, 
                     double newHours) 
                                    
    : employee(newName, newSsn)
   
   
    {
        payRate = newPayRate;
        hours = newHours;
        netPay = hours * payRate;
    }

// hourlyEmp::hourlyEmp(const string& inName, const string& inSSN, double inPayRate, double inHours)

// : employee(inName, inSSN), payRate(inPayRate), hours(inHours), netPay(hours * payRate) {

// }


double hourlyEmp::getHours() const { return hours; }
void hourlyEmp::setHours(double hours) { hours = hours; netPay = hours * payRate; }
void hourlyEmp::giveRaise(double amount) { netPay = (payRate += amount) * hours; }
void hourlyEmp::printCheck() const { cout << name << ": " << netPay << endl; }


//////////
// MAIN //
//////////

int main() {
	hourlyEmp arnold("Arnonld Jones","23456664",13,20);    
	arnold.setHours(10);
	cout << "Check for " << arnold.getName() << " for "
	<< arnold.getHours() << " hours:" << endl;
	arnold.printCheck();

	cout << endl << endl << endl;

	arnold.giveRaise(5);
	cout << "Check for " << arnold.getName() << " for "
	<< arnold.getHours() << " hours:" << endl;
	arnold.printCheck(); 

	cout << endl << endl << endl;

	// salariedEmp sally("Sally Wu", "345123456", 1234.45);    
	// cout << "Check for " << sally.getName() << endl;
	// sally.printCheck();

	// cout << endl << endl << endl;

	// sally.giveRaise(10);
	// cout << endl << endl << endl;
	// cout << "after a raise of 10, Sally's check:" << endl;
	// sally.printCheck();
} 