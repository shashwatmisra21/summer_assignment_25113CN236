#include <iostream>
#include <cmath>
bool isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int numDigits = 0;
    int sum = 0;
    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }
    temp = num; 
    while (temp > 0) {
        int digit = temp % 10;             
        sum += std::pow(digit, numDigits);  
        temp /= 10;                          
    }
    return sum == originalNum;
}
int main() {
    int number;
    std::cout << "Enter any positive number: ";
    std::cin >> number;
if (isArmstrong(number)) {
        std::cout << number << " is an Armstrong number." << std::endl;
    } else {
        std::cout << number << " is NOT an Armstrong number." << std::endl;
    }
return 0;
}
