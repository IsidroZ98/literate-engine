// SUPER GIGA BIG WORKOUT TRACKING

#include <iostream> 
using namespace std; 

void split(string workout, int progress)
{
    cout << "\nLift: " << workout << "\nCurrent PR: " << progress;  
} 
int main() 
{
    split("BENCH", 255); 
    "\n";
    split("DB PRESS", 105); 
    "\n"; 
    split("DEADLIFT", 350);
    "\n";
    split("SQUAT", 225);  
    "\n";
    split("SEATED ROWS:", 160);


    return 0; 
}
