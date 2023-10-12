
#include <iostream>
#include "browserhistory.h"


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file << ", line " << line << "." << endl;
        //abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


void interactive_mode()
{
	BrowserHistory bh("http://google.com");
	cout << "Starting at " << bh.current_url() << "." << endl;
	cout << "Choose (B)ack, (F)orward, or enter a url to go to." << endl;

	string line;
	while (cin)
	{
		string line;
		getline(cin, line);
		if (line == "B")
		{
			if (bh.can_go_back())
			{
				bh.back();
				cout << "    Now at " << bh.current_url() << endl;
			}
			else
				cout << "    Cannot go back." << endl;
				
		}
		else if (line == "F")
		{
			if (bh.can_go_forward())
			{
				bh.forward();
				cout << "    Now at " << bh.current_url() << endl;
			}
			else
				cout << "    Cannot go forward." << endl;
		}
		else if (line.size() > 0)
		{
			bh.go_to_url(line);
			cout << "    Now at " << bh.current_url() << endl;
		}
	}
	exit(0);
}


int main()
{
	// Uncomment line below to use your BrowserHistory interactively.
	// 
	// interactive_mode();


	// Comments below indicate the current (expected) state of the history.
	// Example: [url1, url2, url3, (url4), url5, url6]
	// The urls are listed oldest to newest from left to right, 
	// and the url in parentheses is the current url. 

	bool separator = false;		// Change separator to true to see on the screen which function is being tested

	if (separator) cout << "Testing creation of browser history" << endl << endl;

	// History: [(google.com)]
	BrowserHistory bh("http://google.com");
	test(bh.current_url() == "http://google.com");
	test(!bh.can_go_back());
	test(!bh.can_go_forward());	
	test(bh.past_url_count() == 0);
	test(bh.future_url_count() == 0);

	if (separator) cout << "Testing go_to_url()" << endl << endl;

	bh.go_to_url("http://netflix.com");
	bh.go_to_url("http://amazon.com");
	bh.go_to_url("http://utrgv.edu");
	// History: [google.com, netflix.com, amazon.com, (utrgv.edu)]
	test(bh.current_url() == "http://utrgv.edu");
	test(bh.can_go_back());
	test(!bh.can_go_forward());	
	test(bh.past_url_count() == 3);
	test(bh.future_url_count() == 0);

	if (separator) cout << "Testing back()" << endl << endl;

	bh.back();
	bh.back();
	// History: [google.com, (netflix.com), amazon.com, utrgv.edu]
	test(bh.current_url() == "http://netflix.com");
	test(bh.can_go_back());
	test(bh.can_go_forward());
	test(bh.past_url_count() == 1);
	test(bh.future_url_count() == 2);
	
	if (separator) cout << "Testing go_to_url() again" << endl << endl;

	bh.go_to_url("http://walmart.com");
	// History: [google.com, netflix.com, (walmart.com)]
	test(bh.current_url() == "http://walmart.com");
	test(bh.can_go_back());
	test(!bh.can_go_forward());
	test(bh.past_url_count() == 2);
	test(bh.future_url_count() == 0);

	bh.back();
	bh.go_to_url("http://amazon.com");
	bh.go_to_url("http://utrgv.edu");
	// History: [google.com, netflix.com, amazon.com, (utrgv.edu)]
	bh.back();
	bh.back();

	if (separator) cout << "Testing forward()" << endl << endl;

	bh.forward();
	// History: [google.com, netflix.com, (amazon.com), utrgv.edu]
	test(bh.current_url() == "http://amazon.com");
	test(bh.can_go_back());
	test(bh.can_go_forward());
	test(bh.past_url_count() == 2);
	test(bh.future_url_count() == 1);

	if (separator) cout << "Testing current_url()" << endl << endl;

	// History: [google.com, netflix.com, amazon.com, (youtube.com)]
	bh.go_to_url("http://youtube.com");
	test(bh.current_url() == "http://youtube.com");
	test(bh.can_go_back());
	test(!bh.can_go_forward());
	test(bh.past_url_count() == 3);
	test(bh.future_url_count() == 0);
	bh.forward(); // Can't go forward any more, so do nothing	
	test(bh.current_url() == "http://youtube.com");
	
	bh.back();
	bh.back();
	bh.back();
	// History: [(google.com), netflix.com, amazon.com, youtube.com]
	test(bh.current_url() == "http://google.com");
	bh.back(); // Can't go back any more, so do nothing
	test(bh.current_url() == "http://google.com");

	if (separator) cout << "Testing Larger test" << endl << endl;
	// Larger test 
	string url("http://url00.com");
	for (int i = 0; i < 100; ++i)
	{
		url[10] = i / 10 + '0';
		url[11] = i % 10 + '0';
		bh.go_to_url(url);
	} 
	// History: [url00.com, url01.com, url02.com, ..., (url99.com)]
	for (int i = 0; i < 49; ++i)
		bh.back();
	// History: [url00.com, url01.com, ..., (url50.com), ..., url99.com]
	test(bh.current_url() == "http://url50.com");	

	cout << "Assignment complete." << endl;
}



