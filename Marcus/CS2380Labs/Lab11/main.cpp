
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include "sort.h"

using namespace std;
using namespace chrono;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        //abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


// A basic sorting algorithm (merge sort) to compare 
// against your sorting algorithm for correctness and speed.
void benchmark_sort(int* A, int len)
{
	if (len < 2)
		return;
	int halfway = len/2;
	benchmark_sort(A, halfway);
	benchmark_sort(&(A[len/2]), len - halfway);
	int i, j, copied_elements;
	i = 0;
	j = halfway;
	copied_elements = 0;
	int* sorted_A = new int[len];
	while (copied_elements < len)
	{
        if (j == len)
        {
                sorted_A[copied_elements] = A[i];
                ++i;
        }
		else if (i == halfway)
		{
			sorted_A[copied_elements] = A[j];
			++j;
		}
		else if (A[i] < A[j])
		{
			sorted_A[copied_elements] = A[i];
			++i;
		}
		else 
		{
			sorted_A[copied_elements] = A[j];
			++j;
		}
		++copied_elements;
	}
	for (int i = 0; i < len; ++i)
		A[i] = sorted_A[i];
	delete[] sorted_A;
}


int main()
{
	// Initializes random number generation
	// to make sure test runs the same every time.
	srand(2017);

	// Variables used later
	const int len = 5000000;
	int* A = new int[len];
	int* B = new int[len];
	float total_duration = 0;
	float total_benchmark_duration = 0;



	// Test 1: already in sorted order
	for (int i = 0; i < len; ++i)
		A[i] = B[i] = i+1; 

	system_clock::time_point start = system_clock::now();
	sort(A, len);
	system_clock::time_point end = system_clock::now();
	float dur = duration<float>(end - start).count();
	total_duration += dur;
	cout << "Test #1 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur;

	for (int i = 0; i < len; ++i)
		test(A[i] == B[i]);



	// Test 2: reverse sorted order
	for (int i = 0; i < len; ++i)
		A[i] = len-i; 
	for (int i = 0; i < len; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur; 
	cout << "Test #2 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < len; ++i)
		test(A[i] == B[i]);

		

	// Test 3: in "mostly" sorted order
	for (int i = 0; i < len; ++i)
		A[i] = i+1; 
	for (int i = 0; i < 10000; ++i)
		swap(A[rand() % len], A[rand() % len]);
	for (int i = 0; i < len; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur;
	cout << "Test #3 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < len; ++i)
		test(A[i] == B[i]);
	


	// Test 4: random ints
	for (int i = 0; i < len; ++i)
		A[i] = rand(); 
	for (int i = 0; i < len; ++i)
		B[i] = A[i];
	
	start = system_clock::now();
	sort(A, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur; 
	cout << "Test #4 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < len; ++i)
		test(A[i] == B[i]);


	
	// Test 5: lots of repeats 
	for (int i = 0; i < len; ++i)
		A[i] = rand() % 10; 
	for (int i = 0; i < len; ++i)
		B[i] = A[i];

	start = system_clock::now();
	sort(A, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_duration += dur;
	cout << "Test #5 time: " << dur << " seconds." << endl;

	start = system_clock::now();
	benchmark_sort(B, len);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	total_benchmark_duration += dur; 

	for (int i = 0; i < len; ++i)
		test(A[i] == B[i]);



	// Summary stuff

	// Print out the total time spent by your sort on all tests
	cout << "Total time: " << total_duration << " seconds." << endl;

	// Check that you beat the benchmark (basic merge sort)
	test(total_duration < total_benchmark_duration);
	cout << "Assignment complete." << endl;	
}



