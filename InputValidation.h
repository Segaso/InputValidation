#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <stdlib.h>
#include <regex>

using namespace std;

class InputValidation
{
private:
	static const regex R_INT;
	static const regex R_DOUBLE;
	static const regex R_CHAR;

public:
	bool ISINT(string,bool);
	bool ISDOUBLE(string,bool);
	bool ISCHAR(string,string,bool);

};

#endif