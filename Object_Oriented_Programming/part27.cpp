#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr(5);
    cout << "Enter the input: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // file ko open karo
    ofstream fout;
    fout.open("zero.txt");

    fout << "Original data" << endl;
    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    fout << "\nSorted data\n";
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    fout.close();
    return 0;
}