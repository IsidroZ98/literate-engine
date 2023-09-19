
#ifndef EVILCOMPUTER_H
#define EVILCOMPUTER_H

#include <string>

using namespace std;


class EvilComputer
{
	public:
		// Creates a computer with five accounts and generates their passwords
		EvilComputer();

		// Creates a computer with five accounts whose passwords (except for Guest) are received through the parameter list
		EvilComputer(string dave_pw, string mr_mean_pw, string ms_chief_pw, string dr_evil_pw);

		// Guesses a password for an account.
		void guess(string user, string guess);

		// Returns whether an account's password has been correctly guessed.
		bool is_hacked(string user);

	private:

		// Returns the corresponding index for the account received
		int index(string user);

		// Generates a random single character 
		char random_char();

		// Holds the passwords for each account
		string passwords[5];

		// Holds information for each account regarding whether it was hacked (true) or not (false)
		bool hacked[5];
};

#endif

