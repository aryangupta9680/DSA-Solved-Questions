#include <iostream>
using namespace std;

int main()
{
    for (int row = 0; row <= 5; row++)
    {
        for (char col = 'F'; col <= 'K'; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}