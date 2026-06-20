#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    int mat[N][N] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    bool isSymmetric = true;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) { 
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = false;
                break;
            }
        }
    }

    if (isSymmetric)
        cout << "The matrix is symmetric.\n";
    else
        cout << "The matrix is not symmetric.\n";

    return 0;
}
