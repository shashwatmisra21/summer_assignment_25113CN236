#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::vector<int> arr1 = {1, 3, 2, 5, 4, 2}; 
    std::vector<int> arr2 = {4, 3, 6, 7, 2, 2};
    std::unordered_set<int> set1(arr1.begin(), arr1.end());
    std::unordered_set<int> intersectionSet;
    for (int num : arr2) {
        if (set1.count(num)) {
            intersectionSet.insert(num);
        }
    }
    std::cout << "Intersection of arrays: ";
    for (int num : intersectionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
return 0;
}