#include <iostream>
#include <sstream>
#include "RPNCalc.h"

using namespace std;

RPNCalc::RPNCalc(){
}

RPNCalc::~RPNCalc(){
}

void RPNCalc::calculate(std::string& operand){
	int x, y, total, value;

	//reads in the string expression using istringstream
	istringstream sin(operand);
	GenStack<int> rpnStack;

	//while it's a string expression
	while (sin >> operand) {
		//check if there are digits in the input strating at index 0
		if (isdigit(operand[0])) {
			//convert string value to int
			value = stoi(operand);
			//push the int value to top of stack
			rpnStack.push(value);
		}
		//addition opperation
		else if (operand == "+") {
			x = rpnStack.pop();
			y = rpnStack.pop();
			total = y + x;
			rpnStack.push(total);
		}
		//subtraction opperation
		else if (operand == "-") {
			x = rpnStack.pop();
			y = rpnStack.pop();
			total = y - x;
			rpnStack.push(total);
		}
		//multiplication opperation
		else if (operand == "*") {
			x = rpnStack.pop();
			y = rpnStack.pop();
			total = y * x;
			rpnStack.push(total);
		}
		//division opperation
		else if (operand == "/") {
			x = rpnStack.pop();
			y = rpnStack.pop();
			total = y / x;
			rpnStack.push(total);
		}
		//modulo opperation
		else if (operand == "%") {
			x = rpnStack.pop();
			y = rpnStack.pop();
			total = y / x;
			total *= x;
			total = y - total;
			rpnStack.push(total);
		}
		else {
			//if its not a valid expression
			cout << "Invalid expression." << endl;
		}
	}
	//return result by popping stack
	cout << "Total: " << rpnStack.pop() << endl;
	//cout << "Total: " << calc.calculate(operand) << endl;
}
