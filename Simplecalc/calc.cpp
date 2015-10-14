/*
 * calc.cpp
 *
 *  Created on: 23.09.2015
 *      Author: hsr
 */
#include "calc.h"
#include <iostream>

int calc(int const i1, int const i2, char const c1)
{
	switch(c1)
	{
	case '+':
		return i1+i2;
	case '-':
		return i1-i2;
	case '*':
		return i1*i2;
	case '/':
		if(i2==0){
			return 1000000;
		}
		return i1/i2;
	case '%':
		if(i2==0){
			return 1000000;
		}
		return i1%i2;
	default:
		return 1000000;
	}
}

int calc(std::istream& in)
{
	int i1;
	int i2;
	char c1;

	in>>i1;
	in>>c1;
	in>>i2;

	return calc(i1,c1,i2);
}
