// What is the output of the following C++ code?
#include <iostream> 
using namespace std; 
 

void print(int x)

{

        if (x == 0)

        {

                cout << x;

                return ;

        }

        else

        {               

                cout << x;

                print(x-1);

                cout << x;

        }

}

 

int main()

{

        print(4);

}