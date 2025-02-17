#include <iostream>
using namespace std;

int main()
{
    int n, current, last = 0, prev = 1;
    cout << "Enter number: ";
    cin >> n;
    cout << last << " " << prev << " ";
    for (int i = 3; i <= n; i++)
    {
        current = prev + last;
        last = prev;
        prev = current;
        cout << current << " ";
    }
    return 0;
}