// What is the output of the following C++ code?
#include <iostream> 
using namespace std; 


int mystery(int x, int* A, int n)

{

        if (n <= 1)

                if (A[n/2] != x)

                        return -1;

                else

                        return A[0];

        if (A[n/2] == x)

                return A[n/2];

        if (A[n/2] > x)

                return mystery(x, A, n/2);

        else

                return mystery(x, &(A[n/2]), n-n/2);

}

 

int main()

{

        int A[11] = {2,4,7,9,11,15,16,17,20,21,23};

        cout << mystery(7, A, 11) << ',' << mystery(18, A, 11);

}