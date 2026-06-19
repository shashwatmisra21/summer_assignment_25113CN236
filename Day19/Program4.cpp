#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the square matrix (Rows/Cols): ";
    cin >> size;
    if (size > 100 || size <= 0) {
        cout << "Error: Size must be between 1 and 100." << endl;
        return 1;
    }
int matrix[100][100];
    int primarySum = 0;
    int secondarySum = 0;
    cout << "\nEnter elements for the Matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < size; ++i) {
        primarySum += matrix[i][i];                 
        secondarySum += matrix[i][size - 1 - i];   
    }
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
cout << "\nSum of Primary Diagonal: " << primarySum << endl;
    cout << "Sum of Secondary Diagonal: " << secondarySum << endl;
return 0;
}
