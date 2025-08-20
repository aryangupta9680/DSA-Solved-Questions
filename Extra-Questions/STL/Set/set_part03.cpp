// multiset

#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

// Duplicate elements will be present
// sorted order
// implementation -> red-black tree or AVL Tree

int main()
{
    // multiset -> set mein duplicate bhi present ho sakta hai lekin wo sab sorted form mein hoge

    multiset<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);

    s.erase(10); // dono duplicate values delete ho jayegi

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}