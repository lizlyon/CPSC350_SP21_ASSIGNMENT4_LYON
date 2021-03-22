#ifndef DNA_H
#define DNA_H

#include <iostream>
#include <fstream>
#include <string>

#include "Stack.h"
using namespace std;

class Dna {

public:
	string compute(string userFilePath);
	string reverse(const string& complement);
	
};
#endif
