#include <iostream>
#include <vector>
int main() {
    std::vector<int> arr = {10, 20, 35, 50, 75, 80};
    int targetSum = 95;
    bool found = false;
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == targetSum) {
                std::cout << "Pair found: " << arr[i] << " and " << arr[j] << std::endl;
                found = true;
                break;
            }
        }
        if (found) break; 
    }
if (!found) {
        std::cout << "No pair found with the given sum." << std::endl;
    }
return 0;
}
