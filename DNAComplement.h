#ifndef DNA_H
#define DNA_H
#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"

using namespace std;

class Dna{
public:
	Dna();
	~Dna();
	string compute(string userFilePath);
	string reverse(const string& complement);
};
#endif
