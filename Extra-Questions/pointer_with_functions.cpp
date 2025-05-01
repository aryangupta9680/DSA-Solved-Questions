#include <iostream>
#include <vector>
using namespace std;

// 1. pass by value
// void swapping(int p1, int p2)
// {
//     int temp = p1;
//     p1 = p2;
//     p2 = temp;
//     cout << &p1 << endl;
//     cout << &p2 << endl;
//     cout << p1 << " " << p2 << endl;
// }

// int main()
// {
//     int first = 10, second = 20;
//     cout << &first << endl;
//     cout << &second << endl;
//     swapping(first, second);
//     cout << first << " " << second << endl;

//     return 0;
// }

// 2. pass by Pointer
// void swapping(int *p1, int *p2)
// {
//     int temp = *p1;
//     *p1 = *p2;
//     *p2 = temp;
//     cout << p1 << endl;
//     cout << p2 << endl;
//     cout << &p1 << endl;
//     cout << &p2 << endl;
// }

// int main()
// {
//     int first = 10, second = 20;
//     cout << &first << endl;
//     cout << &second << endl;
//     swapping(&first, &second);
//     cout << first << " " << second << endl;

//     return 0;
// }

// 3. pass by Reference
// void swapping(int &p1, int &p2)
// {
//     int temp = p1;
//     p1 = p2;
//     p2 = temp;
// }

// int main()
// {
//     // int num = 10;
//     // int &temp = num; // num and temp are same
//     // cout << temp << endl;
//     // temp++;
//     // cout << num << endl;
//     // cout << &num << endl;
//     // cout << &temp << endl;

//     int first = 10, second = 20;
//     swapping(first, second);
//     cout << first << " " << second << endl;

//     return 0;
// }

// 4. Pass by reference for vector
// void pass(vector<int>&temp)
// {
//     for(int i = 0; i < 5; i++)
//     {
//         temp[i] = 20;
//     }
// }

// int main(){
//     vector<int>v(5,0);
//     pass(v);
//     for(int i = 0; i < 5; i++)
//     {
//         cout << v[i] << endl;
//     }
//     return 0;
// }



// 5. Pass by reference for array
// void dob(int p[])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         p[i] = p[i] * 2;
//     }
// }

void dob(int *p)
{
    for (int i = 0; i < 5; i++)
    {
        p[i] = p[i] * 2;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    dob(arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}



// Note: for vector, string then solve with help of pass by reference
// Note: for int arr[], int char[] then solve with help of pointer
