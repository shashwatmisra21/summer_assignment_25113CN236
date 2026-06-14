#include <iostream>
int main() {
    int arr[] = {10, 50, 30, 70, 40, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 70; 
    int index = 3; 
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i; 
            break;    
        }
    }
    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
return 0;
}
