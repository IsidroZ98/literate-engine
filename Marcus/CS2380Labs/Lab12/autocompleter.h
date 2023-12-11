
#ifndef AUTOCOMPLETER_H
#define AUTOCOMPLETER_H

#include <string>

using namespace std;

class Autocompleter
{
	public:
		// Same as hw 10
		Autocompleter();
		void insert(string x); // a.k.a. add()
		int size();
		int completion_count(string x);
		void completions(string x, string* suggestions);

	private:
		// A helper class that implements
		// a basic binary search tree node.
		class Node
		{
			public:
				Node(string s)
				{
					this->s = s;
					left = right = nullptr;
				}

				string s;
				Node* left;
				Node* right;
		};

		// Helper method for size()
		int size_recurse(Node* root);
	
		// Helper method for completion_count().
		// Here's a (recursive) algorithm:
		//
		// Base case: 
		// If root is nullptr, then return 0.
		//
		// Recursive case:
		// -Return the sum of the completion counts of the 
		//  left and right subtrees plus:
		//     0 if root->s does not start with x.
		//     1 if root->s does start with x.  
		int completion_count_recurse(string x, Node* root);

		// Helper method for completions().
		// Here's a (recursive) algorithm:
		//
		// Base case:
		// If root is nullptr, return.
		// If the last entry of the suggestions array is not "", return.
		// (since completions() has already found 5 suggestions).
		//
		// Recursive case:
		// -Recurse on left subtree.
		// -If root->s starts with x, add root->s to first empty
		//  location in suggestions.
		// -Recurse on right subtree.
		void completions_recurse(string x, string* suggestions, Node* root);

		// The data structure should be a binary search tree
		Node* root;
};

#endif

