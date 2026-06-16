#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    std::vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 3, 3, 2};
    std::unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        frequencyMap[num]++;
    }
 int maxElement = arr[0];
    int maxCount = 0;
    for (auto pair : frequencyMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxElement = pair.first;
        }
    }
std::cout << "The element with the maximum frequency is: " << maxElement << std::endl;
    std::cout << "It appears " << maxCount << " times." << std::endl;

    return 0;
}
