
#include <cassert>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "deque.h"

using namespace std;


// Testing stuff; just ignore it :)
inline void _test(const char* expression, const char* file, int line)
{
        cerr << "test(" << expression << ") failed in file " << file << ", line " << line << "." << endl;
        abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))
// End of testing stuff


int main() 
{
	Deque d; // []
	test(d.size() == 0);

	d.push_front("hello"); // ["hello"]
	test(d.front() == "hello");
	test(d.back() == "hello");
	test(d.size() == 1);

	d.push_front("dog"); // ["hello", "dog"]
	test(d.size() == 2);
	test(d.front() == "dog");
	test(d.back() == "hello");

	d.push_front("phone"); // ["hello", "dog", "phone"]
	test(d.size() == 3);
	test(d.front() == "phone");
	test(d.back() == "hello");

	d.pop_front(); // ["hello", "dog"]
	test(d.size() == 2);
	test(d.front() == "dog");
	test(d.back() == "hello");
	
	d.push_back("cat"); // ["cat", "hello", "dog"]
	test(d.size() == 3);
	test(d.front() == "dog");
	test(d.back() == "cat");

	d.push_back("goodbye"); // ["goodbye", "cat", "hello", "dog"]
	test(d.size() == 4);
	test(d.front() == "dog");
	test(d.back() == "goodbye");

	d.pop_front(); // ["goodbye", "cat", "hello"]
	test(d.size() == 3);
	test(d.front() == "hello");
	test(d.back() == "goodbye");

	d.pop_back(); // ["cat", "hello"]
	test(d.size() == 2);
	test(d.front() == "hello");
	test(d.back() == "cat");

	d.pop_back(); // ["hello"]
	test(d.size() == 1);
	test(d.front() == "hello");
	
	d.pop_back(); // []
	test(d.size() == 0);
	
	// Test popping off empty deque	
	for (int i = 0; i < 100; ++i)
	{
		test(d.size() == 0);
		d.pop_back();
		d.back();
		d.pop_front();
		d.front();
	}

	cout << "Testing complete." << endl;
	system("pause");
        /*
	// Time how long pop_front()ing and pop_back()ing takes 
	cout << setw(10) << "Size" << setw(10) << "pop_front" << setw(10) << "pop_back" << endl;
	for (int l = 1000; l <= 100000; l += 1000)
	{
		Deque d;
		for (int i = 0; i < l; ++i) // Fill deque
			d.push_back("dog");	

		clock_t start = clock();	
		for (int i = 0; i < l; ++i)		// empty deque at front
			d.pop_front();
		clock_t end = clock();
		float pop_front_elapsed_time = static_cast<float>(end - start) / CLOCKS_PER_SEC;
		cout << setw(10) << l << setw(10) << pop_front_elapsed_time;

		assert(d.size() == 0);
		for (int i = 0; i < l; ++i) // Fill deque
			d.push_back("dog");	
		
		start = clock();
		for (int i = 0; i < l; ++i)		// empty deque at back
			d.pop_back();
		end = clock();
		float pop_back_elapsed_time = static_cast<float>(end - start) / CLOCKS_PER_SEC;
		cout << setw(10) << pop_back_elapsed_time << endl;

	}
        */
	return 0;
}




