// Team #20 CSCI 2380 FALL 2023 HOMEWORK #10
// Edgar Hernandez
// Marcus Gutierrez
// 11/20/23
// Gustavo Dietrich 
////////////////////////////////////////////////////////////////
#include "autocompleter.h"

// constructor created for autocompleter class
Autocompleter::Autocompleter() {
    
  capacity = 100; // initial capacity of autocompleter is set
  
  A = new string[capacity]; // store strings amount is set from capacity
  
  count = 0;
}

void Autocompleter::insert(string x) {
    // set idx to index of x, A, count
    int idx = index_of(x, A, count);
// string 'x' dynamic array A & int count
    if (idx < count && A[idx] == x) {
        // dupe checker
        return;
    }

   // check to make sure capacity is not exceeded
    if (count == capacity) {
    // if it is double it
        capacity *= 2;
        string* newA = new string[capacity];
      // new array (newA) gets updated capacity size

        // for loop to copy elements from existing array 'A' to new array 'newA'
        for (int i = 0; i < count; ++i) {
            newA[i] = A[i];
        }
        delete[] A;// delete old array
        A = newA; // set old to new
    }

    // shift over elements
    for (int i = count; i > idx; --i) {
        A[i] = A[i - 1];
    }

    // insert new word the count increment indicates a new word went through
    A[idx] = x;
    count++;
}

int Autocompleter::size() {
    return count; // return count amount
}

int Autocompleter::completion_count(string x) {
  // utilizing binary search to see where x should go in array 
   int idx = index_of(x, A, count);

    // set our completion count up
    int completionCount = 0;
    while (idx < count && A[idx].find(x) == 0) {
        completionCount++; // increment completion count
        idx++;
    }
    return completionCount;
}

void Autocompleter::completions(string x, string* suggestions) {
    // use binary to find the index of x
    int idx = index_of(x, A, count);

    int i = 0;
    while (idx < count && A[idx].find(x) == 0 && i < 5) {
        suggestions[i] = A[idx];
        idx++; i++; // increment completion and index count
    }  // set first elements of suggestions found to completions x

    for (; i < 5; ++i) {
        suggestions[i] = ""; // fill suggestions with empty strings 
    }
}

int Autocompleter::index_of(string x, string* arr, int n) {
  // set our bounds of search
    int low = 0;
    int high = n - 1;
// using binary search again, this while loop keeps repeating until our set bounds are fully checked
    while (low <= high) {
        int mid = (low + high) / 2; // dietrich talked about this with the phone book name search, cut down on our search to get middle 
        int cmp = x.compare(arr[mid]);

        if (cmp == 0) {
            return mid;  
        } else if (cmp < 0) {
            high = mid - 1; // split our finders to see if string is found in the mid (middle) high (higher bounds) or our low (lower bounds)
        } else {
            low = mid + 1;
        }
    }

    return low;  // if loop is complete and x not found it returns to low where it should have been
}

























































// end of code