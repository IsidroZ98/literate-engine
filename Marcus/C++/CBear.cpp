#include <iostream> 

#include <iostream>
#include <string>
using namespace std;

int main()
{
  //list of userinputs
  //have a counter that is going to break if they type exit
  double num1,num2,total;
  string userInput;
  cout << "Welcome to simple calculator" << endl;
  cout << "Please enter which operation you would like to use" << endl;
  cout << "\n";
  cout << "To choose type add, sub, div, or mul" << endl;
  for (int timerCount = 0;timerCount<=100;timerCount++)
    {
      cin >> userInput;
  
 
      cout << "Please enter your first number" << endl;
      cin >> num1;
      cout << "Please enter your 2nd number" << endl;
      cin >> num2;
      
      
      if(userInput == "add")
      {
        total = num1 + num2;
        cout << "Your number is : " << total<< endl;
      }
      if(userInput == "sub")
      {
        total = num1 - num2;
        cout << "Your number is : " << total<< endl;
      }
      if(userInput == "div")
      {
        total = num1/num2;
        cout << "Your number is : " << total<< endl;
      }
      if(userInput == "mul")
      {
        total = num1*num2;
        cout << "Your number is : " << total << endl;
      }
      if(userInput == "exit")
      {
        timerCount = 1000;
        return 0;
      }
      cout << " If you like to exit type exit else type the next operation ";
      
    }
}

// ++count - prefix form: used as increment or decrement to run before the set expressions.
// count++ postfix form: used as increment or decrement to run after the set expressions. 

