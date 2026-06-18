#include <iostream>
int main() {
    int arr[] = {25, 64, 12, 90, 22};
    int n = 5; 
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j; 
            }
        }
        if (max_index != i) {
            int temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
    std::cout << "Sorted array (Descending): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
return 0;
}
