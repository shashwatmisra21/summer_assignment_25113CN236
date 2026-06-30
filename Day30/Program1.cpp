#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 50;
void displayMenu();
void addStudent(int ids[], string names[], double marks[], int &count);
void displayAllStudents(const int ids[], const string names[], const double marks[], int count);
void searchStudent(const int ids[], const string names[], const double marks[], int count);
void calculateAverage(const double marks[], int count);

int main() {
    int studentIds[MAX_STUDENTS];
    string studentNames[MAX_STUDENTS];
    double studentMarks[MAX_STUDENTS];
    
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudent(studentIds, studentNames, studentMarks, studentCount);
                break;
            case 2:
                displayAllStudents(studentIds, studentNames, studentMarks, studentCount);
                break;
            case 3:
                searchStudent(studentIds, studentNames, studentMarks, studentCount);
                break;
            case 4:
                calculateAverage(studentMarks, studentCount);
                break;
            case 5:
                cout << "\nExiting Student Record System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please pick a valid option from the menu.\n";
        }
    } while (choice != 5);

    return 0;
}
void displayMenu() {
    cout << "\n====================================\n";
    cout << "       STUDENT RECORD SYSTEM        \n";
    cout << "====================================\n";
    cout << "1. Add New Student Record\n";
    cout << "2. Display All Student Records\n";
    cout << "3. Search Student by Roll No / ID\n";
    cout << "4. Calculate Class Average Mark\n";
    cout << "5. Exit System\n";
    cout << "====================================\n";
}
void addStudent(int ids[], string names[], double marks[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "\nError: Student capacity registry is full!\n";
        return;
    }

    int tempId;
    cout << "Enter Student Roll No / ID (Integer): ";
    cin >> tempId;
    cin.ignore();
    for (int i = 0; i < count; i++) {
        if (ids[i] == tempId) {
            cout << "\nError: Student with Roll No / ID " << tempId << " already exists!\n";
            return;
        }
    }
    ids[count] = tempId;

    cout << "Enter Student Full Name: ";
    getline(cin, names[count]);

    cout << "Enter Student Final Mark / Grade: ";
    cin >> marks[count];
    while (marks[count] < 0 || marks[count] > 100) {
        cout << "Invalid score input! Enter values strictly between 0 and 100: ";
        cin >> marks[count];
    }

    count++; 
    cout << "\nSuccess: Student record added successfully!\n";
}
void displayAllStudents(const int ids[], const string names[], const double marks[], int count) {
    if (count == 0) {
        cout << "\nDatabase error: No student profiles exist yet.\n";
        return;
    }

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(15) << "Roll No / ID" 
         << setw(30) << "Student Name" 
         << "Marks Obtained\n";
    cout << "-------------------------------------------------------------\n";
    
    cout << fixed << setprecision(2);

    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << ids[i] 
             << setw(30) << names[i] 
             << marks[i] << "\n";
    }
    cout << "-------------------------------------------------------------\n";
    cout << "Total Active Enrolments: " << count << "\n";
}
void searchStudent(const int ids[], const string names[], const double marks[], int count) {
    if (count == 0) {
        cout << "\nDatabase is empty. Nothing to search.\n";
        return;
    }

    int targetId;
    cout << "Enter Roll No / ID to search: ";
    cin >> targetId;

    for (int i = 0; i < count; i++) {
        if (ids[i] == targetId) {
            cout << "\n=== Profile Match Located ===\n";
            cout << "Roll No / ID : " << ids[i] << "\n";
            cout << "Full Name    : " << names[i] << "\n";
            cout << fixed << setprecision(2) << "Final Marks  : " << marks[i] << "\n";
            return; 
        }
    }
    cout << "\nError: Student with Roll No / ID " << targetId << " not found.\n";
}
void calculateAverage(const double marks[], int count) {
    if (count == 0) {
        cout << "\nNo scores available to calculate metrics.\n";
        return;
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }

    double average = sum / count;
    cout << fixed << setprecision(2);
    cout << "\n=== Class Performance Metrics ===\n";
    cout << "Sum of Marks  : " << sum << "\n";
    cout << "Class Average : " << average << "\n";
}
