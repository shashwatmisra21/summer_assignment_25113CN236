#include <iostream>
using namespace std;
int main() {
    const int ROWS = 3, COLS = 4;
    int mat[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    for (int j = 0; j < COLS; ++j) {
        int colSum = 0;
        for (int i = 0; i < ROWS; ++i) {
            colSum += mat[i][j];
        }
        cout << "Sum of column " << j + 1 << " = " << colSum << "\n";
    }

    return 0;
}
