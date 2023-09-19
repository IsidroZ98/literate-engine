
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <string>

using namespace std;

class Autocompleter
{
	public:
		// Creates a new, empty autocompleter. Initial capacity is 100 elements.
		Autocompleter();
	
		// Adds x to the list of potential suggestions in the Autocompleter in the position that will keep
		// Autocompleter sorted after the insertion.
		// MUST double the capacity when necessary.
		// If the word is already in the Autocompleter, does nothing.
		//
		// MUST run in O(n) time.
		void insert(string x);

		// Returns the number of strings in the Autocompleter.
		int size();

		// Returns the number of strings that are completions of
		// the parameter string x. 
		//
		// MUST run in O(log(n)) time.
		int completion_count(string x);

		// Takes a string (parameter x) and string array of length 5 (parameter suggestions) 
		// Sets the first five elements of suggestions equal 
		// to the first five (in lexicographic order) strings
		// in the Autocompleter that start with x. 
		//
		// If there are less than five such strings, the remaining
		// entries of the suggestions array are set to "" (the empty string) 
		//
		// MUST run in O(log(n)) time.
		void completions(string x, string* suggestions);

		// string get(int x) {return A[x];}		// Uncomment this statement only if you need it for debugging purposes
	
	private:
		// Helper method.
		//
		// Assumes A is SORTED.
		// If x is in A, returns the index of A containing x.
		// Otherwise, returns the index of A where x should be inserted 
		// (that is, the position where it would be after calling insert(x)).
		//
		// MUST run in O(log(n)) time (use binary search). 
		int index_of(string x, string* A, int n);

		// The data structure must consist of 
		// a dynamic array of sorted strings.
		string* A;
		// quantity of words in the data structure
		int count;
		// current capacity of the data structure
		int capacity;

};

#endif

