#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int matrixA[100][100];
    int matrixB[100][100];
    int sumMatrix[100][100];
    cout << "\nEnter elements for Matrix A:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }
    cout << "\nEnter elements for Matrix B:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    cout << "\nResultant Sum Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << sumMatrix[i][j] << "\t";
        }
        cout << endl; 
    }
return 0;
}
