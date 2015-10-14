/*
 * pocketcalculator.h
 *
 *  Created on: 07.10.2015
 *      Author: hsr
 */

#ifndef POCKETCALCULATOR_H_
#define POCKETCALCULATOR_H_
#include <iosfwd>

int pocketcalculator(int const i1, int const i2, char const c1, std::ostream &out);
int pocketcalculator(std::istream& in, std::ostream &out);

#endif /* POCKETCALCULATOR_H_ */
