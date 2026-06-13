#include <iostream>
int main() {
    int n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    int arr[n]; 
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << "Your array is: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
return 0;
}
