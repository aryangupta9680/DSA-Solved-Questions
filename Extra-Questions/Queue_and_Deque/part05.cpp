// print all elements without removing from queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(4);
    q.push(38);
    q.push(96);
    q.push(12);
    q.push(23);

    int n = q.size();
    while (n--)
    {
        cout << q.front() << endl;
        q.push(q.front());
        q.pop();
    }

    cout << "Size: " << q.size() << endl;

    return 0;
}