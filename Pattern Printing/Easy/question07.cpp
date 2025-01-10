#include <iostream>
using namespace std;

int main()
{
    for (int row = 1; row <= 5; row++)
    {
        char name = 'a' + (row - 1);
        for (int col = 0; col < 5; col++)
        {
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}