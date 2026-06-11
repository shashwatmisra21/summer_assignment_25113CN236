#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    long long num;
    cout << "Enter an integer: ";
    cin >> num;

    long long temp = abs(num); 
    int count = 0;

    if (temp == 0) {
        count = 1;
    } else {
        while (temp > 0) {
            temp = temp / 10; 
            count++;         
        }
    }

    cout << "Total number of digits: " << count << endl;
    return 0;
}
