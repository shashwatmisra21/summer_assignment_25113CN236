#include <iostream>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    double sum = 0;
    for (int num : arr) sum += num;
    double avg = sum / 5;

    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Average = " << avg << std::endl;

    return 0;
}
