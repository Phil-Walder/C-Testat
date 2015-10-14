/*
 * main.cpp
 *
 *  Created on: 08.10.2015
 *      Author: hsr
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "pocketcalculator.h"
#include "sevensegment.h"
#include "calc.h"


int main (){
	while(std::cin) {
		std::cout << '=';
		pocketcalculator(std::cin);
		std::cout << '\n';
	}
}
