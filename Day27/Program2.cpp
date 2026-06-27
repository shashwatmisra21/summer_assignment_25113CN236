#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Employee {
    int id;
    string name;
    string department;
    string designation;
    double salary;
};
class EmployeeManager {
private:
    vector<Employee> employees;
    int findEmployeeIndex(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].id == id) {
                return i; 
            }
        }
        return -1; 
    }

public:
    void addEmployee() {
        Employee emp;
        cout << "\n--- Add New Employee Record ---\n";
        cout << "Enter Employee ID: ";
        cin >> emp.id;
        if (findEmployeeIndex(emp.id) != -1) {
            cout << "Error: Employee ID " << emp.id << " already exists!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin, emp.name);
        cout << "Enter Department: ";
        getline(cin, emp.department);
        cout << "Enter Designation: ";
        getline(cin, emp.designation);
        cout << "Enter Monthly Salary: ";
        cin >> emp.salary;

        employees.push_back(emp);
        cout << "Employee record added successfully!\n";
    }
    void displayAllEmployees() {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        cout << "\n----------------------------------------------------------------------------------------\n";
        cout << left << setw(8)  << "ID" 
             << setw(22) << "Name" 
             << setw(18) << "Department" 
             << setw(20) << "Designation" 
             << setw(12) << "Salary" << endl;
        cout << "----------------------------------------------------------------------------------------\n";

        for (const auto& emp : employees) {
            cout << left << setw(8)  << emp.id 
                 << setw(22) << emp.name 
                 << setw(18) << emp.department 
                 << setw(20) << emp.designation 
                 << fixed << setprecision(2) << setw(12) << emp.salary << endl;
        }
        cout << "----------------------------------------------------------------------------------------\n";
    }
    void searchEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to search.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to search: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index == -1) {
            cout << "Employee with ID " << id << " not found.\n";
            return;
        }

        cout << "\n--- Employee Record Found ---\n";
        cout << "ID          : " << employees[index].id << endl;
        cout << "Name        : " << employees[index].name << endl;
        cout << "Department  : " << employees[index].department << endl;
        cout << "Designation : " << employees[index].designation << endl;
        cout << "Salary      : ₹" << fixed << setprecision(2) << employees[index].salary << endl;
    }
    void updateEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to update.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to update: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index == -1) {
            cout << "Employee with ID " << id << " not found.\n";
            return;
        }

        cout << "\n--- Current Record Details ---\n";
        cout << "Name: " << employees[index].name << " | Dept: " << employees[index].department << " | Salary: " << employees[index].salary << endl;

        cout << "\n--- Enter New Details ---\n";
        cin.ignore();
        cout << "Enter New Name: ";
        getline(cin, employees[index].name);
        cout << "Enter New Department: ";
        getline(cin, employees[index].department);
        cout << "Enter New Designation: ";
        getline(cin, employees[index].designation);
        cout << "Enter New Salary: ";
        cin >> employees[index].salary;

        cout << "Employee record updated successfully!\n";
    }
    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to delete.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to delete: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index == -1) {
            cout << "Employee with ID " << id << " not found.\n";
            return;
        }
        employees.erase(employees.begin() + index);
        cout << "Employee record deleted successfully!\n";
    }
};
int main() {
    EmployeeManager em;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "       EMPLOYEE MANAGEMENT SYSTEM        \n";
        cout << "=========================================\n";
        cout << "1. Add Employee Record\n";
        cout << "2. Display All Employee Records\n";
        cout << "3. Search Employee Record\n";
        cout << "4. Update Employee Record\n";
        cout << "5. Delete Employee Record\n";
        cout << "6. Exit System\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                em.addEmployee();
                break;
            case 2:
                em.displayAllEmployees();
                break;
            case 3:
                em.searchEmployee();
                break;
            case 4:
                em.updateEmployee();
                break;
            case 5:
                em.deleteEmployee();
                break;
            case 6:
                cout << "\nExiting system. Have a great day ahead!\n";
                break;
            default:
                cout << "\nInvalid input choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
