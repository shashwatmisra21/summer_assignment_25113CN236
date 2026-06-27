#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Student {
    int rollNumber;
    string name;
    int age;
    string course;
    double gpa;
};
class StudentManager {
private:
    vector<Student> students;
    int findStudentIndex(int rollNumber) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].rollNumber == rollNumber) {
                return i;
            }
        }
        return -1;
    }

public:
    void addStudent() {
        Student newStudent;
        cout << "\n--- Add New Student Record ---\n";
        cout << "Enter Roll Number: ";
        cin >> newStudent.rollNumber;
        if (findStudentIndex(newStudent.rollNumber) != -1) {
            cout << "Error: A student with Roll Number " << newStudent.rollNumber << " already exists!\n";
            return;
        }

        cin.ignore(); // Clear input buffer
        cout << "Enter Full Name: ";
        getline(cin, newStudent.name);
        cout << "Enter Age: ";
        cin >> newStudent.age;
        cin.ignore();
        cout << "Enter Course/Branch: ";
        getline(cin, newStudent.course);
        cout << "Enter GPA: ";
        cin >> newStudent.gpa;

        students.push_back(newStudent);
        cout << "Record added successfully!\n";
    }
    void displayAllStudents() {
        if (students.empty()) {
            cout << "\nNo records found in the database.\n";
            return;
        }

        cout << "\n-----------------------------------------------------------------------------\n";
        cout << left << setw(12) << "Roll No" 
             << setw(25) << "Name" 
             << setw(8)  << "Age" 
             << setw(18) << "Course" 
             << setw(8)  << "GPA" << endl;
        cout << "-----------------------------------------------------------------------------\n";

        for (const auto& student : students) {
            cout << left << setw(12) << student.rollNumber 
                 << setw(25) << student.name 
                 << setw(8)  << student.age 
                 << setw(18) << student.course 
                 << fixed << setprecision(2) << setw(8) << student.gpa << endl;
        }
        cout << "-----------------------------------------------------------------------------\n";
    }
    void searchStudent() {
        if (students.empty()) {
            cout << "\nNo records available to search.\n";
            return;
        }

        int rollNumber;
        cout << "\nEnter Roll Number to search: ";
        cin >> rollNumber;

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student with Roll Number " << rollNumber << " not found.\n";
            return;
        }

        cout << "\n--- Student Record Found ---\n";
        cout << "Roll Number : " << students[index].rollNumber << endl;
        cout << "Name        : " << students[index].name << endl;
        cout << "Age         : " << students[index].age << endl;
        cout << "Course      : " << students[index].course << endl;
        cout << "GPA         : " << fixed << setprecision(2) << students[index].gpa << endl;
    }
    void updateStudent() {
        if (students.empty()) {
            cout << "\nNo records available to update.\n";
            return;
        }

        int rollNumber;
        cout << "\nEnter Roll Number to update: ";
        cin >> rollNumber;

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student with Roll Number " << rollNumber << " not found.\n";
            return;
        }

        cout << "\n--- Current Details ---\n";
        cout << "Name: " << students[index].name << " | Course: " << students[index].course << " | GPA: " << students[index].gpa << endl;
        
        cout << "\n--- Enter New Details ---\n";
        cin.ignore();
        cout << "Enter New Name: ";
        getline(cin, students[index].name);
        cout << "Enter New Age: ";
        cin >> students[index].age;
        cin.ignore();
        cout << "Enter New Course: ";
        getline(cin, students[index].course);
        cout << "Enter New GPA: ";
        cin >> students[index].gpa;

        cout << "Record updated successfully!\n";
    }
    void deleteStudent() {
        if (students.empty()) {
            cout << "\nNo records available to delete.\n";
            return;
        }

        int rollNumber;
        cout << "\nEnter Roll Number to delete: ";
        cin >> rollNumber;

        int index = findStudentIndex(rollNumber);
        if (index == -1) {
            cout << "Student with Roll Number " << rollNumber << " not found.\n";
            return;
        }
        students.erase(students.begin() + index);
        cout << "Student record deleted successfully!\n";
    }
};
int main() {
    StudentManager sm;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "    STUDENT RECORD MANAGEMENT SYSTEM     \n";
        cout << "=========================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                sm.addStudent();
                break;
            case 2:
                sm.displayAllStudents();
                break;
            case 3:
                sm.searchStudent();
                break;
            case 4:
                sm.updateStudent();
                break;
            case 5:
                sm.deleteStudent();
                break;
            case 6:
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
