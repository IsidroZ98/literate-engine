#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

char random_char()
{
	char c = rand() % 36;
	if (c < 10)
		c += 48;
	else
		c += (97 - 10);
	return c;
}

int main()
{
	char ans = 'y';
	while (ans == 'y')
	{
		srand(static_cast<unsigned int>(time(NULL)));
		string passwords[5];
		bool hacked[5];

		for (int i = 0; i < 5; ++i)
			hacked[i] = false;

		passwords[0] = "passw123";

		string password;
		unsigned int length;

		password = "";
		while (password.length() < 4)
			password += '0' + (rand() % 10);
		passwords[1] = password;

		password = "";
		length = 1 + rand() % 8;
		while (password.length() < length)
		{
			if (rand() % 2)
				password += 'g';
			else
				password += 'r';
		}
		passwords[2] = password;

		password = "haha";
		length = 1 + rand() % 8;
		while (password.length() < length)
			password += random_char();
		passwords[3] = password;

		password = "";
		length = 4 + rand() % 5;
		while (password.length() < length - 4)
			password += random_char();
		if (rand() % 2 == 0)
			password = "gato" + password;
		else
			password = password + "gato";
		passwords[0] = password;

		for (int x = 0; x < 4; ++x)
			cout << passwords[x] << endl;
		cout << "More?: ";
		cin >> ans;
	}

	return 0;
}
