
#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include <string>
#include <stack>

using namespace std;

class BrowserHistory 
{
	public:
		// Creates a new browser history with only one page visited: default_url
		BrowserHistory(string default_url);

		// Returns the current page.
		string current_url();

		// Moves the browser to a new page via url,
		// e.g., clicking a link, typing into the address bar, etc. 
		void go_to_url(string url);

		// Moves back (into the past) by one url.
		// 
		// If there is no past url to move to, does nothing.
		void back();

		// Returns whether there is a url in the past,
		// i.e. whether the back button can be pushed. 
		bool can_go_back();

		// Returns how many urls are in the past,
		// i.e. how many times in a row the back button could be pushed. 
		int past_url_count();

		// Moves forward (into the future) by one url.
		// 
		// If there is no future url to move to, does nothing.
		void forward();

		// Returns whether there is a url in future,
		// i.e. whether the future button can be pushed. 
		bool can_go_forward();

		// Returns how many urls are in the future,
		// i.e. how many times in a row the forward button could be pushed.
		int future_url_count();

	private:
		// Two stacks of strings - these are the only variables you need!
		// See http://www.cplusplus.com/reference/stack/stack/ for class reference.

		stack<string> past;			// holds CURRENT and PAST urls
		stack<string> future;		// holds FUTURE urls
};

#endif

