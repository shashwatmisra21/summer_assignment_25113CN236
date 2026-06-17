#include <iostream>
#include <vector>
#include <set>
int main() {
    std::vector<int> arr1 = {1, 3, 2, 5, 4};
    std::vector<int> arr2 = {4, 3, 6, 7, 2};
    std::set<int> unionSet;

    for (int num : arr1) unionSet.insert(num);
    for (int num : arr2) unionSet.insert(num);

    std::cout << "Union of arrays: ";
    for (int num : unionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
return 0;
}