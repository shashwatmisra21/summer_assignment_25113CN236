#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct SalaryRecord {
    int empId;
    string name;
    double baseSalary;
    double dearnessAllowance;  
    double houseRentAllowance; 
    double providentFund;      
    double netSalary;          
};
class SalaryManager {
private:
    vector<SalaryRecord> payrollDb;
    const double DA_PERCENT = 0.40;  
    const double HRA_PERCENT = 0.15; 
    const double PF_PERCENT = 0.12;  
    int locateRecordIndex(int id) {
        for (size_t i = 0; i < payrollDb.size(); ++i) {
            if (payrollDb[i].empId == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void generateSalarySlip() {
        SalaryRecord record;
        cout << "\n--- Generate New Employee Payroll Slip ---\n";
        cout << "Enter Employee ID: ";
        cin >> record.empId;

        if (locateRecordIndex(record.empId) != -1) {
            cout << "Error: Salary details for Employee ID " << record.empId << " already calculated!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Employee Full Name: ";
        getline(cin, record.name);
        cout << "Enter Monthly Base Salary: ₹";
        cin >> record.baseSalary;
        record.dearnessAllowance = record.baseSalary * DA_PERCENT;
        record.houseRentAllowance = record.baseSalary * HRA_PERCENT;
        record.providentFund = record.baseSalary * PF_PERCENT;
        record.netSalary = (record.baseSalary + record.dearnessAllowance + record.houseRentAllowance) - record.providentFund;

        payrollDb.push_back(record);
        cout << "Payroll slip processed successfully for " << record.name << "!\n";
    }
    void displayPayrollLedger() {
        if (payrollDb.empty()) {
            cout << "\nNo processed payroll items found in ledger.\n";
            return;
        }

        cout << "\n---------------------------------------------------------------------------------------------\n";
        cout << left << setw(8)  << "ID" 
             << setw(20) << "Name" 
             << setw(13) << "Base Pay" 
             << setw(10) << "DA" 
             << setw(10) << "HRA" 
             << setw(10) << "PF(-)" 
             << setw(14) << "Net Payout" << endl;
        cout << "---------------------------------------------------------------------------------------------\n";

        for (const auto& rec : payrollDb) {
            cout << left << setw(8)  << rec.empId 
                 << setw(20) << rec.name 
                 << fixed << setprecision(2)
                 << "₹" << setw(12) << rec.baseSalary 
                 << "₹" << setw(9)  << rec.dearnessAllowance 
                 << "₹" << setw(9)  << rec.houseRentAllowance 
                 << "₹" << setw(9)  << rec.providentFund 
                 << "₹" << setw(13) << rec.netSalary << endl;
        }
        cout << "---------------------------------------------------------------------------------------------\n";
    }
    void printDetailedPaySlip() {
        if (payrollDb.empty()) {
            cout << "\nNo payroll records available.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to fetch Pay Slip: ";
        cin >> id;

        int idx = locateRecordIndex(id);
        if (idx == -1) {
            cout << "No ledger slip found under Employee ID " << id << ".\n";
            return;
        }

        const auto& rec = payrollDb[idx];
        cout << "\n=============================================\n";
        cout << "              OFFICIAL PAY SLIP              \n";
        cout << "=============================================\n";
        cout << " Employee ID   : " << rec.empId << endl;
        cout << " Full Name     : " << rec.name << endl;
        cout << "---------------------------------------------\n";
        cout << " (+) Base Salary       : ₹" << fixed << setprecision(2) << rec.baseSalary << endl;
        cout << " (+) Dearness Allow.   : ₹" << rec.dearnessAllowance << endl;
        cout << " (+) House Rent Allow. : ₹" << rec.houseRentAllowance << endl;
        cout << "---------------------------------------------\n";
        cout << " (-) Provident Fund    : ₹" << rec.providentFund << endl;
        cout << "=============================================\n";
        cout << " TOTAL NET PAYOUT      : ₹" << rec.netSalary << endl;
        cout << "=============================================\n";
    }
    void modifyBasePay() {
        if (payrollDb.empty()) {
            cout << "\nLedger ledger holds zero active items.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to adjust salary: ";
        cin >> id;

        int idx = locateRecordIndex(id);
        if (idx == -1) {
            cout << "Employee record match not found.\n";
            return;
        }

        cout << "\nCurrent Base Pay scale is: ₹" << payrollDb[idx].baseSalary << endl;
        cout << "Enter New Base Salary amount: ₹";
        cin >> payrollDb[idx].baseSalary;
        payrollDb[idx].dearnessAllowance = payrollDb[idx].baseSalary * DA_PERCENT;
        payrollDb[idx].houseRentAllowance = payrollDb[idx].baseSalary * HRA_PERCENT;
        payrollDb[idx].providentFund = payrollDb[idx].baseSalary * PF_PERCENT;
        payrollDb[idx].netSalary = (payrollDb[idx].baseSalary + payrollDb[idx].dearnessAllowance + payrollDb[idx].houseRentAllowance) - payrollDb[idx].providentFund;

        cout << "Salary structural calculations modified successfully!\n";
    }
    void removePayrollSlip() {
        if (payrollDb.empty()) {
            cout << "\nZero records ready for clearance handling.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to wipe payroll info: ";
        cin >> id;

        int idx = locateRecordIndex(id);
        if (idx == -1) {
            cout << "No tracking database found matching that ID value.\n";
            return;
        }

        payrollDb.erase(payrollDb.begin() + idx);
        cout << "Payroll entry cleared successfully from systemic registries.\n";
    }
};
int main() {
    SalaryManager sm;
    int selectedOption;

    do {
        cout << "\n=========================================\n";
        cout << "        SALARY MANAGEMENT SYSTEM         \n";
        cout << "=========================================\n";
        cout << "1. Process New Salary Slip\n";
        cout << "2. View All Employee Payroll Ledgers\n";
        cout << "3. Generate Individual Detailed Pay Slip\n";
        cout << "4. Modify Base Salary Scale Info\n";
        cout << "5. Clear Payroll Slip Entry\n";
        cout << "6. Exit Application\n";
        cout << "-----------------------------------------\n";
        cout << "Provide terminal command select (1-6): ";
        cin >> selectedOption;

        switch (selectedOption) {
            case 1: sm.generateSalarySlip(); break;
            case 2: sm.displayPayrollLedger(); break;
            case 3: sm.printDetailedPaySlip(); break;
            case 4: sm.modifyBasePay(); break;
            case 5: sm.removePayrollSlip(); break;
            case 6: cout << "\nClosing System Matrix Ledger execution thread. Safe out!\n"; break;
            default: cout << "\nInvalid numerical entry selection. Retrying options (1-6).\n";
        }
    } while (selectedOption != 6);

    return 0;
}
