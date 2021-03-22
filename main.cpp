#include <iostream>
#include <fstream>
#include <string>
#include "DNA.h"
#include "RPNCalc.h"

using namespace std;

int main(){
	string user;
	//error check
	do{
		cout << "Enter 'RPN' or 'DNA': ";
		getline(cin, user);

		if ((!(user == "RPN" || user == "DNA" || user == "rpn" || user == "dna")))
			cout << "Error!  Please enter either 'RPN' or 'DNA'!" << endl << endl;
	}
	while (!(user == "RPN" || user == "DNA" || user == "rpn" || user == "dna"));

	if (user == "DNA" || user == "dna"){
		string userFile;
		cout << "Enter the file path: " ;
		getline(cin, userFile);
		//create object
		Dna dna;
		//call the compute function
		dna.compute(userFile);
	}

	if (user == "RPN" || user == "rpn") {
		string operand;
		cout << "Welcome to RPN" << endl;
		cout << "Please enter the operation: ";
		//get the console input from user
		getline(cin, operand);
		//create object
		RPNCalc calc;
		//call the calculate function
		calc.calculate(operand);
		//cout << "Total: " << calc.calculate(operand) << endl;
	}
	return 0;
}
