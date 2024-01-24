// What is the output of the following C++ code? 
#include <iostream> 
using namespace std;
 

void yas(int a)

{

        // Base case

        if (a == 3)

        {

                cout << 'a' << ',';

                return;

        }

        // Recursive case

        for (int i = 1; i <= a; ++i)

                yas(a+1);

}

 

int main()

{

        yas(1);

}
