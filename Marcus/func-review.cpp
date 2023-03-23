/*
rand num gen help 
*/
#include <iostream> 
#include <stdlib.h> // use srand && rand 
#include <time.h> // time function
using namespace std; 

int ranINPUT(int top); 

int main() 
{
int num, maxbound;

srand(static_cast<int> (time(NULL)) );

cout << "welcome to my rand num generator " << "\n"; 
cout << "the random number generated for you will be between 0 and your maxbound" << endl; 
cout << "please enter your maxbound: " << "\n"; 

cin >> maxbound; 

num = ranINPUT(maxbound); 

cout << "random number: " << num; 

return 0; 
}
int ranINPUT(int top)
{
    return rand() % top; 
}
