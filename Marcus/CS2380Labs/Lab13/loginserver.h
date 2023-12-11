
#ifndef LOGINSERVER_H
#define LOGINSERVER_H

#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class LoginServer
{
	public:
		// Creates a new server with no accounts.
		// Tthis function has an empty body since there isn't anything to be done.
		LoginServer();
			
		// Returns false if the LoginServer already has an
		// account with the username received.
		//  Otherwise adds a user to the system with the 
		// username and password received and returns true.
		bool create_user(string username, string password);

		// If the username and password received are valid
		// logs out (if necessary) and deletes the corresponding user,
		// and returns true.
		// Otherwise returns false.
		bool delete_user(string username, string password);

		// Returns the total number of accounts in the system.
		int total_user_count();

		// If the username and password received are valid and
		// and the user is not already logged in, logs in the user
		// and returns true.
		// Otherwise returns false.
		bool login(string username, string password);

		// If a user with this username is logged in,
		// logs out the user and returns true.
		// Otherwise returns false.
		bool logout(string username);

		// Returns true if a user with this username is logged in.
		// Otherwise returns false.
		bool is_logged_in(string username);

		// Returns the number of logged-in users.
		int active_user_count();

		// Logs out all users.
		void logout_everyone();

		// If the username and the old_pw received are valid
		// changes the user's password to new_pw and returns true.
		// Otherwise returns false.
		bool change_password(string username, string old_pw, 
			string new_pw);


	private:
		// Stores the usernames of logged-in users 
		unordered_set<string> S;

		// Stores the mapping from usernames to passwords.
		unordered_map<string, string> M;	
};

#endif

