#include "DNAComplement.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Dna::Dna(){
}

Dna::~Dna(){
}

string Dna::compute(string userFilePath){
	string complement, line;
	GenStack<string> dnaStack;

	ifstream inFile(userFilePath);

	if (inFile.is_open()){
		while(getline(inFile, line)){
			//push the line to  stack
			inFile >> line;
			dnaStack.push(line);

			for (int i = 0; i < line.length(); i++) {
				if (line[i] == 'A') {
					complement += "T";
				}
				else if (line[i] == 'T') {
					complement += "A";
				}
				else if (line[i] == 'C') {
					complement += "G";
				}
				else if (line[i] == 'G') {
					complement += "C";
				}
			}
			//push the complement
			dnaStack.push(complement);
			//call the reverse function and then push it on top
			dnaStack.push(reverse(complement));
		}
		//close infile
		inFile.close();
		//let user know where the file is going
		cout << "Writing to file dnaoutput.txt..." << endl;
		//open the outfile
		ofstream outFile;
		outFile.open("dnaoutput.txt");
		outFile << "Sequence: " << line << endl;
		outFile << "Complement: " << complement  << " " << endl;
		outFile << "Reverse complement: " << reverse(complement) << " " << endl;
		//close outfile
		outFile.close();
	}
	else{
		cout << "Error. Unable to open " << userFilePath << endl;
	}
	return complement;
}

string Dna::reverse(const string& complement){
	string reverse;
	GenStack<char> revStack;

	for (int i = 0; i < complement.size(); i++){
		//get the complement on the top of stack
		revStack.push(complement[i]);
	}
	while (!revStack.isEmpty()){
		//while not empty pop the top of stack
		reverse += revStack.pop();
	}

	//open the ouputfile and append the reverse to the end of file
	/*ofstream outFile("dnaoutput.txt", ios::app);

	int reverse = complement.length();
	int n = reverse - 1;
	for (int i = 0; i < (reverse/2); i++){
		swap(complement[i], complement[n]);
		n = n - 1;
	}
	outFile.open("dnaoutput.txt");
	outFile << "Reverse Complement: " << complement << endl;


	outFile << "Reverse complement: " << complement << endl;
	outFile.close();*/

	return reverse;
}
