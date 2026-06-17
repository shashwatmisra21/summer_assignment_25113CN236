#include <iostream>
#include <vector>
#include <unordered_set>
int main() {
    std::vector<int> arr1 = {10, 20, 30, 40, 50, 30}; 
    std::vector<int> arr2 = {30, 60, 40, 70, 80, 30};
    std::unordered_set<int> elementsOfArr1(arr1.begin(), arr1.end());
    std::unordered_set<int> commonElements;
    for (int num : arr2) {
        if (elementsOfArr1.count(num)) {
            commonElements.insert(num);
        }
    }
    std::cout << "Common elements: ";
    for (int num : commonElements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
return 0;
}