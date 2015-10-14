#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <iostream>

//Calc tests
void regularFunctions() {
	ASSERT_EQUAL(5, calc(2,3,'+'));
	ASSERT_EQUAL(5, calc(7,2,'-'));
	ASSERT_EQUAL(8, calc(2,4,'*'));
	ASSERT_EQUAL(2, calc(6,3,'/'));
}
void edgeCases() {
	ASSERT_EQUAL(1000000, calc(5,0,'/'));
	ASSERT_EQUAL(0, calc(6,0,'*'));
	ASSERT_EQUAL(1000000, calc(3,5,'a'));
	ASSERT_EQUAL(1000000, calc(6,0,'%'));
	ASSERT_EQUAL(1000000, calc(10000,10,'*'));
}

//Sevensegment tests
void test_zero() {
	std::ostringstream out{};
	printLargeDigit(0, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"| |\n"
								"   \n"
								"| |\n"
								" - \n"},out.str());
}
void test_one() {
	std::ostringstream out{};
	printLargeDigit(1, out);
	ASSERT_EQUAL(std::string{	"   \n"
								"  |\n"
								"   \n"
								"  |\n"
								"   \n"},out.str());
}
void test_two() {
	std::ostringstream out{};
	printLargeDigit(2, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"  |\n"
								" - \n"
								"|  \n"
								" - \n"},out.str());
}
void test_three() {
	std::ostringstream out{};
	printLargeDigit(3, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"  |\n"
								" - \n"
								"  |\n"
								" - \n"},out.str());
}
void test_four() {
	std::ostringstream out{};
	printLargeDigit(4, out);
	ASSERT_EQUAL(std::string{	"   \n"
								"| |\n"
								" - \n"
								"  |\n"
								"   \n"},out.str());
}
void test_five() {
	std::ostringstream out{};
	printLargeDigit(5, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"|  \n"
								" - \n"
								"  |\n"
								" - \n"},out.str());
}
void test_six() {
	std::ostringstream out{};
	printLargeDigit(6, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"|  \n"
								" - \n"
								"| |\n"
								" - \n"},out.str());
}
void test_seven() {
	std::ostringstream out{};
	printLargeDigit(7, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"  |\n"
								"   \n"
								"  |\n"
								"   \n"},out.str());
}
void test_eight() {
	std::ostringstream out{};
	printLargeDigit(8, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"| |\n"
								" - \n"
								"| |\n"
								" - \n"},out.str());
}
void test_nine() {
	std::ostringstream out{};
	printLargeDigit(9, out);
	ASSERT_EQUAL(std::string{	" - \n"
								"| |\n"
								" - \n"
								"  |\n"
								" - \n"},out.str());
}
void test_ten() {
	std::ostringstream out{};
	printLargeNumber(10, out);
	ASSERT_EQUAL(std::string{	"    - \n"
								"  || |\n"
								"      \n"
								"  || |\n"
								"    - \n"},out.str());
}
void test_eightyeight() {
	std::ostringstream out{};
	printLargeNumber(88, out);
	ASSERT_EQUAL(std::string{	" -  - \n"
								"| || |\n"
								" -  - \n"
								"| || |\n"
								" -  - \n"}, out.str());
}
void test_999() {
	std::ostringstream out{};
	printLargeNumber(999, out);
	ASSERT_EQUAL(std::string{	" -  -  - \n"
								"| || || |\n"
								" -  -  - \n"
								"  |  |  |\n"
								" -  -  - \n"}, out.str());
}

//pocketcalculator test
void test_stringinp(){
	std::ostringstream out{};
	std::istringstream in{"2+3"};
	pocketcalculator(in,out);
	ASSERT_EQUAL(std::string{	""}, out.str());
}



void runAllTests(int argc, char const *argv[]){
	cute::suite s;

	s.push_back(CUTE(regularFunctions));
	s.push_back(CUTE(edgeCases));

	s.push_back(CUTE(test_zero));
	s.push_back(CUTE(test_one));
	s.push_back(CUTE(test_two));
	s.push_back(CUTE(test_three));
	s.push_back(CUTE(test_four));
	s.push_back(CUTE(test_five));
	s.push_back(CUTE(test_six));
	s.push_back(CUTE(test_seven));
	s.push_back(CUTE(test_eight));
	s.push_back(CUTE(test_nine));
	s.push_back(CUTE(test_ten));
	s.push_back(CUTE(test_eightyeight));
	s.push_back(CUTE(test_999));

	s.push_back(CUTE(test_stringinp));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



