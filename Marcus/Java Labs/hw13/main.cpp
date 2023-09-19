
#include <iostream>
#include <string>
#include <cstdlib>
#include "loginserver.h"

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
	LoginServer ls;
	
	// Test total_user_count(), create_user()
	test(ls.total_user_count() == 0);
	test(ls.create_user("Ernesto", "p455w0rd"));
	test(ls.total_user_count() == 1);
	test(ls.create_user("Ruby", "QwErTy123"));
	test(ls.total_user_count() == 2);
	test(ls.create_user("Hugo", "1l0v3c4t5"));
	test(ls.total_user_count() == 3);
	test(ls.create_user("Margo", "Din0s4ur5!"));
	test(ls.total_user_count() == 4);
	test(ls.create_user("Berta", "!sc00p0f00d!"));
	test(ls.total_user_count() == 5);

	test(!ls.create_user("Berta", "anotherp455"));
	test(ls.total_user_count() == 5);
	
	test(ls.delete_user("Berta", "!sc00p0f00d!"));
	test(ls.total_user_count() == 4);
	test(!ls.delete_user("Ernesto", "wrongpassword"));
	test(ls.total_user_count() == 4);
	test(!ls.delete_user("Ernesto", "Din0s4ur5!"));
	test(ls.total_user_count() == 4);
	test(!ls.delete_user("Berta", "!sc00p0f00d!"));
	test(ls.total_user_count() == 4);

	test(ls.create_user("Berta", "!sc00p0f00d!"));
	test(ls.total_user_count() == 5);


	// Test login(), logout(), is_logged_in()
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	
	test(!ls.is_logged_in("Unknown"));

	test(ls.login("Ernesto", "p455w0rd"));
	test(ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	

	test(ls.logout("Ernesto"));
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	

	test(ls.login("Ruby", "QwErTy123"));
	test(ls.login("Hugo", "1l0v3c4t5"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	

	test(ls.logout("Ruby"));
	test(ls.logout("Hugo"));
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	

	test(ls.login("Ruby", "QwErTy123"));
	test(ls.login("Berta", "!sc00p0f00d!"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(ls.is_logged_in("Berta"));	

	// Test logging in with wrong password
	test(!ls.login("Margo", "idontknow"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(ls.is_logged_in("Berta"));	

	// Test logging in when already logged in
	test(!ls.login("Ruby", "QwErTy123"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(ls.is_logged_in("Berta"));	

	// Test logging in a user that doesn't exist
	test(!ls.login("Stranger", "Question!"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(ls.is_logged_in("Berta"));	

	// Test logging out someone not logged in
	test(!ls.logout("Hugo"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(ls.is_logged_in("Berta"));	

	// Test logging out a user that doesn't exist
	test(!ls.logout("Stranger"));
	test(!ls.is_logged_in("Ernesto"));	
	test(ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(ls.is_logged_in("Berta"));	

	test(ls.logout("Ruby"));
	test(ls.logout("Berta"));
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	


	// Test active_user_count()
	test(ls.active_user_count() == 0);	
	ls.login("Ernesto", "p455w0rd");
	test(ls.active_user_count() == 1);	
	ls.login("Ruby", "QwErTy123");
	test(ls.active_user_count() == 2);	
	ls.login("Berta", "!sc00p0f00d!");
	test(ls.active_user_count() == 3);	
	ls.login("Berta", "!sc00p0f00d!"); // Already logged in
	test(ls.active_user_count() == 3);	
	ls.login("Berta", "!3x3rc1s3!");   // Wrong password
	test(ls.active_user_count() == 3);	
	ls.login("Stranger", "_Secret_");  // Not a user
	test(ls.active_user_count() == 3);	
	ls.logout("Berto");                // Not a user
	test(ls.active_user_count() == 3);	
	ls.logout("Margo");                // Not logged in
	test(ls.active_user_count() == 3);	
	ls.logout("Berta");
	test(ls.active_user_count() == 2);	
	ls.logout("Ernesto");
	test(ls.active_user_count() == 1);
	ls.logout("Ruby");
	test(ls.active_user_count() == 0);
	ls.logout("Berta");               // Not logged in
	test(ls.active_user_count() == 0);

	
	// Test logout_everyone()	
	ls.login("Ernesto", "p455w0rd");
	ls.login("Ruby", "QwErTy123");
	ls.login("Hugo", "1l0v3c4t5");
	ls.login("Margo", "Din0s4ur5!");
	ls.login("Berta", "!sc00p0f00d!");
	ls.logout_everyone();	
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	
	test(ls.active_user_count() == 0);

	ls.login("Margo", "Din0s4ur5!");
	ls.login("Berta", "!sc00p0f00d!");
	ls.logout_everyone();
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	
	test(ls.active_user_count() == 0);

	ls.logout_everyone();
	test(!ls.is_logged_in("Ernesto"));	
	test(!ls.is_logged_in("Ruby"));	
	test(!ls.is_logged_in("Hugo"));	
	test(!ls.is_logged_in("Margo"));	
	test(!ls.is_logged_in("Berta"));	
	test(ls.active_user_count() == 0);


	// Test change_password()
	test(ls.login("Ernesto", "p455w0rd"));
	ls.logout("Ernesto");
	test(!ls.login("Ernesto", "p455w0rd!"));
	test(!ls.login("Ernesto", "d1ff3r3nt!"));

	ls.change_password("Ernesto", "p455w0rd", "p455w0rd!");

	test(!ls.login("Ernesto", "p455w0rd"));
	test(ls.login("Ernesto", "p455w0rd!"));
	ls.logout("Ernesto");
	test(!ls.login("Ernesto", "d1ff3r3nt!"));

	ls.change_password("Ernesto", "p455w0rd!", "d1ff3r3nt!");

	test(!ls.login("Ernesto", "p455w0rd"));
	test(!ls.login("Ernesto", "p455w0rd!"));
	test(ls.login("Ernesto", "d1ff3r3nt!"));
	ls.logout("Ernesto");

	test(!ls.change_password("Ernesto", "wr0ng", "wr0ng2")); 

	test(!ls.login("Ernesto", "p455w0rd"));
	test(!ls.login("Ernesto", "p455w0rd!"));
	test(ls.login("Ernesto", "d1ff3r3nt!"));
	ls.logout("Ernesto");

	test(!ls.change_password("Ernesto", "p455w0rd", "wr0ng2")); 

	test(!ls.login("Ernesto", "p455w0rd"));
	test(!ls.login("Ernesto", "p455w0rd!"));
	test(ls.login("Ernesto", "d1ff3r3nt!"));
	ls.logout("Ernesto");

	// Try to change the password of a user that doesn't exist
	test(!ls.change_password("Stranger", "Question!", "Question!2"));
	test(!ls.is_logged_in("Stranger"));
	test(ls.total_user_count() == 5);
	test(!ls.login("Stranger", "Question!"));
	test(!ls.login("Stranger", "Question!2"));
	
	
	// Test delete_user()
	test(ls.login("Ernesto", "d1ff3r3nt!"));
	test(ls.is_logged_in("Ernesto"));						// is logged-in
	test(ls.delete_user("Ernesto", "d1ff3r3nt!"));
	test(ls.total_user_count() == 4);
	test(!ls.is_logged_in("Ernesto"));						// is not logged-in anymore

	test(!ls.is_logged_in("Margo"));						// is not logged-in
	test(ls.delete_user("Margo", "Din0s4ur5!"));
	test(ls.total_user_count() == 3);

	// Try to delete a user by giving the wrong password
	test(ls.login("Ruby", "QwErTy123"));
	test(ls.is_logged_in("Ruby"));							// is logged-in
	test(!ls.delete_user("Ruby", "NoErTy345"));
	test(ls.total_user_count() == 3);
	test(ls.is_logged_in("Ruby"));							// is still logged-in
	ls.logout("Ruby");
	test(ls.login("Ruby", "QwErTy123"));					// account is still active
	ls.logout("Ruby");

	// Try to delete users that don't exist
	test(!ls.delete_user("Unknown", "p455w0rd"));	
	test(ls.total_user_count() == 3);

	test(!ls.delete_user("Ernesto", "d1ff3r3nt!"));	
	test(ls.total_user_count() == 3);


	cout << "Assignment complete." << endl;
}



