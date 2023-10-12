#include <string>
#include <cstdlib>
#include <iostream>
#include "canvas.h"

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

	// Test Canvas(int)

	Canvas C0(0);
	test(C0.width() == 0);
	test(C0.to_string() == string(""));

	Canvas C1(3);
	test(C1.width() == 3);
	test(C1.to_string() == string("   \n") 
	                            + "   \n"
	                            + "   \n"
	                            + "   \n"
	                            + "   \n");
	Canvas C2(4);
	test(C2.width() == 4);
	test(C2.to_string() == string("    \n")
	                            + "    \n"
	                            + "    \n"
	                            + "    \n"
	                            + "    \n");
	Canvas C3(7);
	test(C3.width() == 7);
	test(C3.to_string() == string("       \n")
	                            + "       \n"
	                            + "       \n"
	                            + "       \n"
	                            + "       \n");


	// Test Canvas(char)
	Canvas C4('A');
	test(C4.width() == 5);
	test(C4.to_string() == string(" ### \n")
	                            + "#   #\n"
	                            + "#####\n"
	                            + "#   #\n"
	                            + "#   #\n");
	Canvas C5('B');
	test(C5.width() == 5);
	test(C5.to_string() == string("#### \n")
	                            + "#   #\n"
	                            + "#### \n"
	                            + "#   #\n"
	                            + "#### \n");
	Canvas C6('C');
	test(C6.width() == 5);
	test(C6.to_string() == string(" ####\n")
	                            + "#    \n"
	                            + "#    \n"
	                            + "#    \n"
	                            + " ####\n");
	Canvas C7('D');
	test(C7.width() == 5);
	test(C7.to_string() == string("#### \n")
	                            + "#   #\n"
	                            + "#   #\n"
	                            + "#   #\n"
	                            + "#### \n");
	Canvas C8('E');
	test(C8.width() == 5);
	test(C8.to_string() == string("     \n")
	                            + "     \n"
	                            + "     \n"
	                            + "     \n"
	                            + "     \n");


	// Test replace()
	C5.replace('#', '@');
	test(C5.width() == 5);
	test(C5.to_string() == string("@@@@ \n")
	                            + "@   @\n"
	                            + "@@@@ \n"
	                            + "@   @\n"
	                            + "@@@@ \n");
	C5.replace(' ', '-');
	test(C5.width() == 5);
	test(C5.to_string() == string("@@@@-\n")
	                            + "@---@\n"
	                            + "@@@@-\n"
	                            + "@---@\n"
	                            + "@@@@-\n");
	C5.replace('-', '@');
	test(C5.width() == 5);
	test(C5.to_string() == string("@@@@@\n")
	                            + "@@@@@\n"
	                            + "@@@@@\n"
	                            + "@@@@@\n"
	                            + "@@@@@\n");
	C5.replace('@', '$');
	test(C5.width() == 5);
	test(C5.to_string() == string("$$$$$\n")
	                            + "$$$$$\n"
	                            + "$$$$$\n"
	                            + "$$$$$\n"
	                            + "$$$$$\n");
	C6.replace(' ', '*');
	test(C6.width() == 5);
	test(C6.to_string() == string("*####\n")
	                            + "#****\n"
	                            + "#****\n"
	                            + "#****\n"
	                            + "*####\n");
	C7.replace('#', '*');
	test(C7.width() == 5);
	test(C7.to_string() == string("**** \n")
	                            + "*   *\n"
	                            + "*   *\n"
	                            + "*   *\n"
	                            + "**** \n");
	C8.replace('#', ' ');
	test(C8.width() == 5);
	test(C8.to_string() == string("     \n")
	                            + "     \n"
	                            + "     \n"
	                            + "     \n"
	                            + "     \n");


	// Test add()	
	Canvas C9('A');
	C9.add('C');
	test(C9.width() == 12);	
	test(C9.to_string() == string(" ###    ####\n")
	                             + "#   #  #    \n"
	                             + "#####  #    \n"
	                             + "#   #  #    \n"
	                             + "#   #   ####\n");
	C9.add('B');
	test(C9.width() == 19);	
	test(C9.to_string() == string(" ###    ####  #### \n")
	                            + "#   #  #      #   #\n"
	                            + "#####  #      #### \n"
	                            + "#   #  #      #   #\n"
	                            + "#   #   ####  #### \n");
	C9.add('D');
	test(C9.width() == 26);	
	test(C9.to_string() == string(" ###    ####  ####   #### \n")
	                            + "#   #  #      #   #  #   #\n"
	                            + "#####  #      ####   #   #\n"
	                            + "#   #  #      #   #  #   #\n"
	                            + "#   #   ####  ####   #### \n");
	C9.add('!');
	test(C9.width() == 33);	
	test(C9.to_string() == string(" ###    ####  ####   ####        \n")
	                            + "#   #  #      #   #  #   #       \n"
	                            + "#####  #      ####   #   #       \n"
	                            + "#   #  #      #   #  #   #       \n"
	                            + "#   #   ####  ####   ####        \n");
	C9.add('C');
	test(C9.width() == 40);	
	test(C9.to_string() == string(" ###    ####  ####   ####           ####\n")
	                            + "#   #  #      #   #  #   #         #    \n"
	                            + "#####  #      ####   #   #         #    \n"
	                            + "#   #  #      #   #  #   #         #    \n"
	                            + "#   #   ####  ####   ####           ####\n");


	Canvas C10(0);
	C10.add('A');
	test(C10.width() == 5);
	test(C10.to_string() == string(" ### \n")
		+ "#   #\n"
		+ "#####\n"
		+ "#   #\n"
		+ "#   #\n");

	Canvas C11("");
	C11.add('A');
	test(C11.width() == 5);
	test(C11.to_string() == string(" ### \n")
		+ "#   #\n"
		+ "#####\n"
		+ "#   #\n"
		+ "#   #\n");


	// Test Canvas(string)
	Canvas C12("ADD");
	test(C12.width() == 19);	
	test(C12.to_string() == string(" ###   ####   #### \n")
	                             + "#   #  #   #  #   #\n"
	                             + "#####  #   #  #   #\n"
	                             + "#   #  #   #  #   #\n"
	                             + "#   #  ####   #### \n");
	Canvas C13("VBAD!");
	test(C13.width() == 33);	
	test(C13.to_string() == string("       ####    ###   ####        \n")
	                             + "       #   #  #   #  #   #       \n"
	                             + "       ####   #####  #   #       \n"
	                             + "       #   #  #   #  #   #       \n"
	                             + "       ####   #   #  ####        \n");
	Canvas C14("DAD CAB");
	test(C14.width() == 47);	
	test(C14.to_string() == string("####    ###   ####           ####   ###   #### \n")
	                             + "#   #  #   #  #   #         #      #   #  #   #\n"
	                             + "#   #  #####  #   #         #      #####  #### \n"
	                             + "#   #  #   #  #   #         #      #   #  #   #\n"
	                             + "####   #   #  ####           ####  #   #  #### \n");


	cout << "Assignment complete." << endl;
}





