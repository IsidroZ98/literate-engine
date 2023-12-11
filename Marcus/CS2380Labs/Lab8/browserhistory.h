
#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include <string>

using namespace std;

class BrowserHistory 
{
	public:
		// Creates a new browser history with only one page visited: default_url
		BrowserHistory(string default_url);

		// Returns the current page.
		string current_url();

		// Moves the browser to a new page url via,
		// e.g., clicking a link, typing into the address bar, etc. 
		void go_to_url(string url);

		// Moves back (into the past) by one url.
		void back();

		// Returns whether there is a url in the past,
		// i.e. whether the back button can be pushed. 
		bool can_go_back();

		// Returns how many urls are in the past,
		// i.e. how many times in a row the back button could be pushed. 
		int past_url_count();

		// Moves forward (into the future) by one url.
		void forward();

		// Returns whether there is a url in future,
		// i.e. whether the future button can be pushed. 
		bool can_go_forward();

		// Returns how many urls are in the future,
		// i.e. how many times in a row the forward button could be pushed.
		int future_url_count();

	private:
		class Node
		{
			public:
				string url;
				Node* next;
				Node* prev;
		};

		// Pointers to access the list
		Node* head;			// Points to the first URL entered
		Node* tail;			// Points  to the last URL entered
		Node* current;		// Points to the current URL
};

#endif

