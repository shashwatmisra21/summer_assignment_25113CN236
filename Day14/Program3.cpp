#include <iostream>
int main() {
    int arr[] = {12, 35, 1, 10, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
int largest = arr[0];
    int secondLargest = -1; 
for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
std::cout << "Second largest: " << secondLargest;
    return 0;
}
