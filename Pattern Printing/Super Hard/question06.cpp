#include <iostream>
using namespace std;

int main()
{
    int row, col, n;
    cout << "Enter number: ";
    cin >> n;
    for (row = 1; row <= n; row++)
    {
        for (col = 1; col <= (n - row); col = col + 1)
        {
            cout << " ";
        }

        for (col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // lower part
    for (row = n; row >= 1; row--)
    {
        for (col = 1; col <= (n - row); col = col + 1)
        {
            cout << " ";
        }

        for (col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    return 0;
}