////////////////////////////////////////////////////
// Team #18 CSCI 2380 SPRING 2023 HOMEWORK #10
// Marcus Gutierrez
// 4/13/23
// Gustavo Dietrich
////////////////////////////////////////////////////
#include <iostream>
#include "autocompleter.h"

Autocompleter::Autocompleter()
{
  A = new string[100]; 
  count = 0; 
  capacity = 100; 
}

void Autocompleter::insert(string x)
{
    if (count == capacity) 
    {
        string* temp = new string[capacity * 2]; 
        for (int i = 0; i < capacity; i++) 
        {
            temp[i] = A[i]; 
        }
        delete[] A; 
        A = temp; 
        capacity *= 2; 
    }
    int index = index_of(x, A, count); 
    if (A[index] != x) 
    {
        for (int i = count; i > index; i--) 
        {
            A[i] = A[i - 1];
        }
        A[index] = x; 
        count++; 
    }
}
/* 
  increases array capacity 
  creates new array
  gets old array info -> new established array
////
  goes into array of x
  if not present shifts to the right

*/ 

int Autocompleter::size()
{
  return count; 
}
/* 
returns strings

returns count

*/

int Autocompleter::completion_count(string x)
{
    int index = index_of(x, A, count); 
    int count = 0; 
    for (int i = index; i < this->count; i++) 
    {
        if (A[i].find(x) == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}
/* 
intitalizes the count 

goes thru elements

increases count 

ends with return of count

*/
void Autocompleter::completions(string x, string* suggestions) 
{
    int index = index_of(x, A, count);
    int count = 0; 
    for (int i = index; i < this->count; i++) 
    {
        if (A[i].find(x) == 0) 
        {
            suggestions[count] = A[i]; 
            count++; 
            if (count == 5) 
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
 for (int i = count; i < 5; i++) 
    {
        suggestions[i] = ""; 
    }
}
/* 
sorts out indexes 
corresponding indexes respond based on autocompleter
*/ 
int Autocompleter::index_of(string x, string* A, int n) 
{
    int low = 0; 
    int mid; 
    int high = n - 1; 
    while (low <= high) 
    {
        mid = (low + high) / 2; 
        if(A[mid] == x) 
        {
            return mid;
        }
        else if (A[mid] < x) 
        {
            low = mid + 1; 
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
/* 
goes thru search

low, mid, high indexes available to set based on autocompleter

*/ 
// end of code 4:18:2023||8:23PM // 