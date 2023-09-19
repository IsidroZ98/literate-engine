
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "evilcomputer.h"
#include "hack.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
        cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        //abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))



int main()
{
	//*
//	srand(208); // Initialize random number generation
	srand(static_cast<unsigned int>(time(0)));

	// Create five computers with specific passwords 
	EvilComputer ec1("1234", "grrr", "haha0", "gato1");
	EvilComputer ec2("1235", "gggrrr", "haha456", "gato123");
	EvilComputer ec3("2345", "gr", "haha0abc", "123gato");
	EvilComputer ec4("6789", "grggrrrg", "hahaz123", "abc9gato");
	EvilComputer ec5("9999", "rrrrrrrr", "hahahaha", "gatogato");

	// Try to hack each of the five computers
	hack(&ec1);
	hack(&ec2);
	hack(&ec3);
	hack(&ec4);
	hack(&ec5);

	// Test that Guest's account is always hacked
	test(ec1.is_hacked("Guest"));
	test(ec2.is_hacked("Guest"));
	test(ec3.is_hacked("Guest"));
	test(ec4.is_hacked("Guest"));
	test(ec5.is_hacked("Guest"));

	// Test that Dave's account is always hacked
	test(ec1.is_hacked("Dave"));
	test(ec2.is_hacked("Dave"));
	test(ec3.is_hacked("Dave"));
	test(ec4.is_hacked("Dave"));
	test(ec5.is_hacked("Dave"));

	// Test that Mr. Mean's account was always hacked
	test(ec1.is_hacked("Mr. Mean"));
	test(ec2.is_hacked("Mr. Mean"));
	test(ec3.is_hacked("Mr. Mean"));
	test(ec4.is_hacked("Mr. Mean"));
	test(ec5.is_hacked("Mr. Mean"));
	
	// Test that Ms. Chief's account was always hacked
	test(ec1.is_hacked("Ms. Chief"));
	test(ec2.is_hacked("Ms. Chief"));
	test(ec3.is_hacked("Ms. Chief"));
	test(ec4.is_hacked("Ms. Chief"));
	test(ec5.is_hacked("Ms. Chief"));

	// Test that Dr. Evil's account was always hacked
	test(ec1.is_hacked("Dr. Evil"));
	test(ec2.is_hacked("Dr. Evil"));
	test(ec3.is_hacked("Dr. Evil"));
	test(ec4.is_hacked("Dr. Evil"));
	test(ec5.is_hacked("Dr. Evil"));
	//*/

	// Test hacking some "randomly" chosen passwords	
	for (int i = 0; i < 10; ++i)
	{
		// Try to hack all five users with randomly chosen passwords 
		// (matching each user's password rules)
		EvilComputer ec;
		hack(&ec);

		test(ec.is_hacked("Guest"));
		test(ec.is_hacked("Dave"));
		test(ec.is_hacked("Mr. Mean"));
		test(ec.is_hacked("Ms. Chief"));
		test(ec.is_hacked("Dr. Evil"));
	}


	cout << "Assignment complete." << endl;
}



