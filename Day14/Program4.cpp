#include <iostream>
int main() {
    int arr[] = {2, 4, 6, 4, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Duplicate elements: ";
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                std::cout << arr[i] << " ";
                break; 
            }
        }
    }
return 0;
}
