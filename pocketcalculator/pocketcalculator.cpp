/*
 * pocketcalculator.cpp
 *
 *  Created on: 07.10.2015
 *      Author: hsr
 */

#include "calc.h"
#include "sevensegment.h"

#include <iostream>
#include <string>
#include <sstream>

void pocketcalculator(std::istream &in){
	std::string inputstring;
	std::getline(in, inputstring);

	std::istringstream inpstrstream{inputstring};
	int result=calc(inpstrstream);

	std::ostringstream out{};
	printLargeNumber(result, out);
}
