#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (n < 2)
    {
        cout << n << " is not a Prime Number";
        return 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                cout << n << " is not a Prime Number";
                return 0;
            }
        }

        cout << n << " is a Prime Number";
        return 0;
    }

    return 0;
}