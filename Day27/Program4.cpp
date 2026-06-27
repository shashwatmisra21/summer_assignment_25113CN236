#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Marksheet {
    int rollNumber;
    string studentName;
    int marks[5]; 
    int totalMarks;
    double percentage;
    string grade;
    bool isPassed;
};
class MarksheetSystem {
private:
    vector<Marksheet> records;
    const string subjectNames[5] = {"Physics", "Chemistry", "Mathematics", "English", "Computer Sci"};
    int findRecordIndex(int rollNo) {
        for (size_t i = 0; i < records.size(); ++i) {
            if (records[i].rollNumber == rollNo) {
                return i;
            }
        }
        return -1;
    }
    void calculateResults(Marksheet& student) {
        student.totalMarks = 0;
        student.isPassed = true;

        for (int i = 0; i < 5; ++i) {
            student.totalMarks += student.marks[i];
            if (student.marks[i] < 33) {
                student.isPassed = false;
            }
        }

        student.percentage = student.totalMarks / 5.0;
        if (!student.isPassed) {
            student.grade = "F (Fail)";
        } else if (student.percentage >= 90) {
            student.grade = "A+";
        } else if (student.percentage >= 80) {
            student.grade = "A";
        } else if (student.percentage >= 70) {
            student.grade = "B";
        } else if (student.percentage >= 60) {
            student.grade = "C";
        } else if (student.percentage >= 50) {
            student.grade = "D";
        } else {
            student.grade = "E";
        }
    }

public:
    void addMarksheet() {
        Marksheet student;
        cout << "\n--- Enter Student Marks ---\n";
        cout << "Enter Roll Number: ";
        cin >> student.rollNumber;

        if (findRecordIndex(student.rollNumber) != -1) {
            cout << "Error: Marksheet for Roll Number " << student.rollNumber << " already exists!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Student Full Name: ";
        getline(cin, student.studentName);

        cout << "\nEnter marks out of 100:\n";
        for (int i = 0; i < 5; ++i) {
            do {
                cout << subjectNames[i] << ": ";
                cin >> student.marks[i];
                if (student.marks[i] < 0 || student.marks[i] > 100) {
                    cout << "Invalid marks! Please enter a value between 0 and 100.\n";
                }
            } while (student.marks[i] < 0 || student.marks[i] > 100);
        }

        calculateResults(student);
        records.push_back(student);
        cout << "\nMarksheet data recorded successfully!\n";
    }
    void displaySummaryLedger() {
        if (records.empty()) {
            cout << "\nNo academic records available.\n";
            return;
        }

        cout << "\n---------------------------------------------------------------------------------\n";
        cout << left << setw(10) << "Roll No" 
             << setw(22) << "Name" 
             << setw(12) << "Total (/500)" 
             << setw(12) << "Percentage" 
             << setw(10) << "Grade" 
             << setw(10) << "Result" << endl;
        cout << "---------------------------------------------------------------------------------\n";

        for (const auto& student : records) {
            cout << left << setw(10) << student.rollNumber 
                 << setw(22) << student.studentName 
                 << setw(12) << student.totalMarks 
                 << fixed << setprecision(2) << setw(1) << student.percentage << "%         " 
                 << setw(10) << student.grade 
                 << setw(10) << (student.isPassed ? "PASS" : "FAIL") << endl;
        }
        cout << "---------------------------------------------------------------------------------\n";
    }
    void generateReportCard() {
        if (records.empty()) {
            cout << "\nNo records available to generate report card.\n";
            return;
        }

        int rollNo;
        cout << "\nEnter Student Roll Number: ";
        cin >> rollNo;

        int idx = findRecordIndex(rollNo);
        if (idx == -1) {
            cout << "No student profile matched with Roll Number " << rollNo << ".\n";
            return;
        }

        const auto& student = records[idx];
        cout << "\n====================================================\n";
        cout << "                    REPORT CARD                 \n";
        cout << "====================================================\n";
        cout << " Roll Number   : " << student.rollNumber << endl;
        cout << " Student Name  : " << student.studentName << endl;
        cout << "----------------------------------------------------\n";
        cout << left << setw(25) << " Subject Name" << setw(15) << "Max Marks" << setw(15) << "Obtained" << endl;
        cout << "----------------------------------------------------\n";
        
        for (int i = 0; i < 5; ++i) {
            cout << " " << left << setw(24) << subjectNames[i] 
                 << setw(15) << "100" 
                 << setw(15) << student.marks[i] << endl;
        }
        
        cout << "----------------------------------------------------\n";
        cout << " GRAND TOTAL        : " << student.totalMarks << " / 500" << endl;
        cout << " AGGREGATE PERC.    : " << fixed << setprecision(2) << student.percentage << "%" << endl;
        cout << " FINAL LETTER GRADE : " << student.grade << endl;
        cout << " ACADEMIC STATUS    : " << (student.isPassed ? "PASSED" : "FAILED (Essential Repeat)") << endl;
        cout << "====================================================\n";
    }
    void deleteMarksheet() {
        if (records.empty()) {
            cout << "\nNo records available to delete.\n";
            return;
        }

        int rollNo;
        cout << "\nEnter Roll Number to delete: ";
        cin >> rollNo;

        int idx = findRecordIndex(rollNo);
        if (idx == -1) {
            cout << "No matching records found for deletion.\n";
            return;
        }

        records.erase(records.begin() + idx);
        cout << "Academic entry deleted from systemic database.\n";
    }
};
int main() {
    MarksheetSystem ms;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "       MARKSHEET GENERATION SYSTEM       \n";
        cout << "=========================================\n";
        cout << "1. Add Student Marks\n";
        cout << "2. View All Student Summaries\n";
        cout << "3. Print Detailed Student Report Card\n";
        cout << "4. Delete Student Marksheet Entry\n";
        cout << "5. Close System Application\n";
        cout << "-----------------------------------------\n";
        cout << "Select menu index operation (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: ms.addMarksheet(); break;
            case 2: ms.displaySummaryLedger(); break;
            case 3: ms.generateReportCard(); break;
            case 4: ms.deleteMarksheet(); break;
            case 5: cout << "\nSystem terminated successfully. Have a great day!\n"; break;
            default: cout << "\nInvalid choice identifier! Choose standard range (1-5).\n";
        }
    } while (choice != 5);

    return 0;
}
