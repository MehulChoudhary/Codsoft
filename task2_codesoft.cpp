#include <iostream>
using namespace std;

int main() {
 
  int num1, num2;
  char operator_;

  // input of numbers 
  cout << "Enter the first number: ";
  cin >> num1;
  cout << "Enter the second number: ";
  cin >> num2;

  cout << "Enter the operator (+, -, *, /): ";
  cin >> operator_;

  // Switch statement to perform the desired operation.
  switch (operator_) {
    case '+':
      cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
      break;
    case '-':
      cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
      break;
    case '*':
      cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
      break;
    case '/':
      cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
      break;
    default:
      cout << "Invalid operator." << endl;
  }

  return 0;
}