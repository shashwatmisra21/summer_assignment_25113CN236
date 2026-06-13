#include <iostream>

int main() {
    int arr[] = {28, 12, 5, 32, 18}; 
    int smallest = arr[0];          
    int largest = arr[0];          
for (int num : arr) {
        if (num < smallest) smallest = num; 
        if (num > largest)  largest = num;  
    }

    std::cout << "Smallest: " << smallest << std::endl;
    std::cout << "Largest: " << largest << std::endl;
 return 0;
}
