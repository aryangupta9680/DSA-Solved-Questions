#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // How to create a Queue
    queue<int> q;

    // push
    q.push(38);
    q.push(59);
    q.push(97);
    q.push(21);

    // pop
    q.pop();
    q.pop();

    // front element
    cout << q.front() << endl;

    // back element
    cout << q.back() << endl;

    // size
    cout << q.size() << endl;

    // empty
    cout << q.empty() << endl;

    return 0;
}