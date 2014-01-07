/*
	Author: Leonard A. Kelley III
	Class: CSI 140 - 01
	Description: The purpose of this class is for input validation.
				 This way I can test the input and return a T/F to whatever called these functions.

	Certification of Authenticity:
	I certify that this assignment is entirely my own work.
*/

#include "InputValidation.h"

//Initalize Static Const Variables
const regex InputValidation::R_INT("^[-]?([0-9]+)?$");
const regex InputValidation::R_CHAR("^([a-z]|[A-Z]|[0-9])?$");
const regex InputValidation::R_DOUBLE("^[-]?([0-9]+\\.[0-9]+|\\.[0-9]+|[0-9]+)?$");

/* 
   Pre: None
   Post: It will pass a true or false to whatever called the function.
   Purpose: Validate if the input that was passed to the function was a int and if it can be negative or not.
*/
bool InputValidation::ISINT(string Input, bool AllowNegative)
{
	bool result;
	//IF the input matches the regex output true, otherwise output false.
	if (regex_match(Input.begin(), Input.end(), R_INT) && Input != "")
	{
		if(!AllowNegative && atoi(Input.c_str()) < 0)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}
	else
	{
		result = false;
	}

	return result;
}

/* 
   Pre: None
   Post: It will pass a true or false to whatever called the function.
   Purpose: Validate if the input that was passed to the function was a double/float 
   and if it can be a negative or not.
*/
bool InputValidation::ISDOUBLE(string Input, bool AllowNegative)
{
	bool result;

	//IF the input matches the regex output true, otherwise output false.
	if(regex_match(Input.begin(),Input.end(),R_DOUBLE) && Input != "")
	{
		if(!AllowNegative && atoi(Input.c_str()) < 0)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}
	else
	{
		result = false;
	}

	return result;
}

/* 
   Pre: None
   Post: It will pass a true or false to whatever called the function.
   Purpose: Validate if the input that was passed to the function was a char and if it matched the letter(s) 
   it was expecting
*/
bool InputValidation::ISCHAR(string Input, string Values, bool CaseSensitive)
{
	bool result = false;
	
	//Allow only letters to be inputted and they must match the two choices that are supplied.
	if(regex_match(Input.begin(),Input.end(),R_CHAR))
	{
		if(CaseSensitive)
		{
			for(string::size_type i = 0; i < Values.size(); ++i)
			{
				result = (Input[0] == Values[i]);
				if(result == true) return result;
			}
		}
		else
		{
			for(string::size_type i = 0; i < Values.size(); ++i)
			{
				result = (toupper(Input[0]) == Values[i]);
				if(result == true) return result;
			}
		}
	}
	else
	{
		result = false;
	}
	
	return result;
}