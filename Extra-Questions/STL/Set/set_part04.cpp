// unordered set

#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
// #include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // unordered set
    // it contains only unique elemets
    // search, insert and delete have average constant time complexity -> O(1)
    // it uses hashing technique to achieve it

    // unordered_set<int> s;

    // agar duplicate values include karani hai to use karenge
    unordered_multiset<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(15);
    s.insert(11);
    s.insert(10);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}

// set, multiset, unordered_set, unordered_multiset
// set -> unique elements and sorted form
// multiset -> duplicate values present and sorted form
// unordered_set -> unique elements present and not in sorted form
// unordered_multiset -> duplicate values present and not in sorted form
