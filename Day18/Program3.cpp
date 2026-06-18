#include <iostream>

int main() {
   
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = 7;           
    int target = 25;    
    int low = 0;
    int high = n - 1;
    int result_index = -1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result_index = mid; 
            break;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    if (result_index != -1) {
        std::cout << "Element " << target << " found at index " << result_index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
