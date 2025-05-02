#include <iostream>
using namespace std;

// modified value
// void fun(int *p)
// {
//     *p = *p + 15;
// }

// change address
void fun(int **p1)
{
    *p1 = *p1 + 1;
}

int main()
{
    int n = 10;
    int *p = &n;     // single pointer
    int **p2 = &p;   // double pointer
    int ***p3 = &p2; // triple pointer
    // cout << p << endl;
    // cout << &p << endl;
    // cout << p2 << endl;
    // cout << &p2 << endl;
    // cout << p3 << endl;

    // value ko modified karna ho, jo n mein rakhi hai
    // *p = *p + 5;
    // cout << n << endl;

    // **p2 = **p2 + 8;
    // cout << n << endl;

    // ***p3 = ***p3 + 9;
    // cout << n << endl;

    // fun(p);
    // cout << n << endl;
    // cout << *p << endl;

    // Change address
    cout << p << endl;
    fun(p2);
    cout << p << endl;

    return 0;
}