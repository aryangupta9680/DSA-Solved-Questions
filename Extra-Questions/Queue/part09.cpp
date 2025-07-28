#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(5);
    d.push_front(10);
    d.push_front(20);
    d.pop_back();
    cout << d.front() << endl;
    cout << d.back() << endl;

    return 0;
}