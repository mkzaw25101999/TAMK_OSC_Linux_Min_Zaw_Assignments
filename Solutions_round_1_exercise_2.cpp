#include <iostream>
using namespace std;

int main() {
	int num1, num2;


	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	int addition = num1 + num2;
	int subtraction = num1 - num2;
	int multiplication = num1 * num2;
	int division = num1 / num2;

	cout << "Addition: " << addition << endl;
	cout << "Subtraction: " << subtraction << endl;
	cout << "Multiplication: " << multiplication << endl;
	cout << "Division: " << division << endl;
	
	return 0;
}

