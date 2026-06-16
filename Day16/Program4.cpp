#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 1};
    std::set<int> uniqueElements(arr.begin(), arr.end());
    arr.assign(uniqueElements.begin(), uniqueElements.end());
    std::cout << "Array after removing duplicates: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
 return 0;
}
