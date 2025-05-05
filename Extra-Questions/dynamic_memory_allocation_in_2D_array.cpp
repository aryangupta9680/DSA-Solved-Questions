#include <iostream>
using namespace std;

int main()
{
    // array create karna hai jo store karega address ko
    int n, m;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter columns: ";
    cin >> m;

    int **ptr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        ptr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ptr[i][j];
        }
    }


    // print the value 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    // release the memory heap mein
    for(int i = 0;i<n;i++)
    {
        delete[] ptr[i];
    }

    delete[] ptr;


    return 0;
}