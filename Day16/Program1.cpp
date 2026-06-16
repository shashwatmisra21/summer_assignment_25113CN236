#include <iostream>
#include <vector>
int main() {
    int n = 5; 
    std::vector<int> arr = {1, 2, 4, 5};
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }
    int missingNumber = expectedSum - actualSum;
std::cout << "The missing no. is: " << missingNumber << std::endl;
return 0;
}
