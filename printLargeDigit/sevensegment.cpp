/*
 * printLargeDigit.cpp
 *
 *  Created on: 30.09.2015
 *      Author: Walder Philipp
 *      Prints a single large 7-segment digit over 5 lines
 */
#include "sevensegment.h"

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

	std::vector<std::string> const zero{" - ","| |","","| |"," - "};
	std::vector<std::string> const one{"","  |","","  |",""};
	std::vector<std::string> const two{" - ","  |"," - ","|  "," - "};
	std::vector<std::string> const three{" - ","  |"," - ","  |"," - "};
	std::vector<std::string> const four{"","| |"," - ","  |",""};
	std::vector<std::string> const five{" - ","|  "," - ","  |"," - "};
	std::vector<std::string> const six{" - ","|  "," - ","| |"," - "};
	std::vector<std::string> const seven{" - ","  |","","  |",""};
	std::vector<std::string> const eight{" - ","| |"," - ","| |"," - "};
	std::vector<std::string> const nine{" - ","| |"," - ","  |"," - "};
	std::vector<std::vector<std::string>> const DIGITS{zero, one, two, three, four, five, six, seven, eight, nine};

	std::vector<std::string> const E{" - ","|  "," - ","|  "," - "};
	std::vector<std::string> const r{"   ","   "," - ","|  ","   "};
	std::vector<std::string> const o{"   ","   "," - ","| |"," - "};
	std::vector<std::vector<std::string>> const Error{E,r,r,o,r};


void printLargeDigit(int i, std::ostream &out) {
	std::vector<std::vector<std::string>> const DIGITS{zero, one, two, three, four, five, six, seven, eight, nine};
	std::ostream_iterator<std::string> const output(out, "\n");
	copy(begin(DIGITS[i]), end(DIGITS[i]), output);
}

void printLargeNumber(int i, std::ostream &out){
	std::vector<std::vector<std::string>> largeNumber{};
	if(i>99999){
		for(int j=0; j<5;j++){
			largeNumber[j]=Error[j];
		}
	}else{
		int count=0;
		while(i>1){
			int j=i%10;
			largeNumber[count]=DIGITS[j];
			count++;
		}
	}
	std::vector<std::string> outNumber(5);
	for(int i=0;i<5;i++){
		for_each(begin(largeNumber), end(largeNumber), [&outNumber, &i] (auto k){
			outNumber[i]=k[i];
		});
	}
	std::ostream_iterator<char> const output(out, "\n");
	for(int i=0; i<5;i++){
		std::copy(std::begin(outNumber[i]), std::end(outNumber[i]), output);
	}
}



