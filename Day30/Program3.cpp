#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_EMPLOYEES = 100;
class Employee {
private:
    int id;
    string name;
    string department;
    double salary;

public:
    Employee() {
        id = 0;
        name = "";
        department = "";
        salary = 0.0;
    }
    void setRecord(int empId, string empName, string empDept, double empSalary) {
        id = empId;
        name = empName;
        department = empDept;
        salary = empSalary;
    }
    int getId() const { return id; }
    string getName() const { return name; }
    double getSalary() const { return salary; }
    void updateSalary(double newSalary) {
        salary = newSalary;
    }
    void printRow() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(20) << department 
             << "$" << fixed << setprecision(2) << salary << "\n";
    }
};
void displayMenu();
void registerEmployee(Employee payroll[], int &totalCount);
void printAllRecords(const Employee payroll[], int totalCount);
void searchEmployee(const Employee payroll[], int totalCount);
void processSalaryIncrement(Employee payroll[], int totalCount);

int main() {
    Employee payrollDatabase[MAX_EMPLOYEES];
    int currentEmployeeCount = 0;
    int userChoice;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> userChoice;
        cin.ignore(); 

        switch (userChoice) {
            case 1:
                registerEmployee(payrollDatabase, currentEmployeeCount);
                break;
            case 2:
                printAllRecords(payrollDatabase, currentEmployeeCount);
                break;
            case 3:
                searchEmployee(payrollDatabase, currentEmployeeCount);
                break;
            case 4:
                processSalaryIncrement(payrollDatabase, currentEmployeeCount);
                break;
            case 5:
                cout << "\nTerminating Payroll Management Engine. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid input choice! Please select an operation from 1 to 5.\n";
        }
    } while (userChoice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n====================================\n";
    cout << "     EMPLOYEE MANAGEMENT SYSTEM     \n";
    cout << "====================================\n";
    cout << "1. Add New Employee Record\n";
    cout << "2. View All Employee Directory\n";
    cout << "3. Search Employee by ID\n";
    cout << "4. Modify / Increment Salary\n";
    cout << "5. Exit System\n";
    cout << "====================================\n";
}
void registerEmployee(Employee payroll[], int &totalCount) {
    if (totalCount >= MAX_EMPLOYEES) {
        cout << "\nError: Directory registry limits reached! Cannot insert profile.\n";
        return;
    }

    int checkId;
    string tempName, tempDept;
    double checkSalary;

    cout << "Enter Employee Work ID (Integer): ";
    cin >> checkId;
    cin.ignore();
    for (int i = 0; i < totalCount; i++) {
        if (payroll[i].getId() == checkId) {
            cout << "\nError: Unique ID tag " << checkId << " is already linked to another staff member.\n";
            return;
        }
    }

    cout << "Enter Employee Full Name: ";
    getline(cin, tempName);

    cout << "Enter Department Division: ";
    getline(cin, tempDept);

    cout << "Enter Base Salary ($): ";
    cin >> checkSalary;
    while (checkSalary < 0) {
        cout << "Invalid monetary parameters! Re-enter a positive salary base: ";
        cin >> checkSalary;
    }

    payroll[totalCount].setRecord(checkId, tempName, tempDept, checkSalary);
    totalCount++;
    cout << "\nSuccess: Staff member saved to operational corporate registry.\n";
}
void printAllRecords(const Employee payroll[], int totalCount) {
    if (totalCount == 0) {
        cout << "\nNo employee database records available to pull summaries from.\n";
        return;
    }

    cout << "\n----------------------------------------------------------------------------\n";
    cout << left << setw(10) << "EMP ID" 
         << setw(25) << "Full Name" 
         << setw(20) << "Department" 
         << "Monthly Salary\n";
    cout << "----------------------------------------------------------------------------\n";

    for (int i = 0; i < totalCount; i++) {
        payroll[i].printRow();
    }
    cout << "----------------------------------------------------------------------------\n";
    cout << "Total Active Enterprise Staffing: " << totalCount << "\n";
}
void searchEmployee(const Employee payroll[], int totalCount) {
    if (totalCount == 0) {
        cout << "\nDatabase files are unpopulated. Search request rejected.\n";
        return;
    }

    int searchId;
    cout << "Enter designated Employee ID to pull profile for: ";
    cin >> searchId;

    for (int i = 0; i < totalCount; i++) {
        if (payroll[i].getId() == searchId) {
            cout << "\n=== Enterprise Profile Match Located ===\n";
            cout << "Registration ID  : " << payroll[i].getId() << "\n";
            cout << "Full Staff Name  : " << payroll[i].getName() << "\n";
            cout << "Current Wage Tier: $" << fixed << setprecision(2) << payroll[i].getSalary() << "\n";
            return;
        }
    }
    cout << "\nQuery Error: Staff reference profile matching tag " << searchId << " missing.\n";
}
void processSalaryIncrement(Employee payroll[], int totalCount) {
    if (totalCount == 0) {
        cout << "\nCorporate workspace registry is empty.\n";
        return;
    }

    int targetId;
    cout << "Enter Employee ID to apply salary adjustments on: ";
    cin >> targetId;

    for (int i = 0; i < totalCount; i++) {
        if (payroll[i].getId() == targetId) {
            double raisePercentage;
            cout << "Current Salary profile: $" << fixed << setprecision(2) << payroll[i].getSalary() << "\n";
            cout << "Enter raise percentage reward rate (e.g., enter 10 for 10%): ";
            cin >> raisePercentage;

            if (raisePercentage < -100) {
                cout << "\nInvalid percentage metrics input skipped.\n";
                return;
            }

            double oldSalary = payroll[i].getSalary();
            double revisedSalary = oldSalary + (oldSalary * (raisePercentage / 100.0));
            
            payroll[i].updateSalary(revisedSalary);
            cout << "\nSuccess: Balance updated! New compensation level is: $" << revisedSalary << "\n";
            return;
        }
    }
    cout << "\nModification Failed: Target registration ID match not discovered.\n";
}
