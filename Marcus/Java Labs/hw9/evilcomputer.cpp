
#include <string>
#include <cstdlib>
#include <iostream>
#include "evilcomputer.h"

using namespace std;

// Creates a computer with five accounts whose passwords (except for Guest) are received through the parameter list
EvilComputer::EvilComputer(string dave_pw, string mr_mean_pw, string ms_chief_pw, string dr_evil_pw)
{
	for (int i = 0; i < 5; ++i)
		hacked[i] = false;
	passwords[index("Guest")] = "passw123";
	passwords[index("Dave")] = dave_pw;
	passwords[index("Mr. Mean")] = mr_mean_pw;
	passwords[index("Ms. Chief")] = ms_chief_pw;
	passwords[index("Dr. Evil")] = dr_evil_pw;
}

// Creates a computer with five accounts and generates their passwords
EvilComputer::EvilComputer()
{
	string password;
	unsigned int length;

// Initializes hacked[] to no account hacked
	for (int i = 0; i < 5; ++i)
		hacked[i] = false;

// Generates password for account Guest
	passwords[index("Guest")] = "passw123";

// Generates password for account Dave
	password = "";
	while (password.length() < 4)
		password += '0' + rand() % 10;
	passwords[index("Dave")] = password;

// Generates password for account Mr. Mean
	password = "";
	length = 1 + rand() % 8;
	while (password.length() < length)
	{
		if (rand() % 2)
			password += 'g';
		else
			password += 'r';
	}
	passwords[index("Mr. Mean")] = password;

// Generates password for account Ms. Chief
	password = "haha";
	length = 1 + rand() % 8;
	while (password.length() < length)
		password += random_char();
	passwords[index("Ms. Chief")] = password;

// Generates password for account Dr. Evil
	password = "";
	length = 4 + rand() % 5;
	while (password.length() < length - 4)
		password += random_char();
	if (rand() % 2 == 0)
		password = "gato" + password;
	else
		password = password + "gato";
	passwords[index("Dr. Evil")] = password;
}

// Generates a random single character 
char EvilComputer::random_char()
{
	char c = rand() % 36;
	if (c < 10)
		c += 48;	// generates a digit 0..9
	else
		c += 87;	// generates a letter a..z
	return c;
}

// Guesses a password for an account.
void EvilComputer::guess(string user, string guess)
{
	if (guess == passwords[index(user)])	// if the password guessed for an account is correct
		hacked[index(user)] = true;			//    updates the account's corresponding element in array hacked[]
}

// Returns whether an account's password has been correctly guessed.
bool EvilComputer::is_hacked(string user)
{
	return hacked[index(user)];
}

// Returns the corresponding index for the account received
int EvilComputer::index(string user)
{
	if (user == "Mr. Mean")
		return 0;
	else if (user == "Ms. Chief")
		return 1;
	else if (user == "Dr. Evil")
		return 2;
	else if (user == "Dave")
		return 3;
	else if (user == "Guest")
		return 4;
	return -1;
}




