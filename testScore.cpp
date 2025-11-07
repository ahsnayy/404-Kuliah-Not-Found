#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

 const int ARRAY_SIZE = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

struct studentList {
    studentType students_array[ARRAY_SIZE];  
    int listLength;                      
};

void readIn(studentList &studentList);
void printStudentInfo(const studentType &student);
void assignGrade(studentType &student);
void highestScore(const studentList &classList);

int main ( ) {
    studentList classList;
    classList.listLength = 0;

    readIn(classList);

    for (int i = 0; i < classList.listLength; i++) {
        assignGrade(classList.students_array[i]);
    }

    cout << "----------------------------------------" << endl;
    cout << left << setw(20) << "Name"
     << setw(10) << "Score"
     << setw(5)  << "Grade" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < classList.listLength; i++) {
        printStudentInfo(classList.students_array[i]);
    }

    highestScore(classList);

    return 0;
}

void readIn(studentList &classList) {
    cout << "Enter student information (first name, last name, test score)." << endl;
    cout << "Type 'end' as the first name to finish input." << endl;

    while (classList.listLength < ARRAY_SIZE) {
        string fName;
        cout << "First Name: ";
        cin >> fName;
        if (fName == "end") {
            break;
        }

        string lName;
        int score;
        cout << "Last Name: ";
        cin >> lName;
        cout << "Test Score: ";
        cin >> score;
        cout << endl;

        classList.students_array[classList.listLength].studentFName = fName;
        classList.students_array[classList.listLength].studentLName = lName;
        classList.students_array[classList.listLength].testScore = score;

        classList.listLength++;
    }
}

void assignGrade(studentType &student) {
    if (student.testScore >= 90)
        student.grade = 'A';
    else if (student.testScore >= 80)
        student.grade = 'B';
    else if (student.testScore >= 70)
        student.grade = 'C';
    else if (student.testScore >= 60)
        student.grade = 'D';
    else
        student.grade = 'E';
}

void printStudentInfo(const studentType &student) {
    cout << left << setw(20) << (student.studentLName + ", " + student.studentFName) 
        << setw(10) << student.testScore 
        << setw(5) << student.grade << endl;
}

void highestScore(const studentList &classList) {
    if (classList.listLength == 0) {
        cout << "No students in the list." << endl;
        return;
    }

    int highest = classList.students_array[0].testScore;
    for (int i = 1; i < classList.listLength; i++) {
        if (classList.students_array[i].testScore > highest) {
            highest = classList.students_array[i].testScore;
        }
    }

    cout << "\nThe highest test score is: " << highest << endl;
    cout << "Achieved by:" << endl;
    for (int i = 0; i < classList.listLength; i++) {
        if (classList.students_array[i].testScore == highest) {
            cout << classList.students_array[i].studentFName << " " 
                 << classList.students_array[i].studentLName << endl;
        }
    }
}
