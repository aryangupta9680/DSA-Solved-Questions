#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(50);
    l.push_back(70);
    l.push_front(15);
    // l.pop_back();
    // l.pop_front();

    // cout << l.front() << " " << l.back() << endl;
    // cout << l.size() << endl;

    // iterator
    // 15 20 30 50 70
    // for (auto it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // for reverse list
    for (auto it = l.rbegin(); it != l.rend(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}