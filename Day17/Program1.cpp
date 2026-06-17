#include <iostream>
#include <vector>
int main() {
    std::vector<int> arr1 = {1, 3, 5};
    std::vector<int> arr2 = {2, 4, 6};

    std::vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());

    merged.insert(merged.end(), arr1.begin(), arr1.end());

    merged.insert(merged.end(), arr2.begin(), arr2.end());
    std::cout << "Merged Array: ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
return 0;
}