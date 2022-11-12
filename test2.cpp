//
// Created by sawil on 11/1/2022.
//
// Your First C++ Program

#include <iostream>
using namespace std;

class Student {
    private:
        int studentId;

    public:
        string name;

        Student(string x, int y) {
            name = x;
            studentId = y;
        }

        int getStudentId() {
            return this->studentId;
        }

        void updateStudentName(string newName) {
            this->name = newName;
            cout << "The Student's updated name is " + this->name;
        }
    
};

int sum(int a, int b) {
    // sums two integers 
    int result = a + b;
    return result;
}

int sumArray(int* numbers) {
    // This function sums all of the numbers in a list
    int n, total = 0;
    for (n=0; n < sizeof(numbers); ++n) {
        total += numbers[n];
    }
    return total;
}

void pointers() {
    // Practice using pointers to print the first letter in my name
    string name = "seth";
    char * firstLetter;
    firstLetter = &name[0]; // Get memory address of first letter in string

    cout << "\n" << firstLetter; // print memory address
    cout << "\n" << *firstLetter; // print dereferenced memory address

}

int main() {
    cout << "Hello, Seth! \n";
    // cout << sum(13, 17);
    // int numbers[5] = {1, 2, 3, 4, 5};
    // cout << sumArray(numbers) + "\n";
    Student student1("Seth", 1234);
    int id = student1.getStudentId();
    cout << id;
    student1.updateStudentName("Clay");
    return 0;
}