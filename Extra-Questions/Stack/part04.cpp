#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S;
    S.push(4);
    S.push(58);
    S.push(34);

    S.pop();

    cout << S.size() << endl;

    // top
    cout << S.top() << endl;

    // empty
    cout << S.empty() << endl;

    return 0;
}