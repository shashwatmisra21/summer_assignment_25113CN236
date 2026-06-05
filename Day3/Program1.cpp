# include <iostream>
using namespace std;
int main ()
{
    int n;
    bool isprime = true;
    cout <<"Enter a positive integer : ";
    cin >> n;
    for (int i=2; i<=n-1; i++)
    {
        if (n % i == 0)
        {
            isprime = false;
            break;
        }
    }
    if (isprime == true)
    {
        cout <<"It is a prime number." << endl;
    } else {
        cout <<"It is not a prime number." << endl;
    }
    return 0;
}