#ifndef RPN_CALC_H
#define RPN_CALC_H
#include <string>
#include "GenStack.h"

using namespace std;

class RPNCalc{
public:
	RPNCalc();
	~RPNCalc();
	void calculate(string& operand);
};
#endif
