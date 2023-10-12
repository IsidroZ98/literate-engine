
#ifndef CANVAS_H
#define CANVAS_H

#include <string>

using namespace std;


// In this homework, you'll manipulate ASCII art images
// consisting of a rectangular grid of chararacter pixels. 
class Canvas
{
	public:
		// Allocates a canvas of the given width and height 5 that
		// consists entirely of ' ' (space) chars. If the width is 0,
		// the canvas is empty (pointer is NULL and _width is 0)
		Canvas(int width);

		// Allocates a canvas with width 5 and height 5 that looks like:
		//
		//  ###       ####        ####     ####
		// #   #      #   #      #         #   #
		// #####  or  ####   or  #      or #   #
		// #   #      #   #      #         #   #
		// #   #      ####        ####     ####
		//
		// depending upon which character ('A', 'B', 'C', or 'D') is 
		// given as a parameter. If some other character is given, 
		// allocates a canvas of ' ' chars with width 5 and height 5.
		Canvas(char x); 

		// Returns the width of the canvas.
		int width();

		// Returns the entire canvas as a single string, consisting of each row
		// of the canvas, followed by the newline character ('\n').
		// If the canvas is empty, returns an empty string.
		string to_string(); 
		
		// Replaces every instance in the canvas of old_char with new_char.
		// For instance, if old_char is '#' and new char is '@', then: 
		// 
		//  ###             @@@
		// #   #           @   @
		// #####  becomes  @@@@@ 
		// #   #           @   @
		// #   #           @   @
		//
		void replace(char old_char, char new_char);

		// Destructor. Deallocates all of the memory allocated by the canvas.
		~Canvas();

		// Allocates a canvas containing the sequence of characters
		// in the string with 2 columns of space between each pair 
		// of adjacent characters. For instance, Canvas("BADCAB") 
		// should yield:
		//
		// ####    ###   ####    ####   ###   ####  
		// #   #  #   #  #   #  #      #   #  #   #
		// ####   #####  #   #  #      #####  ####
		// #   #  #   #  #   #  #      #   #  #   # 
		// ####   #   #  ####    ####  #   #  #### 
		// 
		// Any characters in s not from {'A', 'B', 'C', 'D'} should be 
		// replaced with empty 5x5 space, just like previous constructor.
		// If the string is empty (null string), the canvas is empty 
		// (pointer is NULL and _width is 0)
		Canvas(string s);

		// Adds a character to the Canvas's sequence of characters.
		void add(char x);

	private:
		// A canvas is represented as a 2D char array, i.e. 
		// an array of pointers to char (sub)arrays.
		// Each subarray corresponds to a COLUMN of the image.
		char** C;
		int _width;
};

#endif

