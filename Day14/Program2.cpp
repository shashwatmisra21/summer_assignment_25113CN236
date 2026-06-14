#include <iostream>
int main() {
    int arr[] = {10, 20, 30, 20, 40, 20, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20; 
    int count = 0;   
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    std::cout << "The element " << target << " appears " << count << " times." << std::endl;
return 0;
}
