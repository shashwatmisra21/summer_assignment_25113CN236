#include <iostream>
int main() {
    int arr[] = {15, 75, 7, 21, 17, 67};
    int evenCount = 0;
    int oddCount = 0;
 for (int num : arr) {
        if (num % 2 == 0) evenCount++; 
        else oddCount++;               
    }

    std::cout << "Even numbers: " << evenCount << std::endl;
    std::cout << "Odd numbers: " << oddCount << std::endl;
return 0;
}
