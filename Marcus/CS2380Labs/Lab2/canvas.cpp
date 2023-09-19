// Team #20 CSCI 2380 FALL 2023 HOMEWORK #2
// Edgar Hernandez
// Marcus Gutierrez
// 2/19/23
// Gustavo Dietrich 

#include "canvas.h"

// Constructor for Canvas(int width)
Canvas::Canvas(int width) {
    _width = width;

    // Initialize local variables for loops
    int col, row;

    // Create a dynamic array of pointers to char with _width elements
    C = new char*[_width];

    if (_width == 0) {
        C = nullptr; // Set the pointer to null if the canvas is empty
    } else {
        for (col = 0; col < _width; ++col) {
            C[col] = new char[5]; // Create dynamic arrays of char with 5 elements for each column
            for (row = 0; row < 5; ++row) {
                C[col][row] = ' '; // Fill the canvas with ' ' spaces
            }
        }
    }
}

// Constructor for Canvas(char x)
Canvas::Canvas(char x) {
    _width = 5;

    // Initialize local variables for loops
    int row, col;

    // Create a dynamic array of pointers to char with _width elements
    C = new char*[_width];

    for (col = 0; col < _width; ++col) {
        C[col] = new char[_width]; // Create dynamic arrays of char with _width elements for each column
    }

    if (x == 'A') {
        // Fill the canvas with '#' for the letter 'A'
        for (row = 1; row < _width; ++row)
            C[0][row] = '#';
        for (col = 1; col < 4; ++col)
            C[col][0] = C[col][2] = '#';
        for (row = 1; row < _width; ++row)
            C[4][row] = '#';

        // Fill any unfilled elements with ' '
        for (col = 0; col < _width; ++col) {
            for (row = 0; row < 5; ++row) {
                if (C[row][col] != '#') {
                    C[row][col] = ' ';
                }
            }
        }
    } else if (x == 'B') {
        // Fill the canvas with '#' for the letter 'B'
        for (row = 0; row < 5; ++row)
            C[0][row] = '#';
        for (row = 0; row < 3; ++row)
            C[1][row * 2] = '#';
        for (row = 0; row < 3; ++row)
            C[2][row * 2] = '#';
        for (row = 0; row < 3; ++row)
            C[3][row * 2] = '#';
        for (row = 1; row < 3; ++row)
            C[4][row * 2 - 1] = '#';

        // Fill any unfilled elements with ' '
        for (col = 0; col < _width; ++col) {
            for (row = 0; row < 5; ++row) {
                if (C[row][col] != '#') {
                    C[row][col] = ' ';
                }
            }
        }
    } else if (x == 'C') {
        // Fill the canvas with '#' for the letter 'C'
        for (row = 0; row < 5; ++row) {
            if (row == 0 || row == 4) {
                C[0][row] = ' ';
            } else {
                C[0][row] = '#';
            }
        }
        for (col = 1; col < 5; ++col)
            for (row = 0; row < 2; ++row)
                C[col][row * 4] = '#';

        // Fill any unfilled elements with ' '
        for (col = 0; col < _width; ++col) {
            for (row = 0; row < 5; ++row) {
                if (C[row][col] != '#') {
                    C[row][col] = ' ';
                }
            }
        }
    } else if (x == 'D') {
        // Fill the canvas with '#' for the letter 'D'
        for (row = 0; row < 5; ++row)
            C[0][row] = '#';

        for (col = 1; col < 4; ++col)
            for (row = 0; row < 2; ++row)
                C[col][row * 4] = '#';

        for (row = 1; row < 4; ++row)
            C[4][row] = '#';

        // Fill any unfilled elements with ' '
        for (col = 0; col < _width; ++col) {
            for (row = 0; row < 5; ++row) {
                if (C[row][col] != '#') {
                    C[row][col] = ' ';
                }
            }
        }
    } else {
        // If char x is not any of the required letters, create a canvas of 5 width & 5 col with ' ' as char
        for (col = 0; col < _width; ++col)
            for (row = 0; row < 5; ++row)
                C[col][row] = ' ';
    }
}

// Destructor
Canvas::~Canvas() {
    for (int col = 0; col < _width; ++col)
        delete[] C[col]; // Delete dynamic arrays used
    delete[] C; // Delete array of pointers to char
    C = nullptr; // Set C to a null pointer
}

// Return the private data member _width
int Canvas::width() {
    return _width;
}

// Create a string of characters found in the dynamic array
string Canvas::to_string() {
    string fin = "";
    int row, col;

    if (_width == 0) {
        return fin; // Return an empty string if there is no width
    } else {
        for (row = 0; row < 5; ++row) {
            for (col = 0; col < _width; ++col) {
                fin += (C[col][row]);
            }
            fin += "\n"; // Return the string after each char has been added followed by a newline
        }
    }
    return fin;
}

// Replace old_char with new_char in the canvas
void Canvas::replace(char old_char, char new_char) {
    int col, row;

    for (col = 0; col < _width; ++col) {
        for (row = 0; row < 5; ++row) {
            if (C[col][row] == old_char) {
                C[col][row] = new_char; // Replace the current array notation char value with new_char
            }
        }
    }
}
