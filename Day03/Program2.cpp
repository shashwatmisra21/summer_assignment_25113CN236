#include <iostream>
using namespace std;

int main ()
{
    int start, end;
    cout << "Enter the range (start and end): ";
    cin >> start >> end;
    for (int n = start; n <= end; n++) 
    {
        if (n <= 1) continue; 

        bool isprime = true;
        for (int i = 2; i <= n - 1; i++)
        {
            if (n % i == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime == true)
        {
            cout << n << " ";
        }
    }
    cout << endl;
    return 0;
}
