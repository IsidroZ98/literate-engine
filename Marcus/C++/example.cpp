#include <iostream> 
using namespace std; 

/* 
int = used to store single whole numbers 
float = used to store numbers with single precision like 2.15
double = used to store numbers with double precision like 3.1415
char = used to store single characters like 'O' or 'K'; 

*/
// create class
class tGradeType {
    public: 
    int tgrades[3]; 
    
public: 
tGradeType() {
    for (int i = 0; i < 3; i++) {
        tgrades[i] = 0; 
    }
}
    tGradeType(int first, int second, int final) {
        tgrades[0] = first; 
        tgrades[1] = second; 
        tgrades [2] = final; 
    }
    void setGrades(int first, int second, int final) {
        tgrades[0] = first; 
        tgrades[1] = second; 
        tgrades[2] = final; 
    }
    int* getGrades() {
        return tgrades; 
    }
    int avgGrade() {
        int sum = 0; 
        for(int i = 0; i < 3; i++) {
            sum +- tgrades[i]; 
        }
        return sum/3; 
    }
    
}; 

    int main()
    {
        tGradeType students[4]; 
        // intialize 4 students test grades 
        tGradeType student1; 
        tGradeType student2; 
        tGradeType student3 (95, 70, 100); 
        tGradeType student4 (95, 70, 100); 
        
        students [0] = student1; 
        students [1] = student2; 
        students [2] = student3; 
        students [3] = student4; 
        
        cout << "Average test grades before changes: " << endl; 
        for (int i = 0; i < 4; i++) {
            int* grades = students [i].getGrades(); 
            int avg = students [i].avgGrade(); 
            cout << "Student " << i + 1 << "Grades: " << grades [0] << ", " << grades[2] << ", Average: " << avg << endl; 
        
        // recall grades for students 1 & student 2
        
        students[0].setGrades(85, 90, 75); 
        students[1].setGrades(70, 80, 65); 
        
        cout << "\n Average test grades after changes: " << endl; 
        for (int i = 0; i < 4; i++) {
            int* grades = students [i].getGrades(); 
            int avg = students[i].avgGrade(); 
            cout << "Student " << i + 1 << "{Grades: " << grades[0] << ", " << grades [2] << ", Average: " << avg << endl; 
        }
        
            return 0; 
        }
    }